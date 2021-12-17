= スタートプロジェクトの作成

//abstract{
Reactアプリケーションを作成するための最初のステップとして、トップページが表示されるスタートアッププロジェクトを作成します。
//blankline
スタートアッププロジェクトを作成する方法として、@<br>{}

//blankline
  1. create-react-app@<br>{}
  2. ゼロから構築@<br>{}
//blankline
の2つの方法を解説します。

//blankline
「create-react-app」は、コマンド一発でReactアプリケーション開発が数分で始められます。

//blankline
ただし、Facebook(Meta社)を中心に開発されている便利なものなのですが、メンドウな設定などが隠されているため
バージョンの合わないライブラリを入力すると整合性が崩れ手に負えなくなることもあります。

//blankline
たとえば、現行執筆時点(2021年12月12日)で、メジャーバージョンが上がっているwebpackやEslintを上書きしてしまうと
たくさんのエラーに悩まされることになります。

//blankline
「ゼロから構築」を選択すると、最新のライブラリが使用できますが、webpack、ESLintなどの設定ファイルは自分で書かなくてはなりません。
使用するライブラリの設定自体は難しくないので、ここで勉強しておけば必ず役に立つはずです。


どちらの方法もGitHubにテンプレートとしてアップロードしてありますので、ご自由にお使いください。

//}


=={sec-01command} create-react-appコマンド
Reactアプリケーションをゼロから作成するためには、@<br>{}

 * 「nodeプロジェクト」に必要なpackage.jsonを作成
 * reactなど必要なライブラリのインストール
 * 作成したアプリケーションが、古いブラウザでも実行できるようにコードを変換(Babel使用)
 * 出力するファイルをまとめる(バンドルする - webpack使用)

//blankline
など、reactライブラリのインストール以外にも、Babelやwebpackをインストールして設定ファイルを作成しなくてはなりません。

//blankline
また、使用するライブラリによっては、プラグインのインストールや設定など、アプリケーションのコードを書き始める前の作業がたいへんです。

//blankline
しかし、「そんなメンドウなことは、やってられない。」と誰しもが思ったか、
すぐにでもコードを書き始めることのできるスタート用アプリケーションが、react開発元のFacebook(Meta)から提供されています。

//blankline
さらに、そのスタート用アプリケーションは、コマンド一発でインストールできます。

//blankline
では、実際に手を動かしましょう。
ターミナルを起動し、プロジェクトフォルダを作成するフォルダへ移動します。

//terminal[][create-react-appでスタート用アプリケーション作成]{
> npx create react-app プロジェクト名 --template typescript
//}

エンターキーを押すと、作業が始まり「プロジェクト名」のフォルダが作成され、
以下のように表示されればスグにでも開発に取りかかれます。

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

//quote{
ターミナルには、Facebook(Meta)が関わっているノード・パッケージマネージャーの「yarn」を使ったコマンドが表示されています。

 : yarn start
    開発用サーバの開始。
 : yarn build
    製品用に静的はファイルにアプリケーションをまとめる。
 : yarn test
    テストランナーの開始。
 : yarn eject
    ツール(create-react-app)を取り除き、依存関係、設定ファイル、スクリプトをappディレクトリにコピーする。

//blankline
yarnは、pnp(プラグ＆プレイ-依存関係(node_modulesフォルダ以下にインストールされるパッケージ)を仮想化してロードする機能)を
導入したv2で大きく変わっています。今ではv3もリリースされています。

//blankline
PnPなしでもyarn v3を使うこともできるようですが、私はnpm(ノード・パッケージマネージャー)を使っています。
//}


//note[github]{
  ここまでの作業は、GitHubにあります。
#@#<!-- textlint-disable -->
//terminal[][GitHubから]{
> git clone -b 01_create-react-app https://github.com/yaruo-react-redux/yaruo-diary.git
//}
#@#<!-- textlit-enable -->
//}

==={sec-02yarnstart} アプリケーションを実行
アプリケーションが作成できましたので、実行してみます。

ターミナルに表示されているように、プロジェクトフォルダへ移動し、スタート用のコマンドを入力します。

//terminal[][]{
$ cd プロジェクト名
$ npm run start
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

==={sec-03cra-desc} create-react-appで作成された中身

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

//blankline
Node.jsを使うプロジェクトを開始する場合には、プロジェクトフォルダで「npm init」を行うと対話形式で「package.json」を作成しますが、
create-react-appコマンドを使用すると、package.jsonも以下のように作成されます。

