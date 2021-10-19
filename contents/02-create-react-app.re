= スタートプロジェクトの作成

//abstract{
  この章では、「create-react-app」と言う、reactアプリケーションの雛形がコマンドひとつで作成できる優れものを使用して、
スタート用のアプリケーションを作成し、ブラウザで表示するまでを行います。

　また、作成するプロジェクトは、Typescriptを使用します。コード記法の指摘・修正を行えるよう「eslint」、「prettier」の設定も行います。

//}
=={sec-01command} create-react-appコマンド
Reactアプリケーションを作成するためには、

 * 「nodeプロジェクト」に必要なpackage.jsonを作成
 * reactなど必要なライブラリのインストール
 * 作成したアプリケーションが、古いブラウザでも実行できるようにコードを変換(babel使用)
 * 出力するファイルを纏める(バンドルする-webpack使用)

 など、reactライブラリのインストール以外にも、babelやwebpackをインストールして設定ファイルを作成し、
 使用するライブラリーによっては、babelのプラグインのインストールや設定など、アプリケーションのコードを書き始める前の作業が大変です。

 しかし、「そんなメンドウなことは、やってられない。」ので、
 すぐにでもコードを書き始めることのできるスタート用アプリケーションが、reactの開発元であるFacebookから提供されています。

 更に、そのスタート用アプリケーションは、コマンド一発でインストールすることができます。

 ターミナルを起動し、プロジェクトフォルダを作成するフォルダへ移動します。

//terminal[][create-react-appでスタート用アプリケーション作成]{
  $ > yarn create react-app プロジェクト名 --template typescript
//}

で、「プロジェクト名」のフォルダが作成され必要なライブラリがインストールされます。

//terminal[][]{
  Success! Created yourproject at /Users/tmkkz/Documents/Devs/playground/yourproject
  Inside that directory, you can run several commands:

    yarn start
      Starts the development server.

    yarn build
      Bundles the app into static files for production.

    yarn test
      Starts the test runner.

    yarn eject
      Removes this tool and copies build dependencies, configuration files
      and scripts into the app directory. If you do this, you can’t go back!

  We suggest that you begin by typing:

    cd yourproject
    yarn start

  Happy hacking!
//}

で、プロジェクト作成が完了します。

//note[github]{
  ここまでの作業は、githubにあります。以下のコマンドでクローンしてください。

//terminal[][githubから]{
    $ > git clone -b 00_create-react-app https://github.com/tmkkz/yaruo.git
//}

//}

=={sec-02yarnstart} アプリケーションを実行
アプリケーションが作成出来ましたので、実行してみます。

ターミナルに表示されているように、プロジェクトフォルダへ移動し、スタート用のコマンドを入力します。

//terminal[][]{
  $ > cd プロジェクト名
  $ > yarn start
//}

すると、webpackに同梱されている開発用のweb serverが起動し、ディフォルトでは、port:3000でアプリケーションへアクセスできます。

//terminal[][]{
Compiled successfully!

You can now view yourproject in the browser.

  Local:            http://localhost:3000
  On Your Network:  http://192.168.1.10:3000

Note that the development build is not optimized.
To create a production build, use yarn build.
//}

Google Chromeが起動し、http://localhost:3000へアクセスし以下のページが表示されます。

//image[02_cra_start][create-react-appの画面][scale=1.0,pos=H]

このページが表示されれば成功です。

=={sec-03lint} eslint、prettierのインストールと設定
あなたがプロジェクトチームに参加しているのであれば、そのチームのコーディング規約に沿うことが求められます。

例えば、

 * ファイル、コンポーネント、関数などの命名規則
 * 文末のセミコロン
 * 改行位置
など、チーム毎、プロジェクト毎にコーディングがあります。

また、JavaScriptでは、「es5」などの標準仕様がありますので、どの標準仕様に沿ってコーディングするのかも指定されます。

自分ではコーディング規約に沿っているつもりでも、レビューを受けるまで知らなかったり、見落としていたりします。


そのため、コーディング規約に沿っているかを、

 * 自動でチェック
 * 自動で修正
 * 修正方法の提案
などをしてくれる便利なものがありますので、積極的に使うようにしましょう。


この便利な機能こそが、第1章で紹介した

 * Eslint
 * Prettier
になります。


しかし、残念ながらEslintもPrettierも

 * 沢山のプラグインがある
 * EslintとPrettierが競合する部分もある
など、メンドウなことが沢山あります。


オープンソースの世界では、メンドウなことは大抵を先人が解決してくれている、もしくは、解決しようとしている最中です。
もし、解決しようとしている最中で出来ることがあれば手伝いたいものです。

