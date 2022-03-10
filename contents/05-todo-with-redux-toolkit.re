= 日記アプリケーションの作成(Redux-toolkit使用)

//abstract{
　本章では、前章で導入したReduxの動作しているサンプルアプリケーションを、Redux-toolkitを使い、
どれくらいコード量が減り、苦行から解放されるのかを確認します。
@<br>{}
　
//}

//image[slice][][scale=0.8,pos=H]

//clearpage
=={sec05-01} Redux-toolkitの導入
それでは、さっそくredux-toolkitパッケージをインストールします。

//terminal[][redux-toolkitのインストール]{
　> npm install @reduxjs/toolkit
//}

以上でインストールは完了です。

//blankline
redux-toolkitでは、各データ集合毎にSliceを作成します。Sliceにreduceを登録すると、自動でActionCreatorを
作成してくれます。

//blankline
それでは、Sliceを作成するファイル「src/redux/redux-tk.ts」を追加してください。

=={sec05-02} Sliceの作成

Sliceは、「createSlice関数」を使用して作成します。
「createSlice関数」は、以下のような引数を受け取ります。

//list[][createSlice関数]{
  function createSlice({
      // 自動生成されるActionのtypeに使用される名前
      name: string,
      // stateを初期化する初期値
      initialState: any,
      // reducerのswitch文のcase項目で使用していたkey名
      reducers: Object<string, ReducerFunction | ReducerAndPrepareObject>
      // reducerを追加するためのbuilderへのコールバック、または、追加するreducer
      | Object<string, ReducerFunction>
      | ((builder: ActionReducerMapBuilder<State>) => void)
  })
//}

自動生成されるActionオブジェクトのtype要素は、「createSlice関数」のname/reducerのkey名となります。
のちほどサンプルアプリケーションの動作をdevToolsで確認しますので、どのようなActionが実行されたのかが分かります。

//blankline
サンプルアプリケーションのSliceは、このようになります。

reduceでのkey名は、

 * create
 * edit
 * remove

 にしています。「delete」は予約語ですので使えません。

//blankline
 Reduxの特徴として、「Stateのコピーを用意し操作する。Stateを直接いじらない。」とありましたが、
 Redux-toolkitではimmerライブラリが自動で変換してくれるため、Stateを直接変更してもかまいません。

//list[][サンプルアプリケーションのSlice]{
  // diaries stateを初期化する値
  const diariesInitialState: Diary[] = diaries;

  // Sliceを作成
  const diariesSlice = createSlice({
    name: 'diaries',
    initialState: diariesInitialState,
    reducers: {
      create: (state, { payload }: PayloadAction<Diary>) => {
        state.push(payload);
        state.sort(diarySort);
      },
      edit: (state, { payload }: PayloadAction<Diary>) => {
        const index = state.findIndex(
          (diary: Diary) => diary.diaryId === payload.diaryId
        );
        if (index !== -1) {
          state.splice(index, 1, payload).sort(diarySort);
        }
      },
      remove: (state, { payload }: PayloadAction<{ diaryId: string }>) => {
        const index = state.findIndex(
          (diary: Diary) => diary.diaryId === payload.diaryId
        );
        if (index !== -1) {
          state.splice(index, 1).sort(diarySort);
        }
      },
    },
  });

//}

各コンポーネントで使用するActionCreatorをエクスポートします。作成したSliceの「actions」が
ActionCreatorになります。

//blankline
keyはSliceでreducerに使用した名前で、valueは前章で作成したActionCreator名と同じ名前にしています。

//blankline
エクスポートされるのはvalueで、同じ名前でエクスポートされたのもActionCreatorですので、
使用する側の各コンポーネントではActionCreatorのインポートファイルのパスを変更するだけで、コードの変更はありません。

//list[][ActionCreatorのエクスポート]{
  export const {
    create: createDiaryActionCreator,
    edit: editDiaryActionCreator,
    remove: deleteDiaryActionCreator,
  } = diariesSlice.actions;
//}

最後に、Storeを作成しエクスポートします。Storeは「createStore関数」ではなく、
「configureStore関数」となります。

//list[][Storeの作成]{
  export default configureStore({
    reducer: reducers,
    middleware: [logger],
  });
//}

必要なインポート、ソート用の関数、Stateの型情報をいれても５８行です。前章のファイルが101行ですので、
この最小のサンプルアプリケーションでも40%の削減になります。

//blankline
規模が大きくなれば、さらに削減量は増えます。

//image[easy][][scale=0.7,pos=H]

=={sec05-03} トップコンポーネントに登録
トップコンポーネントに登録するのですが、前章で登録してあるので、Storeのインポートパスを変えるだけです。

//list[][トップコンポーネントへ登録]{
  import React from 'react';
  import ReactDOM from 'react-dom';
  import { Provider } from 'react-redux';
  import App from './components/App';

  import store from './redux/redux-tk';

  ReactDOM.render(
    <Provider store={store}>
      <App />
    </Provider>,
    document.getElementById('root')
  );

//}

//image[actionCreator2][][scale=0.7,pos=H]

=={sec05-04} コンポーネントから使用する
ActionCreatorを使用するコンポーネントも、インポートパスを変えるだけです。

//list[][DiaryBoardコンポーネント]{
  import {
    createDiaryActionCreator,
    editDiaryActionCreator,
    State,
  } from '../redux/redux-tk';
//}

//list[][DiaryCardHeaderコンポーネント]{
import { deleteDiaryActionCreator } from '../redux/redux-tk';
//}

以上で、ReduxからRedux-toolkitへ切替が完了しました。動作確認を行います。

//image[done][][scale=0.8,pos=H]

=={sec05-05} devToolsで確認
動作確認で、削除・編集・追加をしました。

//blankline
redux-loggerをMiddlewareとして導入していますので、devToolsのコンソールに、

 * 変更前のState
 * Actionの中身
 * 変更後のState

が表示されています。

//image[devTools01][コンソールに表示されたログ][scale=0.8,pos=H]

reduxタブを開くと、Action Typeが「Sliceのname/reducerのキー名」で自動作成されているのが確認できます。

//image[devTools02][ActionCreatorの自動生成の確認][scale=0.8,pos=H]
=={sec05-06} 第５章のまとめ
Redux-toolkitを使うと、コード量を削減できます。コード量が削減できることは、不具合の入り込む可能性を
低くすることを意味します。

//blankline
また、Reduxではコードが分散しがちでしたが、Redux-toolkitではSliceにまとめることができます。
見通しの良いコードは、さらに不具合の入り込みを減らすことでしょう。


//image[ending][][scale=0.8,pos=H]
