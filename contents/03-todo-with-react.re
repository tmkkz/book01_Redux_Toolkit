= 日記アプリケーションの作成(Reactのみ)
//image[diary01][完成サンプルアプリケーション][scale=0.4,pos=H,border=on]
//clearpage
//abstract{
  本章では、第2章で作成したスタートアップ用のアプリケーションを魔改造し、日記アプリケーションを作成します。@<br>{}

  また、表示用のUIには、Googleが提唱するMaterial DesignのReact用UIの最新版MUI5を使用します。
//}

サンプルアプリケーションで使用している書籍データ(表紙画像)は、
@<href>{https://www.hanmoto.com/about_bookdata, 版元ドットコム}の規約に基づいています。

//clearpage
=={sec-031React} Reactとは？

まずは、「Reactとは、いったい何なのでしょうか？」

//blankline
本家「reactjs.org」のドキュメントは@<href>{https://ja.reactjs.org, 日本語(ja.reactjs.org)}
でも読むことができます。

でも、ここで言われている特徴、

 * 宣言的なView
 * コンポーネントベース
 * 一度学習すれば、どこでも使える

って、「なに言っているのか、良く分かりません。」

//blankline
フロントエンド用フレームワークが当たり前の我々は知らないのですが
jQueryなどでガチのJavaScriptプログラミングされていた方は、たいへんな思いをしていたのではないでしょうか？

//blankline
たとえば、テキストボックスの入力を検証をする場合には、

 1. テキストボックスをdom内から取得(getElementById)
 2. その要素に検証用関数の呼び出しを行うイベントの追加(addEventListener)
 3. 検証しエラーがある場合には、エラー表示用の要素をdom内から取得
 4. エラー表示用要素へ表示(innerHTML)

 が必要です。

//blankline
コードにすると、

//list[][テキストボックス表示部分]{
  <div>
    <input id="yaruo" type="text" value="">
    <p id="yaranaio"></p>
  </div>
//}

//list[][JavaScript部分]{
  <script>
    const input = document.getElementById("yaruo");
    input.addEventListener("input", validationFunc);

    function validationFunc(event) {
      const inputValue = event.target.value;

	    let errMsg = '';
      // check value
      if (inputValue.length < 5) {
        errMsg = '5文字以上の入力が必要です。';
      }

      // display error message
      const errMsgArea = document.getElementById("yaranaio");
      errMsgArea.innerText = errMsg;
    }
  </script>
//}

このように、テキストボックス1つでも、けっこうなコード量になり、おまけに表示部分とコード部分が分かれていてます。

//blankline
もし、入力部分が数個あるフォームだと、入力の表示部分と対応コード部分を探すものたいへんですし
、デバッグも悪夢のようだと思いませんか？

//blankline
また、使用する関数がそれぞれ別のファイルに分かれていた場合など、関数とファイル名の対応表まで必要になります。

//blankline
それが「React」を使うと、

//list[][Reactの場合]{
  import React, { useState } from 'react';

  const YaruoInput = () => {
    const [inputValue, setInputValue] = useState('');
    const [errMsg, setErrMsg] = useState('');

    const handleValidate = (event: React.ChangeEvent<HTMLInputElement>) => {
      setInputValue(event.target.value);

      if (event.target.value.length < 5) {
        setErrMsg('5文字以上の入力が必要です。');
      } else {
        setErrMsg('');
      }
    };

    return (
      <div>
        <input
          id='yaruo'
          type='text'
          value={inputValue}
          onChange={handleValidate}
        />
        <p id='yaranaio'>{errMsg}</p>
      </div>
    );
  };
  export default YaruoInput;
//}

このようにUIコンポーネントとして定義でき、再利用も簡単に行えます。

//list[][Reactのコンポーネントを使う]{
import React from 'react';
import YaruoInput from filePath

const App = () => (
  <>
    <YaruoInput />
    <別なコンポーネント　/>
    <HTMLタグ>
    </HTMLタグ>
 );

 export default App;
//}

同じ機能を持つテキストボックスでもReactを使うことで、UIコンポーネントとして定義し再利用・保守が格段に上がりました。

//blankline
これが、「宣言的なView」、「コンポーネントベース」です。

#@# jsxについてやる夫画像で解説

=={sec-032UIDataType} 表示するデータの型
それでは、サンプルアプリケーションについて説明します。このサンプルアプリケーションは、読書日記としていますが
通常の日記でもかまいません。

//blankline
保持するデータは、

 : diaryId(文字列)
 日記のID、ユニークな文字列とする。
 : title(文字列)
 日記のタイトル
 : postDate(文字列)
 投稿日をYYYYMMDD形式で持つ
 : imageUrl(文字列)
 アイキャッチ画像のURL
 : imageLabel(文字列)
 画像のalt属性
 : mainContent(文字列)
 本文
 : readmore(文字列の配列)
 追記。段落を配列の要素とする。

とします。

//blankline
最初に表示するデータを初期値として持ちます。

実際の初期値は、こちらです(長い文字列は省略しています。GitHub上で実物を確認してください)。

//list[][読書日記の初期値]{
  export type Diary = {
    diaryId: string;
    title: string;
    postDate: string;
    imageUrl: string;
    imageLabel: string;
    mainContent: string;
    readmore: string[];
  };

  const diaries: Diary[] = [
    {
      diaryId: '9784781611495',
      title: '「タモリ学　戸部田誠」を読んだお',
      postDate: '20210601',
      imageUrl: 'http://inazuma.xsrv.jp/book_images/9784781611495_100.jpg',
      imageLabel: '',
      mainContent:
        'デビュー時から現在までの、・・・',
      readmore: [
        'タモリにとって「アドリブとは何か？」',
        'タモリをもっと知りたくて。デビュー時から現在までの、・・・',
        '著者について',
        '78年生まれ、いわき市在住のテレビっ子。お笑い、格闘技、・・・',
      ],
    },

・・・中略

    {
      diaryId: '9784041047361',
      title: '「経済ヤクザ　一橋文哉」を読んだお',
      postDate: '20211101',
      imageUrl: 'http://inazuma.xsrv.jp/book_images/9784041047361_100.jpg',
      imageLabel: '',
      mainContent:
        '日本の経済はこうして動かされてきた。政界や一般企業に食い込み、・・・',
      readmore: [
        '政界や企業に食い込み、ハイエナの如くマネーを貪った「経済ヤクザ」たち。・・・',
        '彼らが復興利権やITバブルをいかにして我が物としてきたか',
      ],
    },
  ];
//}


=={sec-033} Material Design５の導入

ここでは、表示に使用するUIとしてGoogle推奨の「Material Design」に従ってデザインされたReact用UIの
@<href>{https://mui.com/,「MUI5(Material Design User Interface version5)」}を導入します。

//blankline
MUIを使うと、こんな画面もパーツを組み合わせるだけで構築できます。

//image[mui-sample][MUIサンプル][scale=0.5,border=on]

もちろんカスタマイズも自由自在で、コンポーネントの各ページにあるサンプル付属のコードを
ブラウザ上でフロントエンド環境を試せる
@<href>{https://codesandbox.io/, CodeSandbox}をクリック一発で開き、カスタマイズを試すことができます。

//image[mui001-mui_compo_sample][コンポーネントのサンプル][scale=0.6]

//image[mui002-codesandbox][クリックでCodeSandboxを開いたところ][scale=0.6]


==={sec-0330Install} MUIのインストール
MUIのインストールは、MUIトップページから「Get started」ボタンをクリックすると表示されます。

//image[mui000-mui-top][MUIトップページ][scale=0.5]

npmを使ったインストールは、material-iconも含め以下となります。

//terminal[][MUIのインストール]{
  > npm install @mui/material @emotion/react @emotion/styled @mui/icons-material
//}

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 01_install-MUI https://github.com/yaruo-react-redux/yaruo-diary.git
//}
#@#<!-- textlint-enable -->
//}

==={sec-0330UI} データ表示画面を作る
データの一覧画面を作成します。

//blankline
製品版の場合は、１画面に表示するデータ数を決め、それを超えた場合にはページネーションを作成しますが、
今回のサンプルアプリケーションは、1画面とします。

//blankline
１画面のデータ表示を４とかに決め、ページネーションにて前後ページに移動するように魔改造してみてください。

//blankline
では、データ表示コンポーネント(DiaryBoard)を作成します。
「/src/components」に「DiaryBoard.tsx」ファイルを作成します。

==={sec-0331} MUI5のサイトからテンプレートを拝借

MUI5のサイトの左上部のメニューには、

 * Getting Started
 ** Templates
 * Components
 ** Buttonなどのコンポーネント
 * Compotent API
 ** ComponentのProps(引数)の詳細

 があります。

そのTemplateを選択すると、以下のようにMUIで作成されたサンプルページ(コンポーネントを組み合わせたもの)が表示されます。

//image[mui004-templates][MUIのTemplateページ][scale=0.5]

今回は、この中から「Album layout」を拝借して改造していきます。

//clearpage
//image[mui005-albumLayout][アルバムレイアウト][scale=0.5]

先ほどのテンプレートページの「Album Layout」内の「SOURCECODE」をクリックします。

//clearpage
//image[mui006-albumLayoutSource][ソースコードへのリンク][scale=0.4]

MUIのGitHubが開き、JavaScript、TypeScriptのソースコードがあります。今回は、Album.tsxを開きます。

//image[mui007-albumLayoutSourceCode][GitHubでのAlbumのソースコード][scale=0.6]

//clearpage
このコードを作成した「DiaryBoard.tsx」ファイルへ貼り付け、以下を変更します。

 * コンポーネント名(関数名)を「DiaryBoard」へ。
 * ThemeProviderコンポーネント、CssBaselineコンポーネントを削除。
 * ThemeProviderコンポーネントの位置に、<></>を置くこと。
 * Hero unit、カメラアイコンの削除。
 * 「const theme = createTheme()」を削除。
 * functionをアロー関数に変更。
 * 削除したコンポーネントのimport文を削除。

「<></>」をトップのタグにした理由は、「Jsxはひとつの要素のみ」と怒られるからです。
このタグをトップに置くことで、要素は１つ(ほかは子要素)となります。また、不要なdivタグに変換されません。

//blankline
 変更の完了したコードがこちらです。なります。

//list[][src/components/DiaryBoard.tsx]{
  import * as React from 'react';
  import AppBar from '@mui/material/AppBar';
  import Button from '@mui/material/Button';
  import Card from '@mui/material/Card';
  import CardActions from '@mui/material/CardActions';
  import CardContent from '@mui/material/CardContent';
  import CardMedia from '@mui/material/CardMedia';
  import Grid from '@mui/material/Grid';
  import Box from '@mui/material/Box';
  import Toolbar from '@mui/material/Toolbar';
  import Typography from '@mui/material/Typography';
  import Container from '@mui/material/Container';
  import Link from '@mui/material/Link';

  const Copyright = () => (
    <Typography variant='body2' color='text.secondary' align='center'>
      {'Copyright © '}
      <Link color='inherit' href='https://mui.com/'>
        Your Website
      </Link>
      {` ${new Date().getFullYear()}.`}
    </Typography>
  );

  const cards = [1, 2, 3, 4, 5, 6, 7, 8, 9];

  const DiaryBoard = () => (
    <>
      <AppBar position='relative'>
        <Toolbar>
          <Typography variant='h6' color='inherit' noWrap>
            やる夫の読書日記
          </Typography>
        </Toolbar>
      </AppBar>
      <main>
        <Container sx={{ py: 8 }} maxWidth='md'>
          <Grid container spacing={4}>
            {cards.map((card) => (
              <Grid item key={card} xs={12} sm={6} md={4}>
                <Card
                  sx={{
                    height: '100%',
                    display: 'flex',
                    flexDirection: 'column',
                  }}
                >
                  <CardMedia
                    component='img'
                    sx={{
                      // 16:9
                      pt: '56.25%',
                    }}
                    image='https://source.unsplash.com/random'
                    alt='random'
                  />
                  <CardContent sx={{ flexGrow: 1 }}>
                    <Typography gutterBottom variant='h5' component='h2'>
                      Heading
                    </Typography>
                    <Typography>
                      This is a media card. You can use this section to describe
                      the content.
                    </Typography>
                  </CardContent>
                  <CardActions>
                    <Button size='small'>View</Button>
                    <Button size='small'>Edit</Button>
                  </CardActions>
                </Card>
              </Grid>
            ))}
          </Grid>
        </Container>
      </main>
      {/* Footer */}
      <Box sx={{ bgcolor: 'background.paper', p: 6 }} component='footer'>
        <Typography variant='h6' align='center' gutterBottom>
          Footer
        </Typography>
        <Typography
          variant='subtitle1'
          align='center'
          color='text.secondary'
          component='p'
        >
          Something here to give the footer a purpose!
        </Typography>
        <Copyright />
      </Box>
      {/* End footer */}
    </>
  );

  export default DiaryBoard;

//}

次に、Appコンポーネントを変更し、DiaryBoardコンポーネントを表示するように変更します。
また、先ほど削除した「ThemeProvider」、「CssBaseline」、「createTheme()」も追加します。

追加完了したコードが以下となります。

//list[][変更後のAppコンポーネント]{
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

最後に、不要になった「style.css」、「style.scss」を削除し、「index.tsx」を変更します。

//list[][index.tsx]{
  import React from 'react';
  import ReactDOM from 'react-dom';
  import App from './components/App';

  ReactDOM.render(
    <div>
      <App />
    </div>,
    document.getElementById('root')
  );
//}

以上の変更が完了しましたら、動作確認します。

//terminal[][サンプルアプリケーションの動作確認]{
  > npm run start
//}

この画面が表示されれば正常です。カードの画像はランダムですので、違っていてもかまいません。

//image[mui008-album-done][Album Layoutの拝借][scale=0.8]

//clearpage
==={sec-0332} カード一覧画面の表示

カード表示用のボードができましたので、表示するカードは別なものにしましょう。

//blankline
MUIのメニューから「Components > Card」をクリックすると、たくさんのサンプルがあります。
少し下へスクロールすると、こちらが見つかりました。
「<>」アイコンをクリックすると、JS/TS別にソースコードが表示されます。

//image[mui009-card-ComplexInteraction][MUIカードサンプル][scale=1.0]

「src/components/」フォルダに「DiaryCard.tsx」ファイルを作成しソースコードをコピペします。

以下を変更します。

 * 1行目「import * as React」を「import React」へ(理由はのちほど)
 * function関数をアロー関数へ
 * 関数名の変更「DiaryCard」へ
 * 表示するデータをProps(引数)として受け取る
 * 受け取ったオブジェクトを表示するようにtsxに埋め込む

===={sec-00332-1} import * as React呪文

「import」は、ES6仕様のモジュール読み込み方法です。

//blankline
 : import * as React from 'react' の場合
 fromにある「react」がexportしているものすべてをインポート
 : import React from 'react' の場合
 fromにある「react」が「default」でexportしているものだけをインポート

//blankline
結果としての違いは、webpackでバンドルした場合に作成されるビルドファイルはインポートされたものを含むため、
使用しないものまでインポートするとファイルサイズが肥大化する恐れがあります。

===={sec-00332-2} function関数をアロー関数へ

ファンクション関数とアロー関数の違いについては、
@<href>{https://qiita.com/suin/items/a44825d253d023e31e4d, こちらの記事}が参考になります。
//image[sec00332-1-01][ファンクション関数とアロー関数の違い][scale=0.5]

また、Reactでアロー関数を使うことについては、
@<href>{https://zenn.dev/seya/articles/0317b7a61ee781, こちらの記事}が参考になります。

//image[sec00332-1-02][Reactコンポーネントの書き方][scale=0.5]

===={sec-00332-3} 関数名の変更

関数名を「RecipeReviewCard」から「DiaryCard」へ変更します。
exportも忘れずに。

===={sec-00332-4} 表示するデータを受け取る

Reactコンポーネントのjsx(tsx)では、HTML内にJavaScriptのオブジェクトを「{}」で埋め込み表示できます。

TypeScriptでは、受け取るオブジェクトの型を定義します。

//blankline
コンポーネントは、表示するためのデータ(表示する子要素も含む)を「Props(プロパティの意味)」として受け取ります。
コンポーネント関数からしてみると引数にあたります。

受け取るProps(引数)の型を、「src/diaryData.ts」ファイルを作成し定義します。このファイルは、のちほど初期値も追加します。


===={sec-00332-5} 受け取ったオブジェクトを埋め込む

//blankline
受け取ったオブジェクトを変数に展開し、表示位置に埋め込みます。

===={sec-00332-6} DiaryCardを表示する

初期値を設定し、Appコンポーネントに「DiaryBoard」の代わりに表示してみます。こちらが表示されれば完成です。
もちろん、「下向き」をクリックすると詳細部分が表示されます。readmore配列の各要素が段落になっています。

//image[sec00332-6][カードの単体表示][scale=0.6]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 02_Component-Cardboard https://github.com/yaruo-react-redux/yaruo-diary.git
//}
#@#<!-- textlint-enable -->
//}

==={sec-0333} リファクタリング１(サンプルデータ全表示)

用意してあるサンプルデータを初期値として使用し、カード一覧へ表示しましょう。

//blankline
先ほどデータ型を記入したデータファイル「src/diaryDate.ts」へサンプル用データをコピペします。
サンプルアプリケーションのGitHubサイトにありますので使ってください。

次に、「App.tsx」を変更します。

 1. initialDataは不要になったので削除。
 2. 作成したサンプルデータをインポート。
 3. DiaryBoardコンポーネントをpropsを受け付けるよう変更

 変更後の「Appコンポーネント」は、こちらになります。

//list[][変更後のAppコンポーネント]{
  import React from 'react';
  import CssBaseline from '@mui/material/CssBaseline';
  import { createTheme, ThemeProvider } from '@mui/material/styles';

  import diaries from '../diaryData';
  import DiaryBoard from './DiaryBoard';

  const theme = createTheme();

  const App = () => (
    <ThemeProvider theme={theme}>
      <CssBaseline />
      <DiaryBoard diaries={diaries} />
    </ThemeProvider>
  );

  export default App;
//}

「DiaryBoardコンポーネント」を変更します。

 1. propsでDiary型の配列を受け付ける
 2. DiaryCardコンポーネントを使って各データを表示する
 3. Footerのべた書き文字列をアプリケーション用に変更する。

変更した「DiaryBoardコンポーネント」が、こちらになります。

//list[][変更後のDiaryBoardコンポーネント]{
  import React from 'react';
  import AppBar from '@mui/material/AppBar';
  import Grid from '@mui/material/Grid';
  import Box from '@mui/material/Box';
  import Toolbar from '@mui/material/Toolbar';
  import Typography from '@mui/material/Typography';
  import Container from '@mui/material/Container';
  import Link from '@mui/material/Link';

  import { Diary } from '../diaryData';
  import DiaryCard from './DiaryCard';

  export type DiaryBoardProps = {
    diaries: Diary[];
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

  const DiaryBoard = (props: DiaryBoardProps) => {
    const { diaries } = props;

    return (
      <>
        <AppBar position='relative'>
          <Toolbar>
            <Typography variant='h6' color='inherit' noWrap>
              やる夫の読書日記
            </Typography>
          </Toolbar>
        </AppBar>
        <main>
          <Container sx={{ py: 8 }} maxWidth='md'>
            <Grid container spacing={4}>
              {diaries.map((diary) => (
                <Grid item key={diary.diaryId} xs={12} sm={6} md={4}>
                  <DiaryCard diary={diary} />
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
      </>
    );
  };

  export default DiaryBoard;
//}

変更が完了しましたら、動作確認をします。以下のように表示されると成功です。

//clearpage
//image[diaryBoad_done][全データ表示][scale=0.7]

==={sec-0336} リファクタリング2(カードヘッダを別コンポーネントへ)
「DiaryCardコンポーネント」のタイトルの右側にある「縦の３点」アイコンをクリックしても、今は何も起こりません。
このアイコンボタンを利用して、「編集・削除」の機能を持たせます。

MUIサイトのコンポーネント例の「Menu」にあるものを拝借します。
//image[mui010-card-Menu][アイコンボタンでポップアップメニュー][scale=0.6]

//blankline
「CardHeader」を再利用することはないでしょうが、管理・メンテナンスを考えて別コンポーネントにします。

//blankline

 1. 「DiaryCardHeader.tsx」ファイルを作成しコンポーネントのテンプレを書く
 2. 「DiaryCard.tsx」から、CardHeader部分を「DiaryCardHeader.tsx」切り出し
 3. 「DiaryCardコンポーネント」に「DiaryCardHeaderコンポーネント」をインポートして使用

 変更が完了したファイルは、このようになります。

//list[][DiaryCardHeaderコンポーネント]{
   import React from 'react';
  import CardHeader from '@mui/material/CardHeader';
  import Avatar from '@mui/material/Avatar';
  import { red } from '@mui/material/colors';
  import MoreVertIcon from '@mui/icons-material/MoreVert';
  import IconButton from '@mui/material/IconButton';

  export type DiaryCardHeaderProps = {
    diaryId: string;
    title: string;
    postDate: string;
  };

  const DiaryCardHeader = (props: DiaryCardHeaderProps) => {
    const { diaryId, title, postDate } = props;
    return (
      <CardHeader
        avatar={
          <Avatar sx={{ bgcolor: red[500] }} aria-label='recipe'>
            R
          </Avatar>
        }
        action={
          <IconButton aria-label='settings'>
            <MoreVertIcon />
          </IconButton>
        }
        title={title}
        subheader={`postID:${diaryId}-${postDate}`}
      />
    );
  };

  export default DiaryCardHeader;
//}

「DiaryCardコンポーネント」は、このようになります。

//list[][DiaryCardコンポーネントのCardHeaderがあった部分]{
   return (
    <Card sx={{ maxWidth: 345 }}>
      <DiaryCardHeader diaryId={diaryId} title={title} postDate={postDate} />
      <CardMedia
        component='img'
        height='194'
        image={imageUrl}
        alt={imageLabel}
      />
      <CardContent>
        <Typography variant='body2' color='text.secondary'>
          {mainContent}
        </Typography>
      </CardContent>
//}

この時点で動作確認を行います。無事に表示されていれば良いです。

===={sec-0336-1} DiaryCarHeaderコンポーネントにメニューを組み込む

MUIのサイトからメニュー部分のコードを拝借して「DiaryCardHeaderコンポーネント」に追加しましょう。
やりたいことは「編集、削除」ですので、メニュー項目(MenuItem)は２つでかまいません。

//clearpage
//image[mui011-card-MenuCode][MUIのMenuサンプル][scale=0.7]


拝借するコードは、「CardHeader」と同じ階層に貼り付けますが、その場合「Jsxはひとつの要素」と怒られますので、
トップ階層に「<></>」を追加します。

//blankline
必要なMUIのコンポーネント、アイコンもインポートするのですが、アイコンは、

 : 編集アイコン
 import EditIcon from '@mui/icons-material/Edit';
 : 削除アイコン
 import DeleteForeverIcon from '@mui/icons-material/DeleteForever';

を使い、Avatarコンポーネントではなく「ListItemIconコンポーネント」を使います。サンプルメニューの
区切り線の下の部分で使われています。

//blankline
最後は、「AccountMenuコンポーネント」の関数(HTML内に埋め込まれています)も忘れずにコピペしてください。

//blankline
handleClick関数は、MoreVertIconの親要素のIconButtonの「onClick」に追加します。

ここまでの変更が完了すると「DiaryCardHeaderコンポーネント」は、このようになります。

//list[][変更完了のDiaryCardHeaderコンポーネント]{
  import React from 'react';
  import CardHeader from '@mui/material/CardHeader';
  import Avatar from '@mui/material/Avatar';
  import { red } from '@mui/material/colors';
  import Menu from '@mui/material/Menu';
  import MenuItem from '@mui/material/MenuItem';
  import ListItemIcon from '@mui/material/ListItemIcon';
  import MoreVertIcon from '@mui/icons-material/MoreVert';
  import EditIcon from '@mui/icons-material/Edit';
  import DeleteForeverIcon from '@mui/icons-material/DeleteForever';
  import IconButton from '@mui/material/IconButton';

  export type DiaryCardHeaderProps = {
    diaryId: string;
    title: string;
    postDate: string;
  };

  const DiaryCardHeader = (props: DiaryCardHeaderProps) => {
    const { diaryId, title, postDate } = props;
    const [anchorEl, setAnchorEl] = React.useState<null | HTMLElement>(null);
    const open = Boolean(anchorEl);
    const handleClick = (event: React.MouseEvent<HTMLElement>) => {
      setAnchorEl(event.currentTarget);
    };
    const handleClose = () => {
      setAnchorEl(null);
    };

    return (
      <>
        <CardHeader
          avatar={
            <Avatar sx={{ bgcolor: red[500] }} aria-label='recipe'>
              R
            </Avatar>
          }
          action={
            <IconButton aria-label='settings' onClick={handleClick}>
              <MoreVertIcon />
            </IconButton>
          }
          title={title}
          subheader={`postID:${diaryId}-${postDate}`}
        />
        <Menu
          anchorEl={anchorEl}
          id='account-menu'
          open={open}
          onClose={handleClose}
          onClick={handleClose}
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
          <MenuItem>
            <ListItemIcon>
              <EditIcon fontSize='small' />
            </ListItemIcon>
            編集
          </MenuItem>
          <MenuItem>
            <ListItemIcon>
              <DeleteForeverIcon fontSize='small' />
            </ListItemIcon>
            削除
          </MenuItem>
        </Menu>
      </>
    );
  };

  export default DiaryCardHeader;
//}

ここまでの変更を動作確認します。「縦の３点アイコン」をクリックするとメニューが表示されますか？

//clearpage
//image[mui012-card-MenuStep1][クリックするとメニューが表示される][scale=0.7]

メニューが無事表示されたので、のちほど実際の関数に置き換えるとして、テストとしてアラートを出してみます。
「編集・削除」のMenuItemコンポーネントに「onClick」を追加し対応する関数を書きます。

//blankline
ただし、削除がクリックされたときには「本当に削除しますか？」と確認のダイアログを出すようにします。
ダイアログは、MUIサイトの「Dialog」から「Transitions」を拝借します。

//image[mui013-card-deleteDialog][MUIサイトのTransitionsダイアログ][scale=0.6,pos=H]

//blankline
「Dialogコンポーネント」のソースコードを表示し、<Dialog> ~ </Dialog>を</Menu>の下へコピペします。
不要なものは削除し、「キャンセル」、「削除」のボタンを作成します。もちろん、必要な関数もコピペします。

//blankline
コピペすると、メニューの開閉状態の「open」とダイアログ表示状態の「open」が重複しますので、それぞれ
「openMenu」、「openDialog」に名前を変えます。また閉じる関数「handleClose」も重複しますので名前を変えます。

//blankline
Menuの「削除」をクリック　-> 確認ダイアログ表示 -> 削除 -> アラート表示になるように関数呼び出します。

//blankline
ここまでの変更が完了しましたら動作確認します。

 * 編集メニューをクリックしたときにアラートはでましたか？
 * 削除メニューをクリックしたときに確認ダイアログが表示しましたか？
 * 確認ダイアログの削除をクリックしたときにアラートはでましたか？

//clearpage
//image[mui014-card-deleteDialog-done][削除確認ダイアログの表示][scale=0.7,pos=H]

===={sec-0336-2} DiaryBoardHeaderの見栄え

もう少し見栄え良くしたいので、DiaryCardHeaderコンポーネントの、

 1. アバターの代わりに投稿月の画像を表示
 2. サブタイトルに投稿日を「YYYY年M月D日」で表示

を実装します。

===== アバターの代わりに投稿月画像を表示
//blankline
1月〜12月までのSVG画像は、GitHubサイトにあります。「src/assets/images/month-icons」フォルダを作成してコピペしてください。

//blankline
読書日記データの投稿日は「YYYYMMDD」形式の文字列ですので、この文字列からJavaScriptのDateオブジェクトを返す関数を作成します。
また、のちほど作成する読書日記の新規追加・編集時のため日付から「YYYYMMDD」の文字列を作成する関数も合わせて作成します。

どの場所からも使えるように「src/utilities/helper.ts」ファイルを作成し、ここに関数を作成します。

//list[][src/utilities/helper.ts]{
  // DateオブジェクトからYYYYMMDDの文字列へ変換
  export const convertDateToString = (date: Date): string => {
    const monthString = `0${date.getMonth() + 1}`.slice(-2);
    const dayString = `0${date.getDate()}`.slice(-2);

    return `${date.getFullYear()}${monthString}${dayString}`;
  };

  // YYYYMMDD文字列からDateオブジェクトへ変換
  export const convertStringToDate = (dateString: string): Date => {
    let date;
    if (dateString.length !== 8) {
      date = new Date();
    } else {
      date = new Date(
        +dateString.slice(0, 4),
        +dateString.slice(4, 6) - 1,
        +dateString.slice(6)
      );
    }
    return date;
  };
//}

convertStringToDate関数をインポートし、読書日記の「YYYYMMDD」から月を取得し、画像のソースを指定します。
DiaryCardHeaderコンポーネントに追加する関数は、こちらとなります。

//list[][Dateと文字列の変換関数]{
  // DateオブジェクトからYYYYMMDDの文字列へ変換
  export const convertDateToString = (date: Date): string => {
    const monthString = `0${date.getMonth() + 1}`.slice(-2);
    const dayString = `0${date.getDate()}`.slice(-2);

    return `${date.getFullYear()}${monthString}${dayString}`;
  };

  // YYYYMMDD文字列からDateオブジェクトへ変換
  export const convertStringToDate = (dateString: string): Date => {
    let date;
    if (dateString.length !== 8) {
      date = new Date();
    } else {
      date = new Date(
        +dateString.slice(0, 4),
        +dateString.slice(4, 6) - 1,
        +dateString.slice(6)
      );
    }
    return date;
  };
//}

DiaryCardHeaderコンポーネントにアバターのソースを切り替える関数を作成し、
「CardHeaderコンポーネント内Avatarコンポーネント」のsrc要素にします。
ついでに、四角形に変えサイズも大きめにします。

//blankline
追加したコードです。

//list[][画像の切替とAvatarへの指定]{
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

  return (
    <>
      <CardHeader
        avatar={
          <Avatar
            sx={{ width: 58, height: 58 }}
            variant='square'
            aria-label='recipe'
            src={avatarSrc}
          />
        }
//}

===== サブタイトルに投稿日を「YYYY年M月D日」で表示
「src/utilities/helper.ts」に、「YYYYMMDD」文字列から「YYYY年M月D日」に変換する関数を作成します。

//list[][YYYY年M月D日文字列の作成関数]{
  // YYYYMMDDからYYYY年M月Dに変換
  export const convertToLongDateString = (dateString: string) => {
    const date = convertStringToDate(dateString);
    return `${date.getFullYear()}年${date.getMonth() + 1}月${date.getDate()}日`;
  };
//}

DiaryCardHeaderコンポーネントへ「convertToLongDateString」をインポートし、投稿日データを表示します。

//list[][投稿日を表示]{
  const posted = convertToLongDateString(postDate);

  <CardHeader
    avatar={
      <Avatar
        sx={{ width: 58, height: 58 }}
        variant='square'
        aria-label={`投稿日:${posted}`}  @<balloon>{ラベルにも表示}
        src={avatarSrc}
      />
    }
    action={
      <IconButton aria-label='settings' onClick={handleClick}>
        <MoreVertIcon />
      </IconButton>
    }
    title={title}
    subheader={posted}　@<balloon>{サブタイトルに投稿日}
  />
//}

さて、ここまでの変更が完了しましたら、動作確認を行います。

//clearpage
//image[mui015-card-Header-done][desc][scale=0.7]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 04_refactoring_DiaryHeader https://github.com/yaruo-react-redux/yaruo-diary.git
//}
#@#<!-- textlint-enable -->
//}

==={sec-0337} 入力フォームコンポーネントの作成
読書データの新規追加・編集のためのフォームを作成します。

//blankline
フォームは、DialogとしてDiaryBoadコンポーネントに追加し、DiaryBoardコンポーネントに新規追加ボタンで表示するようにします。
作成するフォームは別コンポーネントとするために「src/components/DiaryForm.tsx」ファイルを作成します。

//clearpage
MUIサイトのComponents内のText fieldコンポーネントには、フォームとして使えそうなサンプルがあります。

//image[mui016-muisite-textField][MUIサイトのテキストフィールド][scale=0.6]

これらを参考にしてフォームを作成します。また、投稿日の入力用にMUIのDatePickerを使うのですが、
このコンポーネントはラボ(実験中)に分類されています。そのためMUIのLabと日付を扱うためのライブラリ「date-fns」
をインストールします。

//image[mui017-muisite-datePicker][MUIのDatePicker][scale=0.7]

//terminal[][MUIのラボ、date-fnsのインストール]{
　❯ npm install @mui/lab date-fns
//}

DiaryFormコンポーネントは、propsとして読書日記データを受け取ります。

 * 新規入力の場合には、すべてが空欄の読書日記データ
 * 編集時には、指定された読書日記データ

となります。

//blankline
DiaryFormコンポーネントにあるすべてのテキストフィールドは、React HooksのひとつのuseStateを使用して
入力されたデータを保持します。

//blankline
テキストフィールドに入力されるデータは、タイトルと本文のみは4文字以上の入力を必須とします。

作成したフォームは、こちらになります。

//list[][DiaryForm]{
  import React, { useState, useRef } from 'react';
  import Grid from '@mui/material/Grid';
  import Paper from '@mui/material/Paper';
  import TextField from '@mui/material/TextField';
  import AdapterDateFns from '@mui/lab/AdapterDateFns';
  import LocalizationProvider from '@mui/lab/LocalizationProvider';
  import DatePicker from '@mui/lab/DatePicker';
  import Button from '@mui/material/Button';
  import CancelIcon from '@mui/icons-material/Cancel';
  import DataSaverOnIcon from '@mui/icons-material/DataSaverOn';
  import Stack from '@mui/material/Stack';

  import { convertStringToDate } from '../utilities/helper';
  import { Diary } from '../diaryData';

  interface DiaryFormProps {
    diary: Diary;
  }

  const DiaryForm = (props: DiaryFormProps) => {
    const { diary } = props;
    const {
      diaryId,
      title,
      postDate,
      imageUrl,
      imageLabel,
      mainContent,
      readmore,
    } = diary;

    // hooksでフォームデータ保持
    // タイトル
    const [onEditTitle, setOnEditTitle] = useState(title);
    const [diaryTitleErr, setDiaryTitleErr] = useState(false);
    const [diaryTitleErrMsg, setDiaryTitleErrMsg] = useState('');
    // 投稿日
    const [onEditPostDate, setOnEditPostDate] = useState<Date | null>(
      convertStringToDate(postDate)
    );
    // 画像URL
    const [onEditImageUrl, setOnEditImageUrl] = useState(imageUrl);
    // 画像ALT
    const [onEditImageLabel, setOnEditImageLabel] = useState(imageLabel);
    // 本文
    const [onEditMainContent, setOnEditMainContent] = useState(mainContent);
    const [mainContentErr, setMainContentErr] = useState(false);
    const [mainContentErrMsg, setMainContentErrMsg] = useState('');
    // 追記
    const [onEditReadMore, setOnEditReadMore] = useState(readmore.join('\n\n'));

    const titleRef = useRef<HTMLInputElement>(null);
    const mainContentRef = useRef<HTMLInputElement>(null);

    // 入力データ検証
    const validateFieldData = (event: React.ChangeEvent<HTMLInputElement>) => {
      switch (event.target.name) {
        case 'diaryTitle':
          setOnEditTitle(event.target.value);
          if (event.target.value.length < 5) {
            setDiaryTitleErr(true);
            setDiaryTitleErrMsg('4文字以上入力してください。');
          } else {
            setDiaryTitleErr(false);
            setDiaryTitleErrMsg('');
          }
          break;
        case 'diaryMainContent':
          setOnEditMainContent(event.target.value);
          if (event.target.value.length < 5) {
            setMainContentErr(true);
            setMainContentErrMsg('4文字以上入力してください。');
          } else {
            setMainContentErr(false);
            setMainContentErrMsg('');
          }
          break;
        case 'diaryReadMore':
          setOnEditReadMore(event.target.value);
          break;
        case 'diaryImageUrl':
          setOnEditImageUrl(event.target.value);
          break;
        case 'diaryImageLabel':
          setOnEditImageLabel(event.target.value);
          break;
        default:
          break;
      }
    };

    // 保存ボタン
    const saveData = () => {};

    // キャンセルボタン
    const cancelForm = () => {};

    return (
      <Paper variant='outlined' sx={{ m: 1, py: 2 }}>
        <Grid container spacing={2} sx={{ pl: 5 }}>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              required
              id='diary-title'
              label='タイトル'
              error={diaryTitleErr}
              fullWidth
              name='diaryTitle'
              value={onEditTitle}
              helperText={diaryTitleErrMsg}
              onChange={validateFieldData}
              inputRef={titleRef}
            />
          </Grid>
          <Grid item xs={10} sm={8} md={6} lg={4}>
            {/* eslint-disable-next-line @typescript-eslint/no-unsafe-assignment */}
            <LocalizationProvider dateAdapter={AdapterDateFns}>
              <DatePicker
                label='日付'
                value={onEditPostDate}
                onChange={(newValue: Date | null) => {
                  setOnEditPostDate(newValue);
                }}
                // eslint-disable-next-line react/jsx-props-no-spreading
                renderInput={(params) => <TextField {...params} />}
              />
            </LocalizationProvider>
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              required
              multiline
              id='diary-mainContent'
              label='本文'
              error={mainContentErr}
              fullWidth
              name='diaryMainContent'
              value={onEditMainContent}
              helperText={mainContentErrMsg}
              onChange={validateFieldData}
              inputRef={mainContentRef}
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              multiline
              minRows='4'
              maxRows='6'
              id='diary-readmore'
              label='追記'
              fullWidth
              name='diaryReadMore'
              value={onEditReadMore}
              onChange={validateFieldData}
              helperText='空行を入れると段落表示されます。'
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              id='diary-imageUrl'
              label='画像URL'
              fullWidth
              name='diaryImageUrl'
              onChange={validateFieldData}
              value={onEditImageUrl}
              helperText='画像のURL'
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              id='diary-imageLabel'
              label='画像の代替テキスト'
              fullWidth
              name='diaryImageLabel'
              onChange={validateFieldData}
              value={onEditImageLabel}
              helperText='画像が表示されない場合のテキスト'
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <Stack direction='row' spacing={2}>
              <Button
                variant='contained'
                startIcon={<CancelIcon />}
                onClick={cancelForm}
              >
                キャンセル
              </Button>
              <Button
                variant='contained'
                endIcon={<DataSaverOnIcon />}
                onClick={saveData}
              >
                保存
              </Button>
            </Stack>
          </Grid>
        </Grid>
      </Paper>
    );
  };

  export default DiaryForm;

//}

作成したフォームをダイアログとして表示するコンポーネントを作成します。

//blankline
「src/components/DiaryFormDialog.tsx」ファイルを作成し、MUIのダイアログの表示・非表示を実装します。

//list[][DiaryFormDialog]{
  import React from 'react';
  import Dialog from '@mui/material/Dialog';
  import DialogTitle from '@mui/material/DialogTitle';

  import { Diary } from '../diaryData';
  import DiaryForm from './DiaryForm';

  export interface DialogDiaryFormProps {
    open: boolean;
    diary: Diary;
  }

  const DialogDiaryForm = (props: DialogDiaryFormProps) => {
    const { open, diary } = props;

    return (
      <Dialog open={open}>
        <DialogTitle>日記編集</DialogTitle>
        <DiaryForm diary={diary} />
      </Dialog>
    );
  };

  export default DialogDiaryForm;
//}

DiaryBoardコンポーネントに、新規追加ボタン追加しフォームが開くよう実装します。

 1. 空欄の初期化データinitialDiaryを作成
 2. DiaryFormDialogコンポーネントをインポートし追加
 3. 新規追加アイコンをツールバーに追加し、クリックするとDiaryFormDialogが開く

以上の変更を加えた「DiaryBoardコンポーネント」は、こちらになります。

//list[][新規追加ボタンを追加したDiaryBoardコンポーネント]{
  import React, { useState } from 'react';
  import AppBar from '@mui/material/AppBar';
  import Grid from '@mui/material/Grid';
  import Box from '@mui/material/Box';
  import Toolbar from '@mui/material/Toolbar';
  import Typography from '@mui/material/Typography';
  import Container from '@mui/material/Container';
  import Link from '@mui/material/Link';
  import IconButton from '@mui/material/IconButton';
  import AddCircleOutlineIcon from '@mui/icons-material/AddCircleOutline';

  import { Diary } from '../diaryData';
  import DiaryCard from './DiaryCard';
  import DiaryFormDialog from './DiaryFormDialog';

  export type DiaryBoardProps = {
    diaries: Diary[];
  };

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

  const DiaryBoard = (props: DiaryBoardProps) => {
    const { diaries } = props;

    // DiaryFormDialogの開閉状態
    const [openDialog, setOpenDialog] = useState(false);

    // 新規データでDiaryFormDialogを開く
    const openForm = () => setOpenDialog(true);

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
              {diaries.map((diary) => (
                <Grid item key={diary.diaryId} xs={12} sm={6} md={4}>
                  <DiaryCard diary={diary} />
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
        <DiaryFormDialog open={openDialog} diary={initialDiary} />
      </>
    );
  };

  export default DiaryBoard;

//}

変更が完了したら動作確認をします。ツールバーに「＋」のアイコンボタンが表示され、クリックすると入力フォームが開きます。

 * それぞれのテキストフィールドに入力はできますか？
 * タイトルと本文が４文字以下だとエラーがでますか？
 * DatePickerは、動作しますか？

開いた入力フォームですが、保存・キャンセルとも機能実装していません。そのため一度開いたフォームを閉じることができません。

//clearpage
//image[mui018-DiaryForm-done][入力フォームを開いた状態][scale=0.7]

=={sec-034hooks} データの追加・編集・削除
表示用のコンポーネントが完成したので、データの追加・編集削除ができるように機能実装を行います。

//blankline
分かりづらい図ですが、コンポーネントの構成を図にしました。
Reactコンポーネントは表示するためのデータをPropsを介して受け取るため、孫コンポーネントに表示するデータも
祖父母コンポーネントから親コンポーネントを経由して渡します。

//blankline
これが「Reactあるある」のひとつ「Propsバケツリレー」です。

//image[AppComponents][コンポーネントの構成図][scale=0.7,pos=H]

今回のように孫コンポーネントにあたる「DiaryCardHeaderコンポーネント」の編集・削除の要求があった場合には
全データを管理する「DiaryBoadコンポーネント」に伝えなければなりません。

//blankline
表示は、親コンポーネントからバケツリレーで伝え、
孫コンポーネントで受けたユーザーからの要求は逆のルートをたどって親まで伝えることになります。
孫で発生した要求を親に伝える方法として一般的なのが、関数をPropsとしてデータと伴に子・孫へ渡す方法です。

//blankline
今回のアプリケーションでは、DiaryBoadコンポーネントが、

 * 削除要求は、diaryIdを知らせてね。
 * 編集要求は、全データ持っているので編集対象のdiaryIdを知らせてね。フォームにセットするから。
 * 入力フォームでの保存要求は、保存するデータをください。diaryIdが既存のものは上書き、ほかは追加。

 の関数をそれぞれのコンポーネントにバケツリレーし、孫で関数を実行すれば親に要求が伝わることになります。

//blankline
データの変化が起こると、ブラウザが再描画されます。Reactコンポーネントの場合、
再描画されるためのデータの変化とは、propsとコンポーネント自身で管理しているものです。

//blankline
DiaryBoadコンポーネントでは、管理するデータをuseStateで状態管理し、ブラウザの描画にもその状態を使う
必要があります。そのためDiaryBoadコンポーネントにuseStateを追加します。

//list[][DiaryBoad.tsx]{
  // 全データ Appコンポーネントから受け取ったデータで初期化する
  const [diaryData, setDiaryData] = useState(diaries);

・・・中略

　// 管理しているデータを描画に使用する
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
//}


==={sec-034-1} 削除・編集関数をPropsにデータと渡す

DiaryCardHeaderコンポーネントのPropsに「diaryId、編集・削除フラグ」を引数とする関数を追加します。

//terminal[][DiaryCardHeader.tsxの変更]{
  export type DiaryCardHeaderProps = {
    diaryId: string;
    title: string;
    postDate: string;
    onClickCardHeaderAction: (diaryId: string, mode: string) => void;
  };
//}

DiaryHeaderコンポーネントでは、受けたPropsから関数を取り出し、メニューがクリックされたときに
実行する関数を実装します。

//list[][DiaryCardHeader.tsx]{
  //propsからの取り出し
  const { onClickCardHeaderAction, diaryId, title, postDate } = props;

  // 編集メニュークリック
  const handleEdit = () => {
    handleCloseMenu();
    return onClickCardHeaderAction(diaryId, 'EDIT');
  };

  // ダイアログの削除ボタンクリック
  const handleConfirmDelete = () => {
    setOpenDialog(false);
    return onClickCardHeaderAction(diaryId, 'DELETE');
  };

//}

完成したDiaryCardHeaderコンポーネントは、こちらです。

//list[][DiaryCardHeader.tsx]{
  /* eslint-disable @typescript-eslint/no-unsafe-assignment */
  import React from 'react';
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
    onClickCardHeaderAction: (diaryId: string, mode: string) => void;
  };

  const DiaryCardHeader = (props: DiaryCardHeaderProps) => {
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
      return onClickCardHeaderAction(diaryId, 'EDIT');
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
      return onClickCardHeaderAction(diaryId, 'DELETE');
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

次に、DiaryCardHeaderコンポーネントの親のDiaryCardコンポーネントも親から受け取り、子に渡します。

//list[][DiaryCard.tsx]{
  // propsの型定義
  export type DiaryCardProps = {
    diary: Diary;
    onClickCardHeaderAction: (diaryId: string, mode: string) => void;
  };

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

  return (
  <Card sx={{ maxWidth: 345 }}>
    <DiaryCardHeader
      diaryId={diaryId}
      title={title}
      postDate={postDate}
      onClickCardHeaderAction={onClickCardHeaderAction} @<balloon>{子に送る}
    />
//}

バケツリレーですので、受け取って渡すだけです。変更後のDiaryCardHeaderコンポーネントは、こうなります。

//list[][DiaryCard.tsx]{
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

  import { Diary } from '../diaryData';
  import DiaryCardHeader from './DiaryHeader';

  export type DiaryCardProps = {
    diary: Diary;
    onClickCardHeaderAction: (diaryId: string, mode: string) => void;
  };

  // アイコンクリックで詳細部分を表示するためのコンポーネントのpros型
  interface ExpandMoreProps extends IconButtonProps {
    expand: boolean;
  }

  // アイコンクリックで詳細部分を表示するコンポーネント
  const ExpandMore = styled((props: ExpandMoreProps) => {
    const { expand, ...other } = props;
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
        <CardMedia
          component='img'
          height='194'
          image={imageUrl}
          alt={imageLabel}
        />
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

最後に親のDiaryBoadコンポーネントに、子・孫に送った関数を定義します。

//list[][DiaryBoard.tsx]{
  // 編集・削除ボタンクリック
  const onClickCardHeaderAction = (diaryId: string, mode: string): void => {
    switch (mode) {
      case 'EDIT':
        setDataToForm(diaryId);
        break;
      case 'DELETE':
        deleteDiary(diaryId);
        break;
      default:
        break;
    }
  };
//}

削除はDiaryBoadコンポーネントがuseStateを使って全データを管理していますので、該当のdiaryIdを持つ
オブジェクトを削除するだけです。

//blankline
編集はDiaryBoadコンポーネントに保存対象のデータをuseStateで定義し、全データから該当のdiaryIdを持つ
オブジェクトをtargetDiaryData変数に格納します。

//blankline
新規追加は初期化データをtargetDiaryDataへ格納します。編集フォームへtargetDiaryDataを渡して表示します。

==={sec-034-1} 保存・キャンセル関数をPropsにデータと渡す

同じように、編集フォームのDiaryFormコンポーネントも、DiaryBoadコンポーネントからは孫にあたります。
保存・キャンセルの関数をバケツリレーで渡します。

DiaryFormコンポーネントのPropsに保存・キャンセルの関数を追加します。DiaryBoadコンポーネントからは
保存・キャンセルのどちらもフォームを閉じるため「closeForm関数」としました。

//blankline
保存の場合には読書日記データ、キャンセルの場合はnullを渡します。

//list[][DiaryForm.tsx]{
  interface DiaryFormProps {
    diary: Diary;
    closeForm: (diaryData: Diary | null) => void;
  }
//}

入力フォームのDatePickerはDateオブジェクトを返しますので、Dateオブジェクトから「YYYYMMDD」に変換する関数を
「src/utilities/helper.ts」に作成してあるのでDiaryFormコンポーネントにインポートします。

//blankline
保存ボタンがクリックされた場合には、データ検証し問題があれば該当のテキストフィールドにフォーカスを当てます。
そのためにuseRefを使用しています。

//blankline
空関数としていた「saveData」、「cancelData」を実装します。

//list[][DiaryForm.tsx]{
  // 保存ボタン
  const saveData = () => {
    const postDateValue: Date =
      onEditPostDate !== null ? onEditPostDate : new Date();

    if (onEditTitle.length < 5 && titleRef.current !== null) {
      titleRef.current.focus();
      return;
    }

    if (onEditMainContent.length === 0 && mainContentRef.current !== null) {
      mainContentRef.current.focus();
      return;
    }

    const diaryData = {
      diaryId,
      title: onEditTitle,
      postDate: convertDateToString(postDateValue),
      mainContent: onEditMainContent,
      readmore: onEditReadMore.split('\n\n'),
      imageUrl: onEditImageUrl,
      imageLabel: onEditImageLabel,
    };
    closeForm(diaryData);
  };

  // キャンセルボタン
  const cancelForm = () => {
    closeForm(null);
  };
//}

実装の完了したDiaryFormコンポーネントは、こちらになります。

//list[][DiaryFormコンポーネント]{
  import React, { useState, useRef } from 'react';
  import Grid from '@mui/material/Grid';
  import Paper from '@mui/material/Paper';
  import TextField from '@mui/material/TextField';
  import AdapterDateFns from '@mui/lab/AdapterDateFns';
  import LocalizationProvider from '@mui/lab/LocalizationProvider';
  import DatePicker from '@mui/lab/DatePicker';
  import Button from '@mui/material/Button';
  import CancelIcon from '@mui/icons-material/Cancel';
  import DataSaverOnIcon from '@mui/icons-material/DataSaverOn';
  import Stack from '@mui/material/Stack';

  import { convertStringToDate, convertDateToString } from '../utilities/helper';
  import { Diary } from '../diaryData';

  interface DiaryFormProps {
    diary: Diary;
    closeForm: (diaryData: Diary | null) => void;
  }

  const DiaryForm = (props: DiaryFormProps) => {
    const { diary, closeForm } = props;
    const {
      diaryId,
      title,
      postDate,
      imageUrl,
      imageLabel,
      mainContent,
      readmore,
    } = diary;

    // hooksでフォームデータ保持
    // タイトル
    const [onEditTitle, setOnEditTitle] = useState(title);
    const [diaryTitleErr, setDiaryTitleErr] = useState(false);
    const [diaryTitleErrMsg, setDiaryTitleErrMsg] = useState('');
    // 投稿日
    const [onEditPostDate, setOnEditPostDate] = useState<Date | null>(
      convertStringToDate(postDate)
    );
    // 画像URL
    const [onEditImageUrl, setOnEditImageUrl] = useState(imageUrl);
    // 画像ALT
    const [onEditImageLabel, setOnEditImageLabel] = useState(imageLabel);
    // 本文
    const [onEditMainContent, setOnEditMainContent] = useState(mainContent);
    const [mainContentErr, setMainContentErr] = useState(false);
    const [mainContentErrMsg, setMainContentErrMsg] = useState('');
    // 追記
    const [onEditReadMore, setOnEditReadMore] = useState(readmore.join('\n\n'));

    const titleRef = useRef<HTMLInputElement>(null);
    const mainContentRef = useRef<HTMLInputElement>(null);

    // 入力データ検証
    const validateFieldData = (event: React.ChangeEvent<HTMLInputElement>) => {
      switch (event.target.name) {
        case 'diaryTitle':
          setOnEditTitle(event.target.value);
          if (event.target.value.length < 5) {
            setDiaryTitleErr(true);
            setDiaryTitleErrMsg('4文字以上入力してください。');
          } else {
            setDiaryTitleErr(false);
            setDiaryTitleErrMsg('');
          }
          break;
        case 'diaryMainContent':
          setOnEditMainContent(event.target.value);
          if (event.target.value.length < 5) {
            setMainContentErr(true);
            setMainContentErrMsg('4文字以上入力してください。');
          } else {
            setMainContentErr(false);
            setMainContentErrMsg('');
          }
          break;
        case 'diaryReadMore':
          setOnEditReadMore(event.target.value);
          break;
        case 'diaryImageUrl':
          setOnEditImageUrl(event.target.value);
          break;
        case 'diaryImageLabel':
          setOnEditImageLabel(event.target.value);
          break;
        default:
          break;
      }
    };

    // 保存ボタン
    const saveData = () => {
      const postDateValue: Date =
        onEditPostDate !== null ? onEditPostDate : new Date();

      if (onEditTitle.length < 5 && titleRef.current !== null) {
        titleRef.current.focus();
        return;
      }

      if (onEditMainContent.length === 0 && mainContentRef.current !== null) {
        mainContentRef.current.focus();
        return;
      }

      const diaryData = {
        diaryId,
        title: onEditTitle,
        postDate: convertDateToString(postDateValue),
        mainContent: onEditMainContent,
        readmore: onEditReadMore.split('\n\n'),
        imageUrl: onEditImageUrl,
        imageLabel: onEditImageLabel,
      };
      closeForm(diaryData);
    };

    // キャンセルボタン
    const cancelForm = () => {
      closeForm(null);
    };

    return (
      <Paper variant='outlined' sx={{ m: 1, py: 2 }}>
        <Grid container spacing={2} sx={{ pl: 5 }}>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              required
              id='diary-title'
              label='タイトル'
              error={diaryTitleErr}
              fullWidth
              name='diaryTitle'
              value={onEditTitle}
              helperText={diaryTitleErrMsg}
              onChange={validateFieldData}
              inputRef={titleRef}
            />
          </Grid>
          <Grid item xs={10} sm={8} md={6} lg={4}>
            {/* eslint-disable-next-line @typescript-eslint/no-unsafe-assignment */}
            <LocalizationProvider dateAdapter={AdapterDateFns}>
              <DatePicker
                label='日付'
                value={onEditPostDate}
                onChange={(newValue: Date | null) => {
                  setOnEditPostDate(newValue);
                }}
                // eslint-disable-next-line react/jsx-props-no-spreading
                renderInput={(params) => <TextField {...params} />}
              />
            </LocalizationProvider>
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              required
              multiline
              id='diary-mainContent'
              label='本文'
              error={mainContentErr}
              fullWidth
              name='diaryMainContent'
              value={onEditMainContent}
              helperText={mainContentErrMsg}
              onChange={validateFieldData}
              inputRef={mainContentRef}
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              multiline
              minRows='4'
              maxRows='6'
              id='diary-readmore'
              label='追記'
              fullWidth
              name='diaryReadMore'
              value={onEditReadMore}
              onChange={validateFieldData}
              helperText='空行を入れると段落表示されます。'
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              id='diary-imageUrl'
              label='画像URL'
              fullWidth
              name='diaryImageUrl'
              onChange={validateFieldData}
              value={onEditImageUrl}
              helperText='画像のURL'
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <TextField
              id='diary-imageLabel'
              label='画像の代替テキスト'
              fullWidth
              name='diaryImageLabel'
              onChange={validateFieldData}
              value={onEditImageLabel}
              helperText='画像が表示されない場合のテキスト'
            />
          </Grid>
          <Grid item xs={10} sm={10} md={10} lg={10}>
            <Stack direction='row' spacing={2}>
              <Button
                variant='contained'
                startIcon={<CancelIcon />}
                onClick={cancelForm}
              >
                キャンセル
              </Button>
              <Button
                variant='contained'
                endIcon={<DataSaverOnIcon />}
                onClick={saveData}
              >
                保存
              </Button>
            </Stack>
          </Grid>
        </Grid>
      </Paper>
    );
  };

  export default DiaryForm;
//}

DiaryFormコンポーネントのPropsは、DiaryFormDialogコンポーネントから受け取ります。
DiaryFormDialogコンポーネントにもDiaryBoadコンポーネントから受け取るPropsに関数を追加し
DiaryFormコンポーネントへ送ります。

//list[][DiaryFormDialog.tsx]{
  import React from 'react';
  import Dialog from '@mui/material/Dialog';
  import DialogTitle from '@mui/material/DialogTitle';

  import { Diary } from '../diaryData';
  import DiaryForm from './DiaryForm';

  export type DialogDiaryFormProps = {
    open: boolean;
    diary: Diary;
    closeForm: (diaryData: Diary | null) => void;
  };

  const DialogDiaryForm = (props: DialogDiaryFormProps) => {
    const { open, diary, closeForm } = props;

    return (
      <Dialog open={open}>
        <DialogTitle>日記編集</DialogTitle>
        <DiaryForm diary={diary} closeForm={closeForm} />
      </Dialog>
    );
  };

  export default DialogDiaryForm;

//}

最後にDiaryBoadコンポーネントへ、保存・キャンセルの実装します。保存は、

 * 新規はdiaryId空欄なのでdiaryIdを作成
 * 編集はdiaryIdが既存

となります。保存は、全データから保存対象のdiaryId以外の読書日記データ配列に追加するだけです。


diaryIdを重複なく作成するためにユニークなIDを作成してくれるライブラリをインストールします。
TypeScript用の型情報もインストールします。

//terminal[][uuidのインストール]{
 > npm install uuid
 > npm install -D @types/uuid
//}

//list[][DiaryBoad.tsx]{
  import { v4 as uuidv4 } from 'uuid';

  const saveDiary = (diary: Diary) => {
    const newDiaryData = diaryData.filter((d) => d.diaryId !== diary.diaryId);
    newDiaryData.push(diary);
    setDiaryData(newDiaryData);
  };

  const closeForm = (diary: Diary | null) => {
    // Dialogを閉じる
    setOpenDialog(false);
    if (diary !== null) {
      // 保存
      let newDiary: Diary;
      if (diary.diaryId === '') {
        const newDiaryId: string = uuidv4();
        newDiary = { ...diary, diaryId: newDiaryId };
      } else {
        newDiary = { ...diary };
      }
      saveDiary(newDiary);
    }
  };
//}

ここまでの変更を動作確認します。

 * 削除する
 * 編集で各テキストフィールドの値を変える
 * 新規データを追加する

不具合はみつかりましたか？

//blankline
編集保存した場合、以前の日付で新規追加した場合とも保存したデータが最後尾に表示されます。
編集後の全データをセットする前にソートするようにしましょう。

//list[][DiaryBoad.tsx]{
  // postDateを数値に変換して比較し並べ替え
  const diarySort = (a: Diary, b: Diary) => {
    if (+a.postDate < +b.postDate) return -1;
    if (+a.postDate > +b.postDate) return 1;
    return 0;
  };

  const saveDiary = (diary: Diary) => {
   const newDiaryData = diaryData.filter((d) => d.diaryId !== diary.diaryId);
   newDiaryData.push(diary);
   newDiaryData.sort(diarySort);　　@<balloon>{ソートを追加}
   setDiaryData(newDiaryData);
  };
//}

ソートを追加したDiaryBoadコンポーネントです。

//list[][DiaryBoad.tsx]{
  import React, { useState } from 'react';
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

  import { Diary } from '../diaryData';
  import DiaryCard from './DiaryCard';
  import DiaryFormDialog from './DiaryFormDialog';

  export type DiaryBoardProps = {
    diaries: Diary[];
  };

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

  const DiaryBoard = (props: DiaryBoardProps) => {
    const { diaries } = props;

    // diary data
    const [diaryData, setDiaryData] = useState(diaries);
    // DiaryFormDialogの開閉状態
    const [openDialog, setOpenDialog] = useState(false);
    // 編集対象の読書日記データ
    const [targetDiaryData, setTargetDiaryData] = useState(initialDiary);

    // postDateを数値に変換して比較し並べ替え
    const diarySort = (a: Diary, b: Diary) => {
      if (+a.postDate < +b.postDate) return -1;
      if (+a.postDate > +b.postDate) return 1;
      return 0;
    };

    // Formにデータを渡して表示する
    const setDataToForm = (diaryId: string) => {
      if (diaryId === '') {
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
    const openForm = () => setDataToForm('');

    // 日記データの削除
    const deleteDiary = (diaryId: string) => {
      console.log(`delete:${diaryId}`);
      const newDiaryData = diaryData.filter((diary) => diary.diaryId !== diaryId);
      setDiaryData(newDiaryData);
    };

    // 編集・削除ボタンクリック
    const onClickCardHeaderAction = (diaryId: string, mode: string): void => {
      switch (mode) {
        case 'EDIT':
          setDataToForm(diaryId);
          break;
        case 'DELETE':
          deleteDiary(diaryId);
          break;
        default:
          break;
      }
    };

    // データを保存
    const saveDiary = (diary: Diary) => {
      const newDiaryData = diaryData.filter((d) => d.diaryId !== diary.diaryId);
      newDiaryData.push(diary);
      newDiaryData.sort(diarySort);
      setDiaryData(newDiaryData);
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
        } else {
          newDiary = { ...diary };
        }
        saveDiary(newDiary);
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

以上でサンプルアプリケーションは完成です。

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
  $ > git clone -b 06_implements_data_save https://github.com/yaruo-react-redux/yaruo-cra-template.git
//}
#@#<!-- textlint-enable -->
//}


=={sec03-sammary} 第３章のまとめ

 * Reactのスタートアッププロジェクトがあれば簡単に始めることができる。
 * MUIを使えばサンプルのアレンジで画面が作成できる。
 * コンポーネント間のバケツリレーはたいへん。