//list[][package.json]{
  {
    "name": "作成時に入力したプロジェクト名",
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

package.json内にある「scripts」にあるものがコマンドになります。react-scriptsは、npmスクリプトを連続、
または、並列に実行してくれるものです。

//blankline
package.jsonの「dependencies」には、実行に必要でインストール済みのnpmパッケージが記載されています。
必要なnpmパッケージをインストールすると、ここに自動的に追記されます。

//blankline
また、開発時のみ必要なパッケージ(buildしたときには組み込まれない)は、「devDependencies」に追加されます。

//blankline
以下のように、「create-react-app」で使用されている「Eslint」、「webpack」のバージョンです。

原稿執筆時点(2012年12月12日)では、@<br>{}
 * Eslint 8.4.1
 * webpack 5.65.0
 * TypeScript 4.5.3

 が最新版です。

 最新版を使うのが必ずしも良いとは限りませんが、メジャーバージョンが違うと気になります。


=={sec-04-start}　ゼロから構築してみる

本章では、最新のライブラリを使用してゼロからReact/TypeScriptの環境を構築します。

ステップ毎にGitHub上でブランチを作成してありますので、どこからでも始めていただけます。

==={sec-04-node_init} ステップ1 npm init y

新しくプロジェクト用のフォルダを作成し移動します。

コンソールで「npm init -y」コマンドを実行します。オプションの「-y」なしで実行すると、対話形式で「package.json」を作成できます。

//terminal[npm init -y][nodeプロジェクトの開始]{
  ❯ npm init -y
  Wrote to /Users/yaruo/Documents/yaruo_react_sample/yaruo-start-template/package.json:

  {
    "name": "yaruo-start-template",
    "version": "1.0.0",
    "description": "",
    "main": "index.js",
    "scripts": {
      "test": "echo \"Error: no test specified\" && exit 1"
    },
    "repository": {
      "type": "git",
      "url": "git+https://github.com/yaruo-react-redux/yaruo-start-template.git"
    },
    "keywords": [],
    "author": "",
    "license": "ISC",
    "bugs": {
      "url": "https://github.com/yaruo-react-redux/yaruo-start-template/issues"
    },
    "homepage": "https://github.com/yaruo-react-redux/yaruo-start-template#readme"
  }
//}

作成された「package.json」が表示されます。

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 01_start-node-project https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}


