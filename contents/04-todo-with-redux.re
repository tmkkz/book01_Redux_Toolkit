= 日記アプリケーションの作成(Redux使用)

//abstract{
　本章では、Reactで作成したサンプルアプリケーションが管理しているデータをReduxで管理するように変更します。
@<br>{}
　まずは、Reduxとは何か？から始め、Reduxで使われる定型の書き方を学びます。
//}

=={sec04-01} Reduxとは？
#@# cafeを例にしてAction actioncreator despatch state
Reduxとは状態管理をするためのライブラリのひとつです。状態管理とは、アプリケーションで使用するデータの状態
(初期値への追加・変更・削除)を正しく保持することです。

//blankline
Reactを使用したアプリケーションで状態管理をする方法は複数ありますが、
2022年時点ではデフィアクト・スタンダードと言われるほど使われています。

//blankline
Reactでの状態管理の方法は、
@<href>{https://blog.uhy.ooo/entry/2021-07-24/react-state-management/, こちら}
の記事が参考になります。

//image[stateManageLib1][Reactステート管理比較][scale=0.5]

=== Redux導入のメリット
Reduxを導入するメリットは何があるのでしょうか？

==== データ管理の一元化
一番のメリットは、データ管理の一元化ではないでしょうか？

//blankline
リレーショナル・データベースで言えば、テーブルデータの集合体のStateがあり
画面に必要なデータは、親コンポーネントに頼らず「useSelect」を使えば簡単に取得できます。

//blankline
また、データの追加・更新・削除も親コンポーネントに頼らず「ActionCreator」に
データを渡し作成した「Action」を「dispatch関数」に渡すだけで完了します。

==== バケツリレーからの脱却
サンプルアプリケーションでの「Reactあるあるのバケツリレー」もコンポーネントから
自由にアクセスできるのでデータの取得・変更に関しては脱却できます。

==== メンテナンス性の向上
データを変更する箇所が「Reducer」に集約されるため、メンテナンス性が高くなります。
また、middlewareを組み込むことによりデバッグも簡単になります。

//blankline
devTools-extentionを導入すると、発行されたActionをさかのぼってデータの変化を確認できます。


=={sec04-02} Reduxの動作イメージ
Reduxの動作としては、

 1. アプリケーション起動
 2. 初期値を使用して最初の各Stateが作成されStoreを作る
 3. 表示画面のコンポーネントはStoreの一部Stateをpropsとして参照
 4. イベントが発生しActionCreatorへActionオブジェクトを作成してもらう。
 5. 作成したActionをDispach関数でReducerへ渡す
 6. Reducerは、現在のStateをもとに新しくStateを作成し、ActionオブジェクトによりStateを変更
 7. propsが参照していたStateが変化したため再描画が発生する。

 となります。

//blankline
 例として、Cafeの各テーブルの状態を考えます。

 1. お店オープン。最初はお客がいないためすべてのテーブル上は何もなし。
 2. あるテーブルへお客が入り、ケーキをオーダー。
 3. actioncreatorであるウェイトレスが注文伝票を作成
 4. 注文伝票(Action)が店長により厨房へ運ばれる(dispatch)
 5. 調理担当が注文したお客の現在のテーブル状態を別なテーブルで作成。
 6. 調理担当が作成したテーブルに注文の品をのせ、現在のお客のテーブルと入れ換える

 こんなイメージです。

//image[yaruo-redux][Reduxの動作イメージ][scale=1.0,pos=H]

=={sec04-03} Reduxの導入
それでは、サンプルアプリケーションにReduxを導入します。現在はRedux-toolkitがあるのですが
Reduxの動きを知るために、素のReduxを導入します。

//blankline
Reduxに必要なパッケージは、Redux関連とMiddlewareとデバッグ用です。

 * redux
 * react-redux
 * @redux-devtools/extension
 * redux-logger

TypeScriptを導入しているので型定義も導入します。
これらは「devDependencies」にインストールしますので分けて導入します。

 * @types/react-redex
 * @types/redux-logger

となります。

インストールは、個別に、
//terminal[][reduxのインストール]{
 > npm install redux react-redux @redux-devtools/extension redux-logger
//}

//terminal[][型パッケージのインストール]{
 > npm install -D @types/react-redux　@types/redux-logger
//}
=={sec04-04} Reduxのアプリケーションへの導入
Reduxのインストールが完了しましたので、サンプルアプリケーションへ導入していきます。

//blankline
手順は、

 1. Action Typeを定数として定義
 2. Actioncreatorの作成
 3. Reducerの作成
 4. Reducerを組み合わせる
 5. Storeの作成
 6. トップコンポーネントにStoreを登録

の手順となります。

//blankline
　サンプルアプリケーションでは、管理するデータは、

 * 読書日記データ
 * 編集対象・新規追加のdiaryId

の２つだけでActionも少ないのですが、管理するデータカテゴリ(RDBでのテーブル)が増えると
同じようなファイルをたくさん作成します。

//blankline
この苦行のおかげでReduxの導入はメンドウだと言われましたが、Redux-toolkitの登場で
楽になりました。

//blankline
　このサンプルアプリケーションでは、Redux関連のファイルをひとつにします。
のちほどRedux-toolkitも導入し切り替えますので、ファイルサイズの違いを楽しみに。

//blankline
　それでは、「src/redux/redux-og.ts」ファイルを作成します。

===={sec04-04-1} Action Typeの定数を作成
最初に、Action Typeの定数を作成します。

//blankline
Actionに直接文字列を書き込んでも良いのですが、定数として定義すると、

 * エディタで保管が効く
 * タイポしてもエディタが指摘してくれる

ので、手間以上のメリットがあります。

//list[][アクション定数]{
  // Action定数
  const CREATE_DIARY = 'CREATE_DIARY';
  const EDIT_DIARY = 'EDIT_DIARY';
  const DELETE_DIARY = 'DELETE_DIARY';
  const SELECT_DIARY = 'SELECT_DIARY';
//}

以上で完成です。

===={sec04-04-2} ActionCreatorの作成
次にActionCreatorを作成します。ActionCreatorは、受け取った引数を設定したActionを返すだけのものです。

//list[][ActionCreatorの作成]{
  // Actions & Action Type
  type CreateDiaryActionType = {
    type: typeof CREATE_DIARY;
    payload: Diary;
  };

  export const createDiaryActionCreator = (
    data: Diary
  ): CreateDiaryActionType => ({
    type: CREATE_DIARY,
    payload: data,
  });

  type EditDiaryActionType = {
    type: typeof EDIT_DIARY;
    payload: Diary;
  };

  export const editDiaryActionCreator = (data: Diary): EditDiaryActionType => ({
    type: EDIT_DIARY,
    payload: data,
  });

  type DeleteDiaryActionType = {
    type: typeof DELETE_DIARY;
    payload: { diaryId: string };
  };

  export const deleteDiaryActionCreator = ({
    diaryId,
  }: {
    diaryId: string;
  }): DeleteDiaryActionType => ({
    type: DELETE_DIARY,
    payload: { diaryId },
  });

  type SelectDiaryActionType = {
    type: typeof SELECT_DIARY;
    payload: { diaryId: string };
  };

  export const selectDiaryActionCreator = ({
    diaryId,
  }: {
    diaryId: string;
  }): SelectDiaryActionType => ({
    type: SELECT_DIARY,
    payload: { diaryId },
  });
//}

===={sec04-04-3} Reducerの作成
次にReducerを作成します。Reduxの一番肝心な部分です。

//blankline
Reducerは、ActionとStateを受け取って新しいStateを作成し変更を加えます。
元のStateは変更しないため「不変(英語では、immutable)」と言われます。

//blankline
Reducerは自分の管理するStateに対するActionをすべて受け付け、Actionのtypeで
switch文で処理を分けます。

//blankline
また、Reducerの受け取るStateに初期値を設定することで初期化できます。

//list[][Reducerの作成]{
  import diaries, { Diary } from '../diaryData';

  // Reducers
  type DiaryActionTypes =
    | CreateDiaryActionType
    | EditDiaryActionType
    | DeleteDiaryActionType;

  const diariesInitialState = diaries;

  const diarySort = (a: Diary, b: Diary) => {
    if (+a.postDate < +b.postDate) return -1;
    if (+a.postDate > +b.postDate) return 1;
    return 0;
  };

  const diariesReducer = (
    // eslint-disable-next-line default-param-last
    state: Diary[] = diariesInitialState,
    action: DiaryActionTypes
  ) => {
    switch (action.type) {
      case CREATE_DIARY: {
        const { payload } = action;
        return [...state, payload].sort(diarySort);
      }
      case EDIT_DIARY: {
        const { payload } = action;
        return state
          .map((diary) => (diary.diaryId === payload.diaryId ? payload : diary))
          .sort(diarySort);
      }
      case DELETE_DIARY: {
        const { payload } = action;
        return state
          .filter((diary) => diary.diaryId !== payload.diaryId)
          .sort(diarySort);
      }
      default:
        return state;
    }
  };

  type SelectedDiaryActionTypes = SelectDiaryActionType;
  const selectedDiaryReducer = (
    // eslint-disable-next-line default-param-last
    state: string | null = null,
    action: SelectedDiaryActionTypes
  ) => {
    switch (action.type) {
      case SELECT_DIARY: {
        const { payload } = action;
        const selectedDiaryId =
          payload.diaryId.length > 0 ? payload.diaryId : null;
        return selectedDiaryId;
      }
      default: {
        return state;
      }
    }
  };

//}

===={sec04-04-4} Reducerを組み合わせる
アプリケーション内のすべてのReducerを「combineReducers関数」でまとめます。
「combineReducers関数」はreduxパッケージからインポートします。

//list[][combineReducers]{
  const reducers = combineReducers({
    diaries: diariesReducer,
    targetDiaryId: selectedDiaryReducer,
  });
//}

ここで、「key: value」形式でReducerを登録しますが、Reducerは先ほど作成したもので
keyは、State内の参照名になります。コンポーネントでデータを参照する際には、

//list[][Stateデータの参照方法]{
　const 参照したいデータ = useSelector((state => state.key名));
//}

で行いますので、分かりkey名にします。

===={sec04-04-5} Storeの作成
最後にデータの集合体、Middlewareの集合体のStoreを作成します。

//blankline
Storeを作成するための「createStore関数」もreduxパッケージからインポートします。

//blankline
Middlewareを登録するのは、reduxパッケージの「compose関数」でも良いのですが、
今回登録するのは「logger」で開発時のみの使用を想定していますので、@redux-devTools/extentionの
「composeWithDevTools関数」を使用します。

//blankline
ただ、Middlewareを登録する「applyMiddleware関数」はreduxパッケージからインポートします。
「logger」のインポートも忘れないように。

//blankline
全体に関わるものですが、Storeの型をここへ書いておきます。

//list[][Storeの作成]{
  import { combineReducers, createStore, applyMiddleware } from 'redux';
  import { composeWithDevTools } from '@redux-devtools/extension';
  import logger from 'redux-logger';

  export default createStore(
    reducers,
    composeWithDevTools(applyMiddleware(logger))
  );

  export type State = {
    diaries: Diary[];
    targetDiaryId: string;
  }
//}

===={sec04-04-6} トップコンポーネントにStoreを登録
トップコンポーネントにStoreを登録します。「src/index.ts」を編集します。
「Provider関数」をreact-reduxパッケージからインストールします。

//blankline
また、作成したStoreもインポートします。

//list[][src/index.ts]{
  import React from 'react';
  import ReactDOM from 'react-dom';
  import { Provider } from 'react-redux';
  import App from './components/App';

  import store from './redux/redux-og';

  ReactDOM.render(
    <Provider store={store}>
      <App />
    </Provider>,
    document.getElementById('root')
  );

//}

以上が完了しましたら動作確認します。

//blankline
ブラウザが起動しましたらdevToolsを確認します。Reduxタブを開くとStateの内容を確認できます。

//image[devTools01][Stateの確認][scale=0.8,pos=H]
=={sec04-05} コンポーネントの修正
Stateが無事に作成できましたので、各コンポーネントでデータの参照はStateから、
データの変更はActionCreatorに引数を渡しdispatchします。

//blankline
サンプルアプリケーションでの変更点は、

 1. DiaryBoadコンポーネントでStateから読書日記データを取得する。
 2. DiaryCardHeaderコンポーネントで直接データを削除する。

の２点が主ですが、それに伴う細かなコードの変更があります。

===={sec04-05-1} DiaryBoadコンポーネントでデータ取得
Appコンポーネントで取得した「読書日記データdiaries」をDiaryBoadコンポーネントにてStateから取得します。

//list[][Appコンポーネント]{
  import React from 'react';
  import CssBaseline from '@mui/material/CssBaseline';
  import { createTheme, ThemeProvider } from '@mui/material/styles';

  import DiaryBoard from './DiaryBoard';

  const theme = createTheme();

  const App = () => (
    <ThemeProvider theme={theme}>
      <CssBaseline />
      <DiaryBoard />
    </ThemeProvider>
  );

  export default App;
//}

DiaryBoadコンポーネントで読書日記データを取得しますので、propsが不要になりました。useSelectorで
データを取得します。今までのコードはコメントアウトしました。

//list[][DiaryBoadコンポーネントでデータ取得]{
  const DiaryBoard = () => {
    // const { diaries } = props;
    const diaryData = useSelector((state: State) => state.diaries);
//}

ここで動作確認します。

===={sec04-05-2} DiaryCardHeaderコンポーネントで削除
孫コンポーネントのDiaryCardHeaderコンポーネントが、親コンポーネント(DiaryCard)を経由して
じじコンポーネント(DiaryBoard)へ「削除の要求とdiaryId」を伝えていました。

//blankline
Reduxを導入したので、孫から直接データを削除します。

//list[][DiaryCardHeaderコンポーネントでデータ削除]{
  import { useDispatch } from 'react-redux';

  import { deleteDiaryActionCreator } from '../redux/redux-og';

  const DiaryCardHeader = (props: DiaryCardHeaderProps) => {
    const dispatch = useDispatch();

    // ダイアログの削除ボタンクリック
    const handleConfirmDelete = () => {
    setOpenDialog(false);
    // return onClickCardHeaderAction(diaryId, 'DELETE');
    dispatch(deleteDiaryActionCreator({ diaryId }));
  };

//}

===={sec04-05-3} devToolsでの表示
Google chromeのdevToolsを使えば、ディスパッチされたActionの内容を確認できますし、
変更されたStateの内容も変更前・変更後と確認できます。

//image[devTools02][実行されたActionのtype][scale=0.8,pos=H]

//image[devTools03][実行されたActionの内容][scale=0.8,pos=H]


===={sec04-05-4} Redux導入でコード修正したファイル

Reduxの導入で修正したコードは、

 * Appコンポーネント　読書日記データのバケツリレーをやめた
 * DiaryBoardコンポーネント　Stateからデータ取得、削除をDiaryCardHeaderコンポーネントへ委譲
 * DiaryCardコンポーネント 親コンポーネントから子コンポーネントへ渡す関数の引数変更
 * DiaryCardHeaderコンポーネント 削除を自身で行う 編集要求の引数変更

 です。

変更後のコードは、Appコンポーネントは上記です。ほかのコンポーネントは、こちらになります。

//list[][DiaryBoardコンポーネント]{
  import React, { useState } from 'react';
  import { useDispatch, useSelector } from 'react-redux';
  import AppBar from '@mui/material/AppBar';
  import Grid from '@mui/material/Grid';
  import Box from '@mui/material/Box';
  import Toolbar from '@mui/material/Toolbar';
  import Typography from '@mui/material/Typography';
  import Container from '@mui/material/Container';
  import Link from '@mui/material/Link';
  import IconButton from '@mui/material/IconButton';
  import AddCircleOutlineIcon from '@mui/icons-material/AddCircleOutline';
  import { v4 as uuidv4 } from 'uuid';

  import {
    createDiaryActionCreator,
    editDiaryActionCreator,
    State,
  } from '../redux/redux-og';

  import { Diary } from '../diaryData';
  import DiaryCard from './DiaryCard';
  import DiaryFormDialog from './DiaryFormDialog';

  // diary初期化データ
  const initialDiary: Diary = {
    diaryId: '',
    title: '',
    postDate: '',
    imageUrl: '',
    imageLabel: '',
    mainContent: '',
    readmore: [],
  };

  const Copyright = () => (
    <Typography variant='body2' color='text.secondary' align='center'>
      {'Copyright © '}
      <Link color='inherit' href='https://mui.com/'>
        やる夫が読書します。
      </Link>
      {` ${new Date().getFullYear()}.`}
    </Typography>
  );

  const DiaryBoard = () => {
    // ActionCreatorから返ってきたActionをReducerへ送る
    const dispatch = useDispatch();
    // 読書日記データ
    const diaryData = useSelector((state: State) => state.diaries);
    // DiaryFormDialogの開閉状態
    const [openDialog, setOpenDialog] = useState(false);
    // 編集対象の読書日記データ
    const [targetDiaryData, setTargetDiaryData] = useState(initialDiary);

    // Formにデータを渡して表示する
    const setDataToForm = (diaryId: string) => {
      if (diaryId.length === 0) {
        setTargetDiaryData(initialDiary);
        setOpenDialog(true);
      } else {
        const editDiary = diaryData.filter((d) => d.diaryId === diaryId);
        if (editDiary.length === 1) {
          setTargetDiaryData(editDiary[0]);
          setOpenDialog(true);
        }
      }
    };

    // 編集対象データでDiaryFormDialogを開く
    const openForm = () => {
      setDataToForm('');
    };

    // 編集・削除ボタンクリック
    const onClickCardHeaderAction = (diaryId: string): void => {
      setDataToForm(diaryId);
    };

    // 編集フォームから呼ばれる
    const closeForm = (diary: Diary | null) => {
      // Dialogを閉じる
      setOpenDialog(false);
      if (diary !== null) {
        // 保存
        let newDiary: Diary;
        if (diary.diaryId === '') {
          const newDiaryId: string = uuidv4();
          newDiary = { ...diary, diaryId: newDiaryId };
          dispatch(createDiaryActionCreator(newDiary));
        } else {
          newDiary = { ...diary };
          dispatch(editDiaryActionCreator(newDiary));
        }
      }
    };

    return (
      <>
        <AppBar position='relative'>
          <Toolbar>
            <Box sx={{ flexGrow: 1 }}>
              <Typography variant='h6' color='inherit' noWrap>
                やる夫の読書日記
              </Typography>
            </Box>
            <Box>
              <IconButton
                size='large'
                edge='end'
                aria-label='新規読書日記'
                onClick={openForm}
                color='inherit'
              >
                <AddCircleOutlineIcon />
              </IconButton>
            </Box>
          </Toolbar>
        </AppBar>
        <main>
          <Container sx={{ py: 8 }} maxWidth='md'>
            <Grid container spacing={4}>
              {diaryData.map((diary) => (
                <Grid item key={diary.diaryId} xs={12} sm={6} md={4}>
                  <DiaryCard
                    diary={diary}
                    onClickCardHeaderAction={onClickCardHeaderAction}
                  />
                </Grid>
              ))}
            </Grid>
          </Container>
        </main>
        {/* Footer */}
        <Box sx={{ bgcolor: 'background.paper', p: 6 }} component='footer'>
          <Typography variant='h6' align='center' gutterBottom>
            やる夫の読書日記
          </Typography>
          <Typography
            variant='subtitle1'
            align='center'
            color='text.secondary'
            component='p'
          >
            お前らも本読んだ良いお〜！
          </Typography>
          <Copyright />
        </Box>
        {/* End footer */}
        <DiaryFormDialog
          open={openDialog}
          diary={targetDiaryData}
          closeForm={closeForm}
        />
      </>
    );
  };

  export default DiaryBoard;

//}

DiaryCardコンポーネントは、Propsは、親コンポーネントからコンポーネントへ渡す
メニューがクリックされたときの関数の引数が変わっているだけです。

//list[][DiaryCardコンポーネント]{
  import React from 'react';
  import { styled } from '@mui/material/styles';
  import Card from '@mui/material/Card';
  import CardMedia from '@mui/material/CardMedia';
  import CardContent from '@mui/material/CardContent';
  import CardActions from '@mui/material/CardActions';
  import Collapse from '@mui/material/Collapse';
  import IconButton, { IconButtonProps } from '@mui/material/IconButton';
  import Typography from '@mui/material/Typography';
  import FavoriteIcon from '@mui/icons-material/Favorite';
  import ShareIcon from '@mui/icons-material/Share';
  import ExpandMoreIcon from '@mui/icons-material/ExpandMore';
  import Box from '@mui/material/Box';

  import { Diary } from '../diaryData';
  import DiaryCardHeader from './DiaryHeader';

  export type DiaryCardProps = {
    diary: Diary;
    onClickCardHeaderAction: (diaryId: string) => void;
  };

  // アイコンクリックで詳細部分を表示するためのコンポーネントのpros型
  interface ExpandMoreProps extends IconButtonProps {
    expand: boolean;
  }

  // アイコンクリックで詳細部分を表示するコンポーネント
  const ExpandMore = styled((props: ExpandMoreProps) => {
    // eslint-disable-next-line @typescript-eslint/no-unused-vars
    const { expand, ...other } = props;
    // eslint-disable-next-line react/jsx-props-no-spreading
    return <IconButton {...other} />;
  })(({ theme, expand }) => ({
    transform: !expand ? 'rotate(0deg)' : 'rotate(180deg)',
    marginLeft: 'auto',
    transition: theme.transitions.create('transform', {
      duration: theme.transitions.duration.shortest,
    }),
  }));

  // DiaryCardコンポーネント
  const DiaryCard = (props: DiaryCardProps) => {
    // 詳細表示コンポーネントの表示・非表示の状態
    const [expanded, setExpanded] = React.useState(false);

    // 詳細コンポーネントの表示・非表示を切り替える関数
    const handleExpandClick = () => {
      setExpanded(!expanded);
    };

    // 受け取ったオブジェクトを変数に展開
    const { diary, onClickCardHeaderAction } = props;
    const {
      diaryId,
      title,
      postDate,
      imageUrl,
      imageLabel,
      mainContent,
      readmore,
    } = diary;

    return (
      <Card sx={{ maxWidth: 345 }}>
        <DiaryCardHeader
          diaryId={diaryId}
          title={title}
          postDate={postDate}
          onClickCardHeaderAction={onClickCardHeaderAction}
        />
        <Box
          sx={{
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
          }}
        >
          <CardMedia
            sx={{ width: '100px' }}
            component='img'
            image={imageUrl}
            alt={imageLabel}
          />
        </Box>
        <CardContent>
          <Typography variant='body2' color='text.secondary'>
            {mainContent}
          </Typography>
        </CardContent>
        <CardActions disableSpacing>
          <IconButton aria-label='add to favorites'>
            <FavoriteIcon />
          </IconButton>
          <IconButton aria-label='share'>
            <ShareIcon />
          </IconButton>
          <ExpandMore
            expand={expanded}
            onClick={handleExpandClick}
            aria-expanded={expanded}
            aria-label='show more'
          >
            <ExpandMoreIcon />
          </ExpandMore>
        </CardActions>
        <Collapse in={expanded} timeout='auto' unmountOnExit>
          <CardContent>
            {readmore.map((parag, index) => (
              <Typography paragraph key={`${diaryId}${index.toString()}`}>
                {parag}
              </Typography>
            ))}
          </CardContent>
        </Collapse>
      </Card>
    );
  };

  export default DiaryCard;

//}

DiaryCardHeaderコンポーネントは、編集メニューがクリックされたときの引数の変更と削除をコンポーネント内で
行うように変更しています。

//list[][DiaryCarHeaderコンポーネント]{
  /* eslint-disable @typescript-eslint/no-unsafe-assignment */
  import React from 'react';
  import { useDispatch } from 'react-redux';
  import CardHeader from '@mui/material/CardHeader';
  import Avatar from '@mui/material/Avatar';
  import Menu from '@mui/material/Menu';
  import MenuItem from '@mui/material/MenuItem';
  import ListItemIcon from '@mui/material/ListItemIcon';
  import MoreVertIcon from '@mui/icons-material/MoreVert';
  import EditIcon from '@mui/icons-material/Edit';
  import DeleteForeverIcon from '@mui/icons-material/DeleteForever';
  import IconButton from '@mui/material/IconButton';
  import Button from '@mui/material/Button';
  import Dialog from '@mui/material/Dialog';
  import DialogActions from '@mui/material/DialogActions';
  import DialogContent from '@mui/material/DialogContent';
  import DialogContentText from '@mui/material/DialogContentText';
  import DialogTitle from '@mui/material/DialogTitle';

  import { deleteDiaryActionCreator } from '../redux/redux-og';

  import January from '../assets/images/month-icons/january.svg';
  import February from '../assets/images/month-icons/february.svg';
  import March from '../assets/images/month-icons/march.svg';
  import April from '../assets/images/month-icons/april.svg';
  import May from '../assets/images/month-icons/may.svg';
  import Jun from '../assets/images/month-icons/june.svg';
  import July from '../assets/images/month-icons/july.svg';
  import August from '../assets/images/month-icons/august.svg';
  import September from '../assets/images/month-icons/september.svg';
  import October from '../assets/images/month-icons/october.svg';
  import November from '../assets/images/month-icons/november.svg';
  import December from '../assets/images/month-icons/december.svg';

  import {
    convertToLongDateString,
    convertStringToDate,
  } from '../utilities/helper';

  export type DiaryCardHeaderProps = {
    diaryId: string;
    title: string;
    postDate: string;
    onClickCardHeaderAction: (diaryId: string) => void;
  };

  const DiaryCardHeader = (props: DiaryCardHeaderProps) => {
    const dispatch = useDispatch();
    const { onClickCardHeaderAction, diaryId, title, postDate } = props;

    // menuの開閉状態を管理
    const [anchorEl, setAnchorEl] = React.useState<null | HTMLElement>(null);
    // ダイアログの表示・非表示
    const [openDialog, setOpenDialog] = React.useState(false);

    // menuの開閉
    const openMenu = Boolean(anchorEl);
    // MoreVerIconクリック
    const handleClick = (event: React.MouseEvent<HTMLElement>) => {
      setAnchorEl(event.currentTarget);
    };

    // menuを閉じる
    const handleCloseMenu = () => {
      setAnchorEl(null);
    };

    // ダイアログ表示
    const handleClickOpenDialog = () => {
      handleCloseMenu();
      setOpenDialog(true);
    };

    // 編集メニュークリック
    const handleEdit = () => {
      handleCloseMenu();
      return onClickCardHeaderAction(diaryId);
    };

    // 削除メニュークリック
    const handleDelete = () => {
      handleClickOpenDialog();
    };

    // ダイアログ非表示
    const handleCloseDialog = () => {
      setOpenDialog(false);
    };

    // ダイアログの削除ボタンクリック
    const handleConfirmDelete = () => {
      setOpenDialog(false);
      // return onClickCardHeaderAction(diaryId, 'DELETE');
      dispatch(deleteDiaryActionCreator({ diaryId }));
    };

    // postDate:YYYYMMDDから月を取得し
    const datePosted: Date = convertStringToDate(postDate);
    let avatarSrc;
    // useEffect(() => {
    switch (datePosted.getMonth()) {
      case 0:
        avatarSrc = January;
        break;
      case 1:
        avatarSrc = February;
        break;
      case 2:
        avatarSrc = March;
        break;
      case 3:
        avatarSrc = April;
        break;
      case 4:
        avatarSrc = May;
        break;
      case 5:
        avatarSrc = Jun;
        break;
      case 6:
        avatarSrc = July;
        break;
      case 7:
        avatarSrc = August;
        break;
      case 8:
        avatarSrc = September;
        break;
      case 9:
        avatarSrc = October;
        break;
      case 10:
        avatarSrc = November;
        break;
      case 11:
        avatarSrc = December;
        break;
      default:
        break;
    }

    const posted = convertToLongDateString(postDate);

    return (
      <>
        <CardHeader
          avatar={
            <Avatar
              sx={{ width: 58, height: 58 }}
              variant='square'
              aria-label={`投稿日:${posted}`}
              src={avatarSrc}
            />
          }
          action={
            <IconButton aria-label='settings' onClick={handleClick}>
              <MoreVertIcon />
            </IconButton>
          }
          title={title}
          subheader={posted}
        />
        <Menu
          anchorEl={anchorEl}
          id='account-menu'
          open={openMenu}
          onClose={handleCloseMenu}
          onClick={handleCloseMenu}
          PaperProps={{
            elevation: 0,
            sx: {
              overflow: 'visible',
              filter: 'drop-shadow(0px 2px 8px rgba(0,0,0,0.32))',
              mt: 1.5,
              '& .MuiAvatar-root': {
                width: 32,
                height: 32,
                ml: -0.5,
                mr: 1,
              },
              '&:before': {
                content: '""',
                display: 'block',
                position: 'absolute',
                top: 0,
                right: 14,
                width: 10,
                height: 10,
                bgcolor: 'background.paper',
                transform: 'translateY(-50%) rotate(45deg)',
                zIndex: 0,
              },
            },
          }}
          transformOrigin={{ horizontal: 'right', vertical: 'top' }}
          anchorOrigin={{ horizontal: 'right', vertical: 'bottom' }}
        >
          <MenuItem onClick={handleEdit}>
            <ListItemIcon>
              <EditIcon fontSize='small' />
            </ListItemIcon>
            編集
          </MenuItem>
          <MenuItem onClick={handleDelete}>
            <ListItemIcon>
              <DeleteForeverIcon fontSize='small' />
            </ListItemIcon>
            削除
          </MenuItem>
        </Menu>
        <Dialog open={openDialog} onClose={handleCloseDialog}>
          <DialogTitle>削除の確認だお〜</DialogTitle>
          <DialogContent>
            <DialogContentText>
              削除すると、基には戻せないお〜！それでも削除するのかお〜？
            </DialogContentText>
          </DialogContent>
          <DialogActions>
            <Button onClick={handleCloseDialog}>キャンセル</Button>
            <Button onClick={handleConfirmDelete}>削除</Button>
          </DialogActions>
        </Dialog>
      </>
    );
  };

  export default DiaryCardHeader;

//}

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
  $ > git clone -b 07_install-redux https://github.com/yaruo-react-redux/yaruo-cra-template.git
//}
#@#<!-- textlint-enable -->
//}

=={sec-chap04review} 第4章のまとめ
#@#<!-- textlint-disable -->
Reduxを状態管理に使う
#@#<!-- textlint-enable -->

 * Reduxの動作イメージ
 * Reduxの導入
 * Action Typeの定義 〜 Storeの作成まで
 * コンポーネントでの使用

 を解説しました。