この「Eslint、Prettier」のインストール・設定についても以下の方法で簡単に解決ができます。

eslint-config
@<href>{https://www.npmjs.com/package/@abhijithvijayan/eslint-config}

こちらは、自分で使われている「Eslint、Prettier」のプラグイン・設定を公開し、
コマンド一発でインストール完了すうるようにしてくれています。

//terminal[][コマンド一発でインストール]{
  $ > npx install-peerdeps @abhijithvijayan/eslint-config --dev --yarn
//}


このプロジェクトは、

 * React
 * Typescript
を使っていますので、

プロジェクトのルートフォルダに、「.eslintrc.json」ファイルを作成し、以下のように設定をしてください。

私の好みで、Prettierにて

 * 必要な箇所には、セミコロンを付ける
 * 文字列は、ダブルクォートで囲む
と、しています。

それ以外では、airbnbを元に基本的なルールが設定してあります。ルールは、「.eslintrc.json」で上書きできますので
ご自分の好みで変更してください。

//list[][.eslintrc.json]{
  {
    "extends": [
      "@abhijithvijayan/eslint-config/typescript",
      "@abhijithvijayan/eslint-config/react"
    ],
    "parserOptions": {
      "project": "./tsconfig.json"
    },
    "rules": {
      "react/jsx-props-no-spreading": "off",
      "prettier/prettier": [
        "error",
        {
          "semi": true,
          "singleQuote": false
        }
      ]
    }
  }
//}

Eslint、Prettierの設定が完了しましたので、srcフォルダにある「App.tsx」を開いてみると、
コーディング規約に外れるものは指摘されています。

//image[03_eslint_prettier][Eslint、Prettierに怒られてます][scale=1.0,pos=H]

=={sec-04fix} eslint、prettierの指摘を修正
ESlint、Prettierは指摘するだけではなく、修正案の提示・修正(できるものだけですが・・・)までしてくれます。

VSCode側で設定を行うと、ファイルを保存する度に自動で修正をいれることもできます。

私は、修正を自分のタイミングで行いたいのでVSCode側の設定は行っていません。

もし、VSCode側の設定を行いたい場合には、VSCodeで@<br>{}
[File] -> [Preferences] -> [Settings] にて、以下の各項目を検索して設定するか、settings.jsonへ追加してください。

//list[][VSCodeの設定]{
"editor.formatOnSave": true,
"[JavaScript]": {
  "editor.formatOnSave": false
},
"[JavaScriptreact]": {
  "editor.formatOnSave": false
},
"[typescript]": {
  "editor.formatOnSave": false
},
"[typescriptreact]": {
  "editor.formatOnSave": false
},
"editor.codeActionsOnSave": {
    "source.fixAll": true,
    "source.fixAll.eslint": false
},
"prettier.disableLanguages": ["JavaScript", "JavaScriptreact", "typescript", "typescriptreact"],
//}


VSCode上で、

 * 赤波線で指摘されている
 * 問題タブひ表示ｓれている

ものを修正します。

App.tsxの赤波線の上で「コマンドキー(Windowsでは、ctrl)　+ ピリオド」を押すと、
画面のようにポップアップが表示されます。

//image[04_eslint_prettier_fix][ポップアップが表示][scale=1.0,pos=H]

「Fix all auto-fixable problems」を選択すると、自動修復可能なものを修正してくれます。

//note[]{
  筆者がVSCodeを日本語化していないのは、エラーメッセージでググる場合を考えてのことです。英語での情報の方が的確なページをみつけやすいと思います。
//}

以下のように、修正されたました。

//image[05_eslint_prettier_fixdone][修正後][scale=1.0,pos=H]

自動修正できない問題が残りました。問題点は、このファイルはTypescriptを使用していますので、@<br>{}
「関数Appの戻り値の型が指定されていない！」@<br>{}
と言うことです。

ついでに、Arrow関数へ書き換えておきます。

//list[][App.tsx]{
  import React, { ReactElement } from "react";
  import logo from "./logo.svg";
  import "./App.css";

  const App = (): ReactElement => {
    return (
      <div className="App">
//}

このように、戻り値の型を指定することで指摘を修正することができました。

//image[06_eslint_prettier_fixdoneAll][全ての問題の修正完了][scale=1.0,pos=H]

=={sec-chap02review} 第2章のまとめ
Reactを使用したアプリケーションは、スタートアップ用のアプリケーションがコマンド一発でインストールできます。

より良いコーディングをするためにも、Eslint、Prettierを導入しましょう。

//note[]{
  ここまでの内容は、github上で、以下のコマンドでクローンできます。

//terminal[][github]{
  $ > git clone -b 01_eslint_prettier https://github.com/tmkkz/yaruo.git
//}

//}