==={sec-04-webpack} webpackのインストールと設定
webpackとは、(@<href>{https://webpack.js.org/, 本家})のトップにある画像が示しているように、@<br>{}
 * JavaScriptファイル
 * CSS(SASS,SCSS)ファイル
 * 画像ファイル

 などをすべてJavaScriptファイルとして扱い、インストールしているライブラリファイルなどもすべて含めて
 1つのファイルとして出力するバンドラー(まとめる)です。

しかし、すべてを1つのファルとするよりも、htmlファイル、cssファイル、画像ファイルをブラウザが並列ダウンロードすると効率がよく表示速度も速くなりため
上図のように、複数ファイルに出力します。

それでは、webpackをインストールし、バンドラーの動きを確認しながら設定ファイルを作成していきます。

ターミナルに以下のコマンドを入力します。「-D」のオプションは、
開発時のみ必要で製品版には含まないライブラリをインストールするときに使います。

「package.json」の「devDependencies」に追記されます。

 * webpack  本体
 * webpack-cli コマンドライン用
 * webpack-dev-server 開発用Webサーバ

をインストールします。

//terminal[webpckのインストール][]{
  ❯ npm install -D webpack webpack-cli webpack-dev-server
  npm WARN deprecated querystring@0.2.0: The querystring API is considered Legacy. new code should use the URLSearchParams API instead.

  added 328 packages, and audited 329 packages in 24s

  42 packages are looking for funding
    run `npm fund` for details

  found 0 vulnerabilities
//}

「package.json」は、以下のようになります。「ーD」オプションを付けたため、「devDependencies」以下に
追記されています。

//list[package.json][]{
  {
    "name": "yaruo-start-template",
    "version": "1.0.0",
    "description": "",
    "main": "index.js",
    "scripts": {
      "test": "echo \"Error: no test specified\" && exit 1"
    },
    "repository": {
      "type": "git",
      "url": "git+https://github.com/yaruo-react-redux/yaruo-start-template.git"
    },
    "keywords": [],
    "author": "",
    "license": "ISC",
    "bugs": {
      "url": "https://github.com/yaruo-react-redux/yaruo-start-template/issues"
    },
    "homepage": "https://github.com/yaruo-react-redux/yaruo-start-template#readme",
    "devDependencies": {
      "webpack": "^5.65.0",
      "webpack-cli": "^4.9.1",
      "webpack-dev-server": "^4.6.0"
    }
  }
//}


==={04-webpack-check} webpackの動作確認

インストールしたwebpackの動作を確認してみます。

//blankline
確認方法は、便利な関数をまとめてある「lodash」ライブラリをインストールし、トップページを作成し動作確認します。

手順は、@<br>{}
//blankline
@<strong>{1. src、distフォルダを作成}@<br>{}
ソースコードを置くフォルダ「src」とｗebpackのデフォルトの出力先フォルダ「dist」を作成します。
@<strong>{2. ファイルを作成}@<br>{}
「lodash」ライブラリをインストールし、srcフォルダに、下記の「index.js」ファイルを作成します。
//terminal[lodashのインストール][]{
 > npm install lodash
//}
//list[src/index.js][]{
  import _ from 'lodash';

  function component() {
    const element = document.createElement('div');
    // Lodash, now imported by this script
    element.innerHTML = _.join(['webpack', '動いてるお〜'], ' ');
    return element;
  }

  document.body.appendChild(component());
//}

@<strong>{3. トップページを作成}
webpackのデフォルトの出力先「dist」フォルダを作成し、「index.html」ファイルを作成します。
//blankline
//list[dist/index.html][]{
  <!DOCTYPE html>
  <html>
    <head>
      <meta charset="utf-8" />
      <title>Getting Started</title>
    </head>
    <body>
      <script src="main.js"></script>
    </body>
  </html>
//}

//blankline

@<strong>{4. 動作を確認}
webpackの動作を確認するために、ターミナルで以下のコマンドを実行します。

npx webpack serve --open --static-directory dist --mode=development

//note[コマンド解説]{
  npx --> /node_modules/.binフォルダにあるファイルを実行@<br>{}
  webpack --> 今回動かすモジュール@<br>{}
  serve --> devServer(開発用サーバ)も起動@<br>{}
  --open --> デフォルトのブラウザで開く@<br>{}
  --static-directory dist --> devServerのDocumentRootを指定@<br>{}
  --mode=development --> 出力モード@<br>{}

「--static-directory dist」を入力しているのは、devServerのデフォルトDocumentRootは「public」のためです。
//}



//terminal[webpackをコマンドで起動][]{
  ❯ npx webpack serve --open --static-directory dist --mode=development
  <i> [webpack-dev-server] Project is running at:
  <i> [webpack-dev-server] Loopback: http://localhost:8080/
  <i> [webpack-dev-server] On Your Network (IPv4): http://192.168.20.101:8080/
  <i> [webpack-dev-server] On Your Network (IPv6): http://[fe80::1]:8080/
  <i> [webpack-dev-server] Content not from webpack is served from 'dist' directory
  <i> [webpack-dev-middleware] wait until bundle finished: /
  asset main.js 836 KiB [emitted] (name: main)
  runtime modules 27.2 KiB 13 modules
  modules by path ./node_modules/ 730 KiB
    modules by path ./node_modules/webpack-dev-server/client/ 52.8 KiB 12 modules
    modules by path ./node_modules/webpack/hot/*.js 4.3 KiB 4 modules
    modules by path ./node_modules/html-entities/lib/*.js 81.3 KiB 4 modules
    modules by path ./node_modules/url/ 37.4 KiB 3 modules
    modules by path ./node_modules/querystring/*.js 4.51 KiB
      ./node_modules/querystring/index.js 127 bytes [built] [code generated]
      ./node_modules/querystring/decode.js 2.34 KiB [built] [code generated]
      ./node_modules/querystring/encode.js 2.04 KiB [built] [code generated]
    ./node_modules/lodash/lodash.js 531 KiB [built] [code generated]
    ./node_modules/ansi-html-community/index.js 4.16 KiB [built] [code generated]
    ./node_modules/events/events.js 14.5 KiB [built] [code generated]
  ./src/index.js 269 bytes [built] [code generated]
  webpack 5.65.0 compiled successfully in 882 ms
//}

「--open」オプションでデフォルトのブラウザが起動し、index.htmlが表示されます。
//image[webpack_test01][ブラウザで表示][scale=1.0]

devToolsで「main.js」を確認すると、node_modulesフォルダ以下にインストールされたJavaScriptが
1つのファイルにまとめられているのが確認できます。
//image[webpack_test02][devToolsでmain.js内を確認][scale=1.0]

npx webpack build

上記コマンドを実行すると、distフォルダ以下にmain.jsファイルが出力されます。

//image[webpack_test03][webpackでビルドしてみた][scale=1.0]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 02_webpack-install https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}

==={04-webpack-config} webpackの設定ファイル
自分でwebpack、devServerを動作させてみると、webpackが何をやっているかを理解しやすくなります。

本章では、webpackの設定ファイル「webpack-config.js」を作成します。

//blankline
手順は、@<br>{}

 1. 「npx webpack-cli init」をターミナルで実行し、ひな型を作成。
 2. 必要なpluginのインストールと設定ファイルへの追加
 3. 不要な設定を削除し、開発時用、製品作成時用でファイルを分ける

 と、なります。

 では、まずは、ターミナルにて上記コマンドを実行すると、
 //blankline
 このコマンドを実行するには、「@webpack-cli/generatorsパッケージが必要ですが、インストールしますか？」と
 聞かれますので、エンターキーを押します。

 //blankline
 @webpack-cli/generatorsと依存関係をもつパッケージがインストールされると、設定ファイルを作成するための質問が始まります。
 私が選んだ答えと括弧内は表示される選択肢です。
//blankline
 * どのタイプのJSを使いますか？　--> TypeScript(none, ES6)
 * devServerを使いますか？ --> Yes
 * バンドル用のHTMLファイルを作成しますか？ --> Yes
 * PWAサポートが必要ですか？ --> No
 * CSSは、どのタイプを使いますか？ --> SASS(none, CSS only, LESS, Stylus)
 * SASSと一緒にCSSスタイルも使いますか？　--> Yes
 * PostCSS(Node.js製のCSSを作るためのフレームワーク)を使いますか？ --> No
 * ファイル毎にCSSを別にしますか？ --> Yes
 * 設定ファイルをフォーマットするのにPrettierをインストールしますか？　--> Yes
 * パッケージマネージャーを選択してください。 --> npm
 * package.jsonがすでにありますが上書きしても良いですか？ --> No
 * README.mdがすでにありますが上書きしても良いですか？ --> No


//terminal[webpack-config.jsの作成][]{
   ❯ npx webpack-cli init
  [webpack-cli] For using this command you need to install: '@webpack-cli/generators' package.
  [webpack-cli] Would you like to install '@webpack-cli/generators' package? (That will run 'npm install -D @webpack-cli/generators') (Y/n)
  npm WARN deprecated urix@0.1.0: Please see https://github.com/lydell/urix#deprecated
  npm WARN deprecated resolve-url@0.2.1: https://github.com/lydell/resolve-url#deprecated

  added 370 packages, and audited 699 packages in 22s

  58 packages are looking for funding
    run `npm fund` for details

  9 vulnerabilities (4 moderate, 5 high)

  To address all issues (including breaking changes), run:
    npm audit fix --force

  Run `npm audit` for details.
  ? Which of the following JS solutions do you want to use? Typescript
  ? Do you want to use webpack-dev-server? Yes
  ? Do you want to simplify the creation of HTML files for your bundle? Yes
  ? Do you want to add PWA support? No
  ? Which of the following CSS solutions do you want to use? SASS
  ? Will you be using CSS styles along with SASS in your project? Yes
  ? Will you be using PostCSS in your project? No
  ? Do you want to extract CSS for every file? Yes
  ? Do you like to install prettier to format generated configuration? Yes
  ? Pick a package manager: npm
  [webpack-cli] ℹ INFO  Initialising project...
   conflict package.json
  ? Overwrite package.json? do not overwrite
       skip package.json
     create src/index.ts
   conflict README.md
  ? Overwrite README.md? do not overwrite
       skip README.md
     create index.html
     create webpack.config.js
     create tsconfig.json

  added 65 packages, and audited 764 packages in 9s

  73 packages are looking for funding
    run `npm fund` for details

  9 vulnerabilities (4 moderate, 5 high)

  To address all issues (including breaking changes), run:
    npm audit fix --force

  Run `npm audit` for details.
//}

質問完了後に必要なパッケージがインストールされ、「webpack.config.js」が作成されます。
また、TypeScript用に「tsconfig.json」も作成されますが、後で作成しますので削除します。

作成された「webpack.config.js」を以下のように編集します。
#@#<!-- textlint-disable -->
 * entry: "./src/index.ts"を"./src/index.js"へ
 * output: path: path.resolve(__dirname, "public")へ
 * distフォルダを削除し、publicフォルダを作成
#@#<!-- textlint-enable -->
//list[webpack.config.js][]{
  // Generated using webpack-cli https://github.com/webpack/webpack-cli

  const path = require("path");
  const HtmlWebpackPlugin = require("html-webpack-plugin");
  const MiniCssExtractPlugin = require("mini-css-extract-plugin");

  const isProduction = process.env.NODE_ENV == "production";

  const stylesHandler = MiniCssExtractPlugin.loader;

  const config = {
    entry: "./src/index.js", @<balloon>{TypeScript導入までは、拡張子jsで}　
    output: {
      path: path.resolve(__dirname, "public"), @<balloon>{出力フォルダをpublicへ}
    },
    devServer: {
      open: true,
      host: "localhost",
    },
    plugins: [
      new HtmlWebpackPlugin({
        template: "index.html",
      }),

      new MiniCssExtractPlugin(),

      // Add your plugins here
      // Learn more about plugins from https://webpack.js.org/configuration/plugins/
    ],
    module: {
      rules: [
        {
          test: /\.(ts|tsx)$/i,
          loader: "ts-loader",
          exclude: ["/node_modules/"],
        },
        {
          test: /\.css$/i,
          use: [stylesHandler, "css-loader"],
        },
        {
          test: /\.s[ac]ss$/i,
          use: [stylesHandler, "css-loader", "sass-loader"],
        },
        {
          test: /\.(eot|svg|ttf|woff|woff2|png|jpg|gif)$/i,
          type: "asset",
        },

        // Add your rules for custom modules here
        // Learn more about loaders from https://webpack.js.org/loaders/
      ],
    },
    resolve: {
      extensions: [".tsx", ".ts", ".js"],
    },
  };

  module.exports = () => {
    if (isProduction) {
      config.mode = "production";
    } else {
      config.mode = "development";
    }
    return config;
  };

//}

@<strong>{プラグインのインストール}

//blankline
追加で、以下のプラグイン、ローダも追加します。

 * uglify-js 製品版出力時にconsole関数を除去
 * terser-webpack-plugin 上記をwebpackで使用する場合必要
 * css-minimizer-webpack-plugin CSSをminimize
 * webpack-merge 複数のwebpack-configファイルをマージする

 ターミナルで以下のコマンドを実行します。
 //terminal[追加プラグイン、ローダのインストール][]{
  npm install -D uglify-js terser-webpack-plugin css-minimizer-webpack-plugin webpack-merge
 //}

 追加のプラグイン、ローダの設定を追加したwebpack.config.jsです。devServerでページを表示する際に、
 デフォルトのブラウザではなくdevToolsの強力な「Google Chrome」を使うようにしました。

//blankline
ただし、OS毎にChromeのアプリケーション名が違うためOSを取得し対応した「Chrome名」に変換しています。
「create-react-app」だと、結構複雑なことをやっています。

興味のある方は、「create-react-app」を使ってプロジェクト作成し、react-scriptsを追うとお勉強になります。

//list[webpack.config.js][]{
  // Generated using webpack-cli https://github.com/webpack/webpack-cli
  const path = require('path');
  const HtmlWebpackPlugin = require('html-webpack-plugin');
  const MiniCssExtractPlugin = require('mini-css-extract-plugin');
  const TerserPlugin = require('terser-webpack-plugin');
  const CssMinimizerPlugin = require('css-minimizer-webpack-plugin');
  const os = require('os');

  const isProduction = process.env.NODE_ENV == 'production';

  const stylesHandler = MiniCssExtractPlugin.loader;

  let devBrowser = 'Google Chrome';
  switch (os.platform()) {
    case 'win32':
      devBrowser = 'chrome';
      break;
    case 'linux':
      devBrowser = 'google-chrome';
    default:
      break;
  }

  const config = {
    entry: './src/index.js',
    output: {
      path: path.resolve(__dirname, 'public'),
      assetModuleFilename: 'images/[name][ext][query]',
      clean: true,
    },
    plugins: [
      new HtmlWebpackPlugin({
        template: 'index.html',
      }),

      new MiniCssExtractPlugin(),

      // Add your plugins here
      // Learn more about plugins from https://webpack.js.org/configuration/plugins/
      new CssMinimizerPlugin(),
    ],
    module: {
      rules: [
        {
          test: /\.(ts|tsx)$/i,
          loader: 'ts-loader',
          exclude: ['/node_modules/'],
        },
        {
          test: /\.css$/i,
          use: [stylesHandler, 'css-loader'],
        },
        {
          test: /\.s[ac]ss$/i,
          use: [stylesHandler, 'css-loader', 'sass-loader'],
        },
        {
          test: /\.(eot|svg|ttf|woff|woff2|png|jpg|gif)$/i,
          type: 'asset',
        },

        // Add your rules for custom modules here
        // Learn more about loaders from https://webpack.js.org/loaders/
      ],
    },
    resolve: {
      extensions: ['.tsx', '.ts', '.js'],
    },
    optimization: {
      minimize: true,
      minimizer: [
        new TerserPlugin({
          minify: TerserPlugin.uglifyJsMinify,
          terserOptions: {
            compress: {
              drop_console: true,
            },
          },
        }),
        new CssMinimizerPlugin(),
      ],
    },
    devtool: 'eval-source-map',
    devServer: {
      open: {
        app: {
          name: devBrowser,
        },
      },
      host: 'localhost',
      port: 3000,
      static: './public',
    },
  };

  module.exports = () => {
    if (isProduction) {
      config.mode = 'production';
    } else {
      config.mode = 'development';
    }
    return config;
  };

//}

動作確認のために「index.js」を書き換えます。いつの間にかプロジェクトフォルダ直下に「index.html」も
作成されています。

「index.js」に、動作確認用に追加するスタイル指定用の「sytle.css」、「style.scss」も追加します。

適当な画像ファイルを用意し、「src/assets/images」フォルダを作成し追加します。

「package.json」に、スクリプトを追加します。

//list[package.json][]{
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "build": "webpack --mode=production",
    "build:dev": "webpack --mode=development",
    "build:prod": "webpack --mode=production",
    "start": "webpack serve"
  },
//}

まずは、ファイルを出力しないでブラウザで表示します。

//terminal[ブラウザで表示][]{
 > npm run start
//}

「div」要素の背景、文字色も「style.css」、「style.scss」から作成された「main.css」から反映されています。
また、「index.html」には、作成された「main.js」、「main.css」を読み込む部分はありませんが、
webpackが「HtmlWebpackPlugin」で自動で読込部分が追加されています。

//image[webpack_test04][desc][scale=1.0]


次にプロダクション用にビルドしてみます。

//terminal[ビルド][]{
　> npm run build
//}

下図のように、@<br>{}
 * index.html
 * main.js
 * main.css
 * images/画像ファイル

が出力されていますので、ファイル開き内容を確認してください。

//image[webpack_test05][][scale=1.0]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 03_setup-webpack-config-file https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}



====={sec-04-webpack-config-all} webpack設定ファイルを分割する
問題なく動作した「webpack.config.js」ですが、今後の運用を考え「開発用」、「プロダクション用」、「共通分」に切り分けます。
devServer関連はプロダクションには関係ありませんし、minimizer関連は開発時には邪魔です。

@<href>{https://webpack.js.org/guides/production/, 本家でも推奨}されています。

「webpack.config.js」を以下のよう分割し、共用部分は「webpack-merge」を使用して統合します。

 * 共用 webpack.common.js
 * 開発用 webpack.dev.js
 * プロダクション用 webpack.prod.js

 開発用はdevServer関係、プロダクション用はminimizer関係、それ以外は共用として分けていきます。

まずは、統合に必要な「webpack-merge」をインストールします。

//terminal[webpack-mergeのインストール][]{
 > npm install -D webpack-merge
//}


「webpack.dev.js」を作成し、「webpack.config.js」全体を貼り付けdevServer、debtoolを
残し、「module」はCSS関係のみで「style-loader」を使うように変更します。


また、「mode:'development'」を追加します。

//list[webpack.dev.js][]{
  const { merge } = require('webpack-merge');
  const common = require('./webpack.common');
  const os = require('os');

  let devBrowser = 'Google Chrome';
  switch (os.platform()) {
    case 'win32':
      devBrowser = 'chrome';
      break;
    case 'linux':
      devBrowser = 'google-chrome';
      break;
    default:
      break;
  }

  module.exports = merge(common, {
    mode: 'development',
    module: {
      rules: [
        {
          test: /\.css$/i,
          use: ['style-loader', 'css-loader'],
        },
        {
          test: /\.s[ac]ss$/i,
          use: ['style-loader', 'css-loader', 'sass-loader'],
        },
      ],
    },
    devtool: 'eval-source-map',
    devServer: {
      open: {
        app: {
          name: devBrowser,
        },
      },
      host: 'localhost',
      port: 3000,
      static: './public',
    },
  });

//}

プロダクション用も、「webpack.config.js」全体を貼り付け、CssMinimizer関連を中心に「module」はCSSの抽出のままで
不要な部分を削除します。

こちらは、「mode:'production'」を追加します。

//list[webpack.prod.js][]{
  const { merge } = require('webpack-merge');
  const common = require('./webpack.common');
  const MiniCssExtractPlugin = require('mini-css-extract-plugin');
  const TerserPlugin = require('terser-webpack-plugin');
  const CssMinimizerPlugin = require('css-minimizer-webpack-plugin');

  module.exports = merge(common, {
    mode: 'production',
    plugins: [new MiniCssExtractPlugin(), new CssMinimizerPlugin()],
    module: {
      rules: [
        {
          test: /\.css$/i,
          use: [MiniCssExtractPlugin.loader, 'css-loader'],
        },
        {
          test: /\.s[ac]ss$/i,
          use: [MiniCssExtractPlugin.loader, 'css-loader', 'sass-loader'],
        },
      ],
    },
    resolve: {
      extensions: ['.tsx', '.ts', '.js'],
    },
    optimization: {
      minimize: true,
      minimizer: [
        new TerserPlugin({
          minify: TerserPlugin.uglifyJsMinify,
          terserOptions: {
            compress: {
              drop_console: true,
            },
          },
        }),
        new CssMinimizerPlugin(),
      ],
    },
  });
//}

共通部分も、「webpack.config.js」全体を貼り付け、上記ファイルにあるものを削除します。

//list[webpack.common.js][]{
  const path = require('path');
  const HtmlWebpackPlugin = require('html-webpack-plugin');

  module.exports = {
    entry: './src/index.js',
    output: {
      path: path.resolve(__dirname, 'public'),
      assetModuleFilename: 'images/[name][ext][query]',
      clean: true,
    },
    plugins: [
      new HtmlWebpackPlugin({
        template: 'index.html',
      }),
    ],
    module: {
      rules: [
        {
          test: /\.(ts|tsx)$/i,
          loader: 'ts-loader',
          exclude: ['/node_modules/'],
        },
        {
          test: /\.(eot|svg|ttf|woff|woff2|png|jpg|gif)$/i,
          type: 'asset',
        },
      ],
    },
    resolve: {
      extensions: ['.tsx', '.ts', '.js'],
    },
  };

//}


webpackの設定ファイル名がデフォルトから変更になったので、「package.json」のスクリプト部分を変更します。

//list[package.json][]{
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "build": "webpack --config webpack.prod.js",
    "build:dev": "webpack --config webpack.dev.js",
    "build:prod": "webpack --config webpack.prod.js",
    "start": "webpack serve --config webpack.dev.js"
  },
//}

ターミナル上で、「npm run start」、「npm run build」で動作確認を行います。

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 04_webpack-config-split https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}


=={sec-03lint} eslint、prettierとは？

「lint」は、C言語用のコンパイラよりも詳細で厳密なチェックを行うプログラムです。
コンパイル前にコードをチェックするために使われます。

//blankline
それが、いつしかコードをチェック・解析することを「lint」、lintを行うプログラムをlinterと呼ぶようになったそうです。

//blankline
JavaScript(ECMAScript)用のlinterが、「eslint」になります。もちろん、Java、HTML、Pythonなどにもlinterがあります。

//blankline
「eslint」は、設定ファイルで指定されたルールと違うコードの書き方をしている部分を指摘してくれます。
その指定されたルールとは、たいていの場合にはJavaScriptに詳しい人達が決めたもので、良く使われるものは、かの有名なAirBnBの開発チームのものです。
もちろん、ルールは改変・追加もできます。

//blankline
チェックしてくれるのは、たとえば、@<br>{}

 * constで宣言している変数への代入
 * 未定義の変数やモジュールの使用
 * 分割代入の使用を推奨

//blankline
などがありますが、何をチェックし指摘するのかは、チーム毎、プロジェクト毎に自由に決めることができます。

//blankline
「prettier」は、コードを整形(インデント、改行など)してくれるツールです。
実は、eslintでもコード整形はできるのですが、コード整形はprettierの方が優れいます。

//blankline
そのために、@<br>{}

 * コードチェックは、eslint
 * コード整形は、prettier

//blankline
と、得意なものに任せます。

==={sec-03eslint} eslint、prettierのインストール

===={sec-03eslint-install} eslintのパッケージ追加と設定
create-react-appを使用して作成したスタートアッププロジェクトには、eslintは導入済みですので設定し直し、必要な関連パッケージをインストールします。

ターミナルに以下のように「eslint --init」と初期化コマンドを入力します。
//terminal[][eslintの初期化]{
$ npx eslint --init
//}

「?」が行頭にある質問と選択枝が表示されますので、カーソルキーで選択枝を選びエンターキーで次ぎの質問に移ります。
//terminal[][eslintの質問に答える]{
  ? How would you like to use ESLint? …
    To check syntax only　　　　　　　　　　　　
  > To check syntax and find problems    @<balloon>{選択したものに　＞ が表示される}
    To check syntax, find problems, and enforce code style
//}

最後の質問に答えると必要なパッケージをインストールするか尋ねられますので「Yes」と答えてます。
//terminal[][eslintへの答え]{
  ✔ How would you like to use ESLint? · problems
  ✔ What type of modules does your project use? · esm
  ✔ Which framework does your project use? · react
  ✔ Does your project use TypeScript? · No / Yes　　　　@<balloon>{Yesを選択}
  ✔ Where does your code run? · browser
  ✔ What format do you want your config file to be in? · JavaScript
  Local ESLint installation not found.
  The config that you've selected requires the following dependencies:

  eslint-plugin-react@latest @typescript-eslint/eslint-plugin@latest @typescript-eslint/parser@latest eslint@latest
  ✔ Would you like to install them now with npm? · No / Yes  @<balloon>{Yesを選択}
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
      "extends": [
        "eslint:recommended"
        "plugin:react/recommended",
        "plugin:@typescript-eslint/recommended",
      ],
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

設定ファイル「.eslintrc.js」で、どのようなルールが適用されるのかを確認します。
適用されるルールが、「current_rules.txt」に書き出されます。

//blankline
書き出されたルールは、ルール名に適用方法{"off(適用しない)","warn(警告)","error(エラー)"}が記されています。
表記は、{0,1,2}の数字で表示される場合もあります。
同じルールがあった場合には、後から読み込まれたものが上書きされます。
個別に上書きしたいものは「.eslintrc.js」ファイルの「rules」セクションに追加します。

//terminal[][eslint設定で適用されるルール]{
$ npx eslint --print-config .eslintrc.js > current_rules.txt
//}


eslintで使用するルールは一般的なものをベースにしたいので、airbnbのルールをインストールします。
//terminal[][airbnbのルーツのインストール]{
 $  npx install-peerdeps --dev eslint-config-airbnb
    install-peerdeps v3.0.3
    It seems as if you are using Yarn.
    Would you like to use Yarn for the installation? (y/n) n@<balloon>{yarnを使っているのか聞かれるので、noである「n」を入力}
//}

airbnbのルールをインストールしたので、設定ファイルに追加します。
//list[][.eslintrc.jsへairbnbルールを適用]{
  "extends": [
      "eslint:recommended",
      "plugin:react/recommended",
      "airbnb",  　　　@<balloon>{airbnbのルール}
      "airbnb/hooks", @<balloon>{airbnbのReact hooksのルール}
      "plugin:@typescript-eslint/recommended",
  ],
//}

再度、ルールを出力すると適用されるルールがずいぶん増えているのが分かります。
@<br>{}
@<br>{}
次に、TypeScriptもチェックできるようにルールを追加します。「plugin:」の下3行を追加しました。
//list[][.eslintrc.jsのextends部分]{
  "extends": [
      "eslint:recommended",
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
//list[][.eslintrc.jsのparserOptions部分]{
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

これでルールの適用は完了しましたが、都合の悪いルールには設定ファイルでルールの上書をします。

「import/extensions」は、インポート宣言でnode_modules以下にあるパッケージからは拡張子が不要(import aaa from 'aaa')
で、相対パスからのimportは、拡張子が必要と言うルールです。

現在はすべてがエラー、node_modules下のパッケージ内の指定された拡張子は除外となっていますが、
node_modules下以外でも{js,jsx,ts,tsx}は除外したいのでルールを追加します。
//list[][import/extensionsの現時点]{
  "import/extensions": [
    "error",
    "ignorePackages",
    {
      "js": "never",
      "mjs": "never",
      "jsx": "never"
    }
  ],
//}

「react/jsx-filename-extension」は、JSXを含むファイルの拡張子を制限するルールです。

現時点では、拡張子「.jsx」に制限されていますが、拡張子「.tsx」も追加したいのでルールに追加します。
//list[][react/jsx-filename-extentionの現時点]{
  "react/jsx-filename-extension": [
    "error",
    {
      "extensions": [
        ".jsx"
      ]
    }
  ],
//}

「react/react-in-jsx-scope」は、JSXファイルに「import React from 'react'」がない場合にはエラーにしてくれるのですが
React17からは、「import React from 'react'」を書かなくてもよくなりました。そのため、このルールをOFFにします。
//list[][react/react-in-jsx-scope]{
  "react/react-in-jsx-scope": [
    "error"
  ],
//}

「react/function-component-definition」は、関数コンポーネントに特定の関数タイプを強制します。
現時点では、functionの使用を強制されるので、アロー関数強制に変更します。
//list[][react/function-component-definitionの現在]{
  "react/function-component-definition": [
    "error",
    {
      "namedComponents": "function-expression",
      "unnamedComponents": "function-expression"
    }
  ],
//}


上書きしたいルールを、「.eslintrc.js」へ追加します。
//list[][.eslintrc.jsのrulesへ追加]{
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
        "react/function-component-definition": [
          "error",
          {
            namedComponents: "arrow-function",
            unnamedComponents: "arrow-function",
          },
        ],
  }
//}

===={sec-03prettier} Prettierのインストールと設定

ここからは、Prettierのインストールと設定をします。
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

Pretterのチェックを「.eslintrc.js」へ追加します。
//list[][.eslintrc.js]{
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
    "singleQuote": true,
    "jsxSingleQuote": true
  }
//}

eslintとprettierが衝突すると検出・修正ループに入りますので、チェックします。
//terminal[][eslint、prettierの衝突検出]{
  $ npx eslint-config-prettier 'src/**/*.{js,jsx,ts,tsx}'
    No rules that are unnecessary or conflict with Prettier were found.
//}

無事に衝突なしとなりました。

package.jsonにスクリプトコマンドを追加します。
//list[][package.json]{
"scripts": {
  "start": "react-scripts start",
  "build": "react-scripts build",
  "test": "react-scripts test",
  "lint": "eslint 'src/**/*.{js,jsx,ts,tsx}'", @<balloon>{lint:チェック}
  "fix": "npm run format && npm run lint:fix", @<balloon>{fix:整形してチェックして自動修復}
  "format": "prettier --write 'src/**/*.{js,jsx,ts,tsx}'", @<balloon>{format:整形}
  "lint:fix": "eslint --fix 'src/**/*.{js,jsx,ts,tsx}'",  @<balloon>{lint:fixチェック後修復}
  "eject": "react-scripts eject"
},
//}

Eslint、Prettierの設定が完了しましたので、srcフォルダにある「App.tsx」を開いてみると、
ルールから外れるものは指摘されています。

//image[032_app_tsx_error][Eslint、Prettierに怒られてます][scale=1.0,pos=H]

=={sec-04fix} eslint、prettierの指摘を修正
ESlint、Prettierは指摘するだけではなく、修正案の提示・修正(できるものだけですが...)までしてくれます。

//blankline
VSCodeにPrettier拡張機能を追加してあれば、
以下のように、VSCode側で設定すると、ファイルを保存する度に自動で修正をいれることもできます。

//blankline
私は、修正を自分のタイミングで行いたいのでVSCode側の設定は行っていません。

//blankline
もし、VSCode側の設定をする場合には、VSCodeで@<br>{}
[File]->[Preferences]->[Settings]にて、以下の各項目を検索して設定するか、settings.jsonへ追加するか、
このプロジェクトのみ適用の場合は、プロジェクトフォルダ直下に「.vscode」フォルダを作成し、「settings.json」ファイルへ書き込みます。

ユーザー設定ファイルの内容が、この設定で上書きされます。

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

//blankline
ものを修正します。

//blankline
まずは、.eslintrc.js自体に問題があるようです。

赤波線の上にマウスポンタを置くとeslintのコード、この場合は「no-use-before-define」が表示されます。、
さらに、「コマンドキー(Windowsでは、ctrl)　+ ピリオド」を押すと、修正方法が提示されます。

//image[031_eslint_error][.eslintrc.jsの指摘][scale=1.0]

.eslintrc.jsファイルでの指摘は、「es6モジュールの書き方へ移行しろ！」とのことです。
以下のように、.eslintrc.jsを変更します。

//list[][.eslintrc.js]{
  const config = {
      "env": {
          "browser": true,
          "es2021": true
      },
      "extends": [
          "eslint:recommended",
          "plugin:react/recommended",
          "airbnb",
          "airbnb/hooks",
          "plugin:@typescript-eslint/recommended",
          "plugin:@typescript-eslint/recommended-requiring-type-checking",
          "plugin:import/recommended",
          "plugin:import/typescript",
          "prettier",
      ],
      "parser": "@typescript-eslint/parser",
      "parserOptions": {
          "ecmaFeatures": {
              "jsx": true
          },
          "ecmaVersion": 12,
          "sourceType": "module",
          "tsconfigRootDir": __dirname,
          "project": ["./tsconfig.json"],
      },
      "plugins": [
          "react",
          "@typescript-eslint"
      ],
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
            "react/function-component-definition": [
              "error",
              {
                namedComponents: "arrow-function",
                unnamedComponents: "arrow-function",
              },
            ],
      }
  };

  export default config

//}

このように修正して保存すると、次の指摘がきます。
//quote{
  Parsing error: "parserOptions.project" has been set for @typescript-eslint/parser.
  The file does not match your project config: .eslintrc.js.
  The file must be included in at least one of the projects provided.
//}

これは、ファイルが「どこからもimportされていない」場合に表示されるエラーです。
「.eslintrc.js」は、ESLintの設定ファイルですので、どこからもインポートされていません。

//blankline
解消法は、「npx elsint --init」でファイルを作成した際に「.eslitrc」ファイルをjson形式、
または、yaml(yml)形式で作成を選択するか、.eslintrc.jsファイル自体をチェックの対象から除外します。

//blankline
今回は、JavaScript形式で作成したのでチェック除外のための、「.eslintignore」ファイルをプロジェクトフォルダ直下に作成し、
lint.jsやconfig.jsのパターンが含まれるファイル、パッケージがインストールされるnode_modulesフォルダなどを除外するように指定します。

//list[][.eslintignore]{
  build/
  public/
  **/node_modules/
  *.config.js
  .*lintrc.js
//}

これで、.eslintrc.jsについては怒られなくなりました。

次に、App.tsxファイルを修正します。


//image[032_app_tsx_error][App.tsxの修正][scale=1.0,pos=H]


//note[]{
  筆者がVSCodeを日本語化していないのは、エラーメッセージでググる場合を考えてのことです。
  英語でのエラーメッセージの方が的確なページをみつけやすいと考えています。
//}

では、指摘されている点を修正していきます。

「react/function-component-definition」は、関数コンポーネントに一貫した関数タイプを適用しなさいと怒られています。

関数をアロー関数に直し、関数型の宣言も追加します。

//list[][App.tsx]{
  // React17からは、JSXでReactのインポートが不要になりましたので、以下の行を削除します。
  import React from 'react';
//}


//list[][App.tsx]{
  import { VFC } from 'react';
  import logo from './logo.svg';
  import './App.css';

  const App: VFC = () => (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.tsx</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );

  export default App;
//}

これで現時点での指摘はすべて修正できました。

//image[06_eslint_prettier_fixdoneAll][すべての問題の修正完了][scale=1.0,pos=H]

=={sec-chap02review} 第2章のまとめ
Reactを使用したアプリケーションは、スタートアップ用のアプリケーションがコマンド一発でインストールできます。

//blankline
バグの混入を防いだりより良いコーディングをするためにも、ESlint、Prettierを導入しましょう。

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
  $ > git clone -b 02_eslint_prettier https://github.com/yaruo-react-redux/yaruo-diary.git
//}
#@#<!-- textlint-enable -->
//}
