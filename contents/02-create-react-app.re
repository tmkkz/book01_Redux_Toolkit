= スタートプロジェクトの作成

//abstract{
  本章では、「create-react-app」と言う、reactアプリケーションのひな型がコマンドひとつで作成できる優れものを使用して、
スタート用のアプリケーションを作成し、ブラウザで表示するまでを行います。

　また、作成するプロジェクトは、TypesScriptを使用します。コード記法の指摘・修正を行えるよう「eslint」、「prettier」の設定も行います。

//}
=={sec-01command} create-react-appコマンド
Reactアプリケーションをゼロから作成するためには、@<br>{}
@<br>{}
 * 「nodeプロジェクト」に必要なpackage.jsonを作成
 * reactなど必要なライブラリのインストール
 * 作成したアプリケーションが、古いブラウザでも実行できるようにコードを変換(Babel使用)
 * 出力するファイルをまとめる(バンドルする - webpack使用)

 など、reactライブラリのインストール以外にも、Babelやwebpackをインストールして設定ファイルを作成しなくてはなりません。

 また、使用するライブラリによっては、Babelのプラグインのインストールや設定など、アプリケーションのコードを書き始める前の作業がたいへんです。

 しかし、「そんなメンドウなことは、やってられない。」と誰しもが思ったか、
 すぐにでもコードを書き始めることのできるスタート用アプリケーションが、react開発元のFacebookから提供されています。

 さらに、そのスタート用アプリケーションは、コマンド一発でインストールできます。

 ターミナルを起動し、プロジェクトフォルダを作成するフォルダへ移動します。

//terminal[][create-react-appでスタート用アプリケーション作成]{
  $ > npx create react-app プロジェクト名 --template typescript
//}

で、「プロジェクト名」のフォルダが作成され、スグにでも開発に取りかかれます。

#@# create-react-app やる夫 注釈



//terminal[][]{
  Success! Created yourproject at yourproject_path
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

//quote{
 コンソールには、Facebookが関わっているノード・パッケージマネージャーの「yarn」を使ったコマンドが表示されています。

　： yarn start
    開発用サーバの開始。
  : yarn build
    製品用に静的はファイルにアプリケーションをまとめる。
  : yarn test
    テストランナーの開始。
  : yarn eject
    ツール(create-react-app)を取り除き、依存関係、設定ファイル、スクリプトをappディレクトリにコピーする。

@<br>{}
　と、あります。

　yarnは、pnp(プラグ＆プレイ-依存関係(node_modulesフォルダ以下にインストールされるパッケージ)を仮想化してロードする機能)を
導入したv2で大きく変わっています。今ではv3もリリースされています。
@<br>{}
  PnPなしでもyarn v3を使うこともできるようですが、私はnpm(ノード・パッケージマネージャー)を使っています。
//}



//note[github]{
  ここまでの作業は、GitHubにあります。

//terminal[][GitHubから]{
    $ > git clone -b 00_create-react-app https://github.com/yaruo-react-redux/yaruo-blog.git
//}

//}

=={sec-02yarnstart} アプリケーションを実行
アプリケーションが作成できましたので、実行してみます。

ターミナルに表示されているように、プロジェクトフォルダへ移動し、スタート用のコマンドを入力します。

//terminal[][]{
  $ > cd プロジェクト名
  $ > npm start
//}

すると、webpackに同梱されている開発用のweb serverが起動し、デフォルトでは、port:3000でアプリケーションへアクセスできます。

//terminal[][]{
Compiled successfully!

You can now view yourproject in the browser.

  Local:            http://localhost:3000
  On Your Network:  http://pcのローカルIPアドレス:3000

Note that the development build is not optimized.
To create a production build, use yarn build.
//}

Google Chromeが起動し、http://localhost:3000へアクセスし以下のページが表示されます。

//image[02_cra_start][create-react-appの画面][scale=1.0,pos=H]

このページが表示されれば成功です。

=={sec-03cra-desc} create-react-appで作成された中身

create-react-appで作成された中身は、以下となります(使用するテンプレートにより作成されるファイル・フォルダは異なる)。

//terminal[][package.json]{
  .
  ├── node_modules
  ├── README.md
  ├── package.json
  ├── public
  │   ├── favicon.ico
  │   ├── index.html
  │   ├── logo192.png
  │   ├── logo512.png
  │   ├── manifest.json
  │   └── robots.txt
  ├── src
  │   ├── App.css
  │   ├── App.test.tsx
  │   ├── App.tsx
  │   ├── index.css
  │   ├── index.tsx
  │   ├── logo.svg
  │   ├── react-app-env.d.ts
  │   ├── reportWebVitals.ts
  │   └── setupTests.ts
  ├── tsconfig.json
  └── yarn.lock
//}

package.jsonファイルは、Node.jsを使用するプロジェクトの設計図にあたるものです。
@<br>{}
Node.jsを使うプロジェクトを開始する場合には、プロジェクトフォルダで「npm init」を行うと対話形式で「package.json」を作成しますが、
create-react-appコマンドを使用すると、package.jsonも以下のように作成されます。

//list[][package.json]{
  {
    "name": "yaruo-blog",
    "version": "0.1.0",
    "private": true,
    "dependencies": {
      "@testing-library/jest-dom": "^5.11.4",
      "@testing-library/react": "^11.1.0",
      "@testing-library/user-event": "^12.1.10",
      "@types/jest": "^26.0.15",
      "@types/node": "^12.0.0",
      "@types/react": "^17.0.0",
      "@types/react-dom": "^17.0.0",
      "react": "^17.0.2",
      "react-dom": "^17.0.2",
      "react-scripts": "4.0.3",
      "typescript": "^4.1.2",
      "web-vitals": "^1.0.1"
    },
    "scripts": {
      "start": "react-scripts start",
      "build": "react-scripts build",
      "test": "react-scripts test",
      "eject": "react-scripts eject"
    },
    "eslintConfig": {
      "extends": [
        "react-app",
        "react-app/jest"
      ]
    },
    "browserslist": {
      "production": [
        ">0.2%",
        "not dead",
        "not op_mini all"
      ],
      "development": [
        "last 1 chrome version",
        "last 1 firefox version",
        "last 1 safari version"
      ]
    }
  }
//}

package.json内にある「scripts」にあるものがコマンドになります。react-scriptsは、npmスクリプトを連続、または、並列に実行してくれるものです。
@<br>{}

package.jsonの「dependencies」には、実行に必要でインストール済みのnpmパッケージが記載されています。
必要なnpmパッケージをインストールすると、ここに自動的に追記されます。
@<br>{}
また、開発時のみ必要なパッケージ(buildしたときには組み込まれない)は、「devDependencies」に追加されます。
@<br>{}



=={sec-03lint} eslint、prettier

「lint」は、C言語用のコンパイラよりも詳細で厳密なチェックを行うプログラムです。
コンパイル前にコードをチェックするために使われます。

それが、いつしかコードをチェック・解析することを「lint」、lintを行うプログラムをlinterと呼ぶようになったそうです。

JavaScript(ECMAScript)用のlinterが、「eslint」になります。もちろん、Java、HTML、Pythonなどにもlinterがあります。

「eslint」は、JavaScriptで指定されたルールと違うコードの書き方をしている部分を指摘してくれます。
その指定されたルールとは、たいていの場合にはJavaScriptに詳しい人達が決めたもので、良く使われるものは、かの有名なAirBnBの開発チームのものです。

もちろん、ルールは改変・追加もできます。

チェックしてくれるのは、たとえば、@<br>{}

 * constで宣言している変数への代入
 * 未定義の変数やモジュールの使用
 * 分割代入の使用を推奨

などがありますが、何をチェックし指摘するのかは、チーム毎、プロジェクト毎に自由に決めることができます。


「prettier」は、コードを整形(インデント、改行など)してくれるツールです。
実は、eslintでもコード整形はできるのですが、コード整形はprettierの方が優れいます。

そのために、@<br>{}

 * コードチェックは、eslint
 * コード整形は、prettier
と、得意なものに任せます。
@<br>{}

この便利な機能こそが、第1章で紹介した@<br>{}

 * Eslint
 * Prettier
になります。
@<br>{}

==={sec-03eslint} eslint、prettierのインストール

create-react-appを使用して作成したスタートアッププロジェクトには、eslintは導入済みですので設定し直し、必要な関連パッケージをインストールします。

ターミナルに以下のように「eslint --init」と初期化コマンドを入力します。
//terminal[][eslintの初期化]{
　　$ npx eslint --init
//}

「?」が行頭にある質問と選択枝が表示されますので、カーソルキーで選択枝を選びエンターキーで次ぎの質問に移ります。
//terminal[][eslintの質問に答える]{
  ? How would you like to use ESLint? …
  ❯ To check syntax only　　　　　　　　　　　　@<balloon>{選択したものに　＞ が表示される}
    To check syntax and find problems
    To check syntax, find problems, and enforce code style
//}

最後の質問に答えると必要なパッケージをインストールするか尋ねられますので「Yes」と答えてます。
//terminal[][eslintへの答え]{
  ✔ How would you like to use ESLint? · syntax
  ✔ What type of modules does your project use? · esm
  ✔ Which framework does your project use? · react
  ✔ Does your project use TypeScript? · No / Yes　　　　@<balloon>{Yesを選択}
  ✔ Where does your code run? · browser
  ✔ What format do you want your config file to be in? · JavaScript
  Local ESLint installation not found.
  The config that you've selected requires the following dependencies:

  eslint-plugin-react@latest @typescript-eslint/eslint-plugin@latest @typescript-eslint/parser@latest eslint@latest
  ✔ Would you like to install them now with npm? · No / Yes
//}

//list[][package.jsonにeslint関連のパッケージがインストールされました。]{
  "devDependencies": {
    "@typescript-eslint/eslint-plugin": "^5.4.0",
    "@typescript-eslint/parser": "^5.4.0",
    "eslint": "^8.2.0",
    "eslint-plugin-react": "^7.27.0"
  }
//}

また、eslintの設定ファイル「.eslintrc.js」が作成されています。
//list[][.eslint.js]{
  module.exports = {
      "env": {
          "browser": true,
          "es2021": true
      },
      "extends": "plugin:react/recommended",
      "parser": "@typescript-eslint/parser",
      "parserOptions": {
          "ecmaFeatures": {
              "jsx": true
          },
          "ecmaVersion": 12,
          "sourceType": "module"
      },
      "plugins": [
          "react",
          "@typescript-eslint"
      ],
      "rules": {
      }
  };
//}

設定ファイル「.eslint.js」で、どのようなルールが適用されるのかを確認します。
適用されるルールが、「current_rules.txt」に書き出されます。
//terminal[][eslint設定で適用されるルール]{
　$ npx eslint --print-config .eslint.js > current_rules.txt
//}


eslintで使用するルールは一般的なものをベースにしたいので、あのairbnbのルールをインストールします。
//terminal[][airbnbのルーツのインストール]{
 $  npx install-peerdeps --dev eslint-config-airbnb
    install-peerdeps v3.0.3
    It seems as if you are using Yarn.
    Would you like to use Yarn for the installation? (y/n) n@<balloon>{yarnを使っているのか聞かれるので、noである「n」を入力}
//}

airbnbのルールをインストールしたので、設定ファイルに追加します。
//list[][.eslint.jsへairbnbルールを適用]{
  "extends": [
      "plugin:react/recommended",
      "airbnb",  　　　@<balloon>{airbnbのルール}
      "airbnb/hooks", @<balloon>{airbnbのReact hooksのルール}
  ],
//}

再度、ルールを出力すると適用されるルールがずいぶん増えているのが分かります。
@<br>{}
@<br>{}
次に、TypeScriptもチェックできるようにルールを追加します。「plugin:」の4行を追加しました。
//list[][.eslint.jsのextends部分]{
  "extends": [
      "plugin:react/recommended",
      "airbnb",
      "airbnb/hooks",
      "plugin:@typescript-eslint/recommended",
      "plugin:@typescript-eslint/recommended-requiring-type-checking",
      "plugin:import/recommended",
      "plugin:import/typescript",
  ],
//}

TypeScript用ルールを追加しましたので、「parserOptions」を以下のように変更する。
//list[][.eslint.jsのparserOptions部分]{
  "parserOptions": {
    "ecmaFeatures": {
        "jsx": true
    },
    "ecmaVersion": 12,
    "sourceType": "module",
    "tsconfigRootDir": __dirname,
    "project": ["./tsconfig.json"],
  },
//}

これでルールの適用は完了したが、都合の悪いルールは設定ファイルにてルールの上書をする。
//list[][.eslint.jsのrulesへ追加]{
  "rules": {
      "import/extensions": [
          "error",
          {
            js: "never",
            jsx: "never",
            ts: "never",
            tsx: "never",
          },
        ],
        "react/jsx-filename-extension": [
          "error",
          {
            extensions: [".jsx", ".tsx"],
          },
        ],
        "react/react-in-jsx-scope": "off",
        "no-void": [
          "error",
          {
            allowAsStatement: true,
          },
        ],
  }
//}

ここからは、Prettierのインストールと設定する。
//terminal[][Prettierのインストール]{
  $ npm install -D prettier eslint-config-prettier
//}

インストールが完了すると、package.jsonに追加されます。
//list[][package.json]{
  "devDependencies": {
    "@typescript-eslint/eslint-plugin": "^5.4.0",
    "@typescript-eslint/parser": "^5.4.0",
    "eslint": "^8.2.0",
    "eslint-config-airbnb": "^19.0.0",
    "eslint-config-prettier": "^8.3.0",
    "eslint-plugin-import": "^2.25.3",
    "eslint-plugin-jsx-a11y": "^6.5.1",
    "eslint-plugin-react": "^7.27.0",
    "eslint-plugin-react-hooks": "^4.3.0",
    "prettier": "^2.4.1"
  }
//}

Pretterのチェックを「.eslint.js」へ追加します。
//list[][.eslint.js]{
  "extends": [
      "plugin:react/recommended",
      "airbnb",
      "airbnb/hooks",
      "plugin:@typescript-eslint/recommended",
      "plugin:@typescript-eslint/recommended-requiring-type-checking",
      "plugin:import/recommended",
      "plugin:import/typescript",
      "prettier",　　　@<balloon>{prettierを追加}
  ],
//}

pritterの設定ファイル「.prettierrc」を追加します。設定可能なオプションは、
@<href>{https://prettier.io/docs/en/options.html, Prettierオプション}で確認できます。

ほぼすべてがデフォルトでも良いのですが、create-react-appがシングルクオートなので設定します。
//list[][.prettierrc]{
  {
    "singleQuote": true
  }
//}

eslintとprettierが衝突すると検出・修正ループに入りますので、チェックします。
//terminal[][eslint、prettierの衝突検出]{
  $ npx eslint-config-prettier 'src/**/*.{js,jsx,ts,tsx}'
    No rules that are unnecessary or conflict with Prettier were found.
//}

無事に衝突なしとなりました。

package.jsonにチェック用のスクリプトコマンドを追加します。
//list[][package.json]{
  "scripts": {
    "start": "react-scripts start",
    "build": "react-scripts build",
    "test": "react-scripts test",
    "lint": "eslint 'src/**/*.{js,jsx,ts,tsx}'",　@<balloon>{eslint用コマンドを追加}
    "eject": "react-scripts eject"
  },
//}


Eslint、Prettierの設定が完了しましたので、srcフォルダにある「App.tsx」を開いてみると、
ルールから外れるものは指摘されています。

//image[03_eslint_prettier][Eslint、Prettierに怒られてます][scale=1.0,pos=H]

=={sec-04fix} eslint、prettierの指摘を修正
ESlint、Prettierは指摘するだけではなく、修正案の提示・修正(できるものだけですが...)までしてくれます。

VSCodeにPrettier拡張機能を追加してあれば、
以下のように、VSCode側で設定すると、ファイルを保存する度に自動で修正をいれることもできます。

私は、修正を自分のタイミングで行いたいのでVSCode側の設定は行っていません。

もし、VSCode側の設定をする場合には、VSCodeで@<br>{}
[File]->[Preferences]->[Settings]にて、以下の各項目を検索して設定するか、settings.jsonへ追加してください。

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


VSCode上で、@<br>{}

 * 赤波線で指摘されている
 * 問題タブに表示されている

ものを修正します。

App.tsxの赤波線の上にマウスポンタを置くとeslintのコード、この場合は「no-use-before-define」が表示されます。、
さらに、「コマンドキー(Windowsでは、ctrl)　+ ピリオド」を押すと、修正方法が提示されます。

「Fix all auto-fixable problems」を選択すると、自動修復可能なものを修正してくれます。

//image[04_eslint_prettier_fix][ポップアップが表示][scale=1.0,pos=H]


//note[]{
  筆者がVSCodeを日本語化していないのは、エラーメッセージでググる場合を考えてのことです。
  英語でのエラーメッセージの方が的確なページをみつけやすいと考えています。
//}

では、指摘されている点を修正していきます。



//list[][App.tsx]{
  // React17からは、JSXでReactのインポートが不要になりましたので、以下の行を削除します。
  import React from 'react';
//}


//list[][App.tsx]{
  import React, { ReactElement } from "react";
  import logo from "./logo.svg";
  import "./App.css";

  const App = (): ReactElement => {
    return (
      <div className="App">
//}

このように、戻り値の型を指定することで指摘を修正できました。

//image[06_eslint_prettier_fixdoneAll][すべての問題の修正完了][scale=1.0,pos=H]

=={sec-chap02review} 第2章のまとめ
Reactを使用したアプリケーションは、スタートアップ用のアプリケーションがコマンド一発でインストールできます。

より良いコーディングをするためにも、Eslint、Prettierを導入しましょう。

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。

  //terminal[][GitHub]{
    $ > git clone -b 01_eslint_prettier https://github.com/tmkkz/yaruo.git
  //}

//}
