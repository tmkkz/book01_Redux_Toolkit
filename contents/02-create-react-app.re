= スタートプロジェクトの作成

//abstract{
Reactアプリケーションを作成するための最初のステップとして、トップページのみを持つスタートアッププロジェクトを作成します。
　@<br>{}

スタートアッププロジェクトを作成する方法として、@<br>{}
　@<br>{}
  1. create-react-app@<br>{}
  2. ゼロから構築@<br>{}
　@<br>{}
の2つの方法を解説します。

　@<br>{}
「create-react-app」は、コマンド一発でReactアプリケーション開発が数分で始められます。

　@<br>{}
ただし、Facebook(Meta社)を中心に開発されている便利なものなのですが、メンドウな設定などが隠されているため
バージョンの合わないライブラリを導入すると整合性が崩れ手に負えなくなることもあります。

　@<br>{}
2021年12月14日にリリースされた「create-react-app V5.0.0」では、webpack、eslintなどは最新のものが使われています。

　@<br>{}
「ゼロから構築」を選択すると、最新のライブラリが使用できますが、webpack、ESLintなどの設定ファイルは自分で書かなくてはなりません。
使用するライブラリの設定自体は難しくないので、ここで勉強しておけば必ず役に立つはずです。

　@<br>{}
　どちらの方法もGitHubにテンプレートとしてアップロードしてありますので、ご自由にお使いください。

//}

=={sec-01command} create-react-appコマンド
#@#<!-- textlint-disable -->
Reactアプリケーションをゼロから作成するためには、
#@#<!-- textlint-enable -->

 * 「nodeプロジェクト」に必要なpackage.jsonを作成
 * reactなど必要なライブラリのインストール
 * 作成したアプリケーションが、古いブラウザでも実行できるようにコードを変換(Babel使用)
 * 出力するファイルをまとめる(バンドルする - webpack使用)

など、reactライブラリのインストール以外にも、Babelやwebpackをインストールして設定ファイルを作成しなくてはなりません。

//blankline
また、使用するライブラリによっては、プラグインのインストールや設定など、アプリケーションのコードを書き始める前の作業がたいへんです。

//blankline
しかし、「そんなメンドウなことは、やってられない。」と誰しもが思ったか、
すぐにでもコードを書き始めることのできるスタート用アプリケーションが、react開発元のFacebook(Meta)から提供されています。

//blankline
さらに、そのスタート用アプリケーションは、コマンド一発でインストールできます。

//image[oneCommand][][scale=0.7,pos=H]

では、実際に手を動かしましょう。
ターミナルを起動し、プロジェクトを作成するフォルダへ移動します。

//terminal[][create-react-appでスタート用アプリケーション作成]{
> npx create react-app プロジェクト名 --template typescript
//}

エンターキーを押すと、作業が始まり「プロジェクト名」のフォルダが作成され、
以下のように表示されればスグにでも開発に取りかかれます。

//image[cra-options][][scale=0.7,pos=H]


//terminal[][create-react-app完了時]{
  Success! Created yaruo-cra-template at /Users/yaruo/yaruo-cra-template
  Inside that directory, you can run several commands:

    npm start
      Starts the development server.

    npm run build
      Bundles the app into static files for production.

    npm test
      Starts the test runner.

    npm run eject
      Removes this tool and copies build dependencies, configuration files
      and scripts into the app directory. If you do this, you can’t go back!

  We suggest that you begin by typing:

    cd yaruo-cra-template
    npm start

  Happy hacking!
//}

//quote{
  「create-react-app」は、2021年12月14日にV5.0.0がリリースされました。
  このリリースでは、メジャーバージョンアップされていた「webpack5」、「eslint8」が採用されています。
//}


//note[github]{
  ここまでの作業は、GitHubにあります。
#@#<!-- textlint-disable -->
//terminal[][GitHubから]{
> git clone -b 01_create-react-app-executed https://github.com/yaruo-react-redux/yaruo-cra-template.git
//}
#@#<!-- textlit-enable -->
//}

==={sec-02yarnstart} アプリケーションを実行
アプリケーションが作成できましたので、実行してみます。
ターミナルの表示に従い、プロジェクトフォルダへ移動し、スタート用のコマンドを入力します。

//terminal[][プロジェクトの実行]{
 > cd プロジェクト名
 > npm run start @<balloon>{もしくは、yarn start}
//}

すると、webpackに同梱されている開発用のweb serverが起動し、デフォルトでは、port:3000でアプリケーションへアクセスできます。

//terminal[][npm run start時]{
Compiled successfully!

You can now view yourproject in the browser.

  Local:            http://localhost:3000
  On Your Network:  http://pcのローカルIPアドレス:3000

Note that the development build is not optimized.
To create a production build, use yarn build.
//}

Google Chromeが起動し、http://localhost:3000へアクセスし以下のページが表示されます。

//image[ok][][scale=0.5,pos=H]

//image[02_cra_start][create-react-appの画面][scale=0.9,pos=H]

このページが表示されれば成功です。

//clearpage

==={sec-03cra-desc} create-react-appで作成された中身

create-react-appで作成された中身は、以下となります(使用するテンプレートにより作成されるファイル・フォルダは異なる)。

//image[noMatter][][scale=0.7,pos=H]

//terminal[][create-react-appで作成されたファイル・フォルダ]{
  .
  ├── node_modules
  ├── README.md
  ├── package-lock.json
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
  └── tsconfig.json
//}

package.jsonファイルは、Node.jsを使用するプロジェクトの設計図にあたるものです。

//blankline
Node.jsを使うプロジェクトを開始する場合には、プロジェクトフォルダで「npm init」を行うと対話形式で「package.json」を作成しますが、
create-react-appコマンドを使用すると、package.jsonも以下のように作成されます。

//clearpage
//list[][package.json]{
  {
    "name": "作成時に入力したプロジェクト名",
    "version": "0.1.0",
    "private": true,
    "dependencies": {
      "@testing-library/jest-dom": "^5.16.1",
      "@testing-library/react": "^12.1.2",
      "@testing-library/user-event": "^13.5.0",
      "@types/jest": "^27.0.3",
      "@types/node": "^16.11.14",
      "@types/react": "^17.0.37",
      "@types/react-dom": "^17.0.11",
      "react": "^17.0.2",
      "react-dom": "^17.0.2",
      "react-scripts": "5.0.0",
      "typescript": "^4.5.4",
      "web-vitals": "^2.1.2"
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

package.json内にある「scripts」にあるものがコマンドになります。

//blankline
package.jsonの「dependencies」には、実行に必要でインストール済みのnpmパッケージが記載されています。
必要なnpmパッケージをインストールすると、ここに自動的に追記されます。

//blankline
また、開発時のみ必要なパッケージ(buildしたときには組み込まれない)は、「devDependencies」に追加されます。

//image[buildFile][][scale=1.0,pos=H]

=={sec-04-start}　ゼロから構築してみる

本章では、最新のライブラリを使用してゼロからReact/TypeScriptの環境を構築します。

//blankline
ステップ毎にGitHub上でブランチを作成してありますので、どこからでも始めていただけます。

//image[fromScratch][][scale=0.4,pos=H]


==={sec-04-node_init} ステップ1 Node.jsプロジェクト作成

新しくプロジェクト用のフォルダを作成し移動します。

コンソールで「npm init -y」コマンドを実行します。オプションの「-y」なしで実行すると、対話形式で「package.json」を作成できます。

//terminal[][nodeプロジェクトの開始]{
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
//image[02_webpack_site][desc][scale=1.0]
#@#<!-- textlint-disable -->
webpackとは、(@<href>{https://webpack.js.org/, 本家})のトップにある上図が示しているように、
#@#<!-- textlint-enable -->

 * JavaScriptファイル
 * CSS(SASS,SCSS)ファイル
 * 画像ファイル

 などをすべてJavaScriptファイルとして扱い、インストールしているライブラリファイルなどもすべて含めて
 1つのファイルとして出力するバンドラー(まとめる)です。

//image[bandle][][scale=0.7,pos=H]

//blankline
しかし、すべてを1つのファルとするよりも「htmlファイル」、「cssファイル」、画像ファイルを別ファイルとして出力し、
ブラウザがファイルを並列にダウンロードできると効率がよくなり、表示速度も速くなります。
そのため、上図のように、複数ファイルに出力します。

//blankline
それでは、webpackをインストールし、バンドラーの動きを確認しながら設定ファイルを作成していきます。

//blankline
ターミナルに以下のコマンドを入力します。「-D(または、--save-dev)」のオプションは、
開発時のみ必要で製品版には含まないライブラリをインストールするときに使います。

//blankline
インストールすると、「package.json」の「devDependencies」に追記されます。

 * webpack  本体
 * webpack-cli コマンドライン用
 * webpack-dev-server 開発用Webサーバ

//terminal[][webpckのインストール]{
  ❯ npm install -D webpack webpack-cli webpack-dev-server
  npm WARN deprecated querystring@0.2.0: The querystring API is considered Legacy. new code should use the URLSearchParams API instead.

  added 328 packages, and audited 329 packages in 24s

  42 packages are looking for funding
    run `npm fund` for details

  found 0 vulnerabilities
//}

「package.json」は、以下のようになります。「ーD」オプションを付けたため、「devDependencies」以下に
追記されています。

//list[][package.json]{
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

//image[pray][][scale=0.6,pos=H]

//blankline
確認方法は、便利な関数をまとめてある「lodash」ライブラリをインストールし、トップページを作成し動作確認します。

//blankline
手順は、@<br>{}
@<strong>{1. src、distフォルダを作成}@<br>{}
ソースコードを置くフォルダ「src」とｗebpackのデフォルトの出力先フォルダ「dist」を作成します。

//blankline
@<strong>{2. ファイルを作成}@<br>{}
「lodash」ライブラリをインストールし、srcフォルダに、下記の「index.js」ファイルを作成します。
//terminal[][lodashのインストール]{
 > npm install lodash
//}
//list[][src/index.js]{
  import _ from 'lodash';

  function component() {
    const element = document.createElement('div');
    // Lodash, now imported by this script
    element.innerHTML = _.join(['webpack', '動いてるお〜'], ' ');
    return element;
  }

  document.body.appendChild(component());
//}

@<strong>{3. トップページを作成}@<br>{}
webpackのデフォルトの出力先「dist」フォルダを作成し、「index.html」ファイルを作成します。

//list[][dist/index.html]{
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

@<strong>{4. 動作を確認}@<br>{}
webpackの動作を確認するために、ターミナルで以下のコマンドを実行します。

//terminal[][webpack実行後、ブラウザで表示]{
 > npx webpack serve --open --static-directory dist --mode=development
//}

//note[コマンド解説]{
npx --> /node_modules/.binフォルダにあるファイルを実行@<br>{}
  　webpack --> 今回動かすモジュール@<br>{}
  　serve --> devServer(開発用サーバ)も起動@<br>{}
  　--open --> デフォルトのブラウザで開く@<br>{}
  　--static-directory dist --> devServerのDocumentRootを指定@<br>{}
  　--mode=development --> 出力モード@<br>{}

「--static-directory dist」を入力しているのは、devServerのデフォルトDocumentRootは「public」のためです。
//}

//terminal[][webpackをコマンドで起動]{
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

//clearpage
「--open」オプションでデフォルトのブラウザが起動し、index.htmlが表示されます。
//image[webpack_test01][ブラウザで表示][scale=0.8,border=on]

//image[ok2][][scale=0.6,pos=H]
//clearpage


devToolsで「main.js」を確認すると、node_modulesフォルダ以下にインストールされたJavaScriptが
1つのファイルにまとめられているのが確認できます。
//image[webpack_test02][devToolsでmain.js内を確認][scale=0.8]

//clearpage

//terminal[][ビルドの実行]{
 > npx webpack build
//}

上記コマンドを実行すると、distフォルダ以下にmain.jsファイルが出力されます。

//image[webpack_test03][webpackでビルドしてみた][scale=0.8]

//clearpage
//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 02_webpack-install https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}

//image[git][][scale=0.7,pos=H]

//clearpage
==={04-webpack-config} webpackの設定ファイル
自分でwebpack、devServerを動作させてみると、webpackが何をやっているかを理解しやすくなります。

本章では、webpackの設定ファイル「webpack-config.js」を作成します。

//image[generateSettings][][scale=0.7,pos=H]

手順は、

 1. 「npx webpack-cli init」をターミナルで実行し、ひな型を作成。
 2. 必要なpluginのインストールと設定ファイルへの追加
 3. 不要な設定を削除し、開発時用、製品作成時用でファイルを分ける

と、なります。

ターミナルにてコマンドを実行すると、@<br>{}
//terminal[][npx webpack-cli initの実行]{
 > npx webpack-cli init
//}

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

//terminal[][webpack-config.jsの作成]{
  > npx webpack-cli init
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

//blankline
作成された「webpack.config.js」を以下のように編集します。
#@#<!-- textlint-disable -->

 * entry: "./src/index.ts"を"./src/index.js"へ
 * output: path: path.resolve(__dirname, "public")へ
 * distフォルダを削除し、publicフォルダを作成

#@#<!-- textlint-enable -->
//list[][webpack.config.js]{
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

@<strong>{プラグインのインストール}@<br>{}

//image[plugins][][scale=0.7,pos=H]
追加で、以下のプラグイン、ローダも追加します。

 * uglify-js プロダクション出力時にconsole関数を除去
 * terser-webpack-plugin 上記をwebpackで使用する場合必要
 * css-minimizer-webpack-plugin CSSをminimize
 * webpack-merge 複数のwebpack-configファイルをマージする

ターミナルで以下のコマンドを実行します。
//terminal[][追加プラグイン、ローダのインストール]{
 > npm install -D uglify-js terser-webpack-plugin css-minimizer-webpack-plugin webpack-merge
//}

追加のプラグイン、ローダの設定を追加したwebpack.config.jsです。devServerでページを表示する際に、
デフォルトのブラウザではなくdevToolsの強力な「Google Chrome」を使うようにしました。

//blankline
OS毎にChromeのアプリケーション名が違うためOSを取得し対応した「Chrome名」に変換するためのswitch文を追加しています。
「create-react-app」だと、結構複雑なことをやってGoogle Chromeを起動しています。

//blankline
興味のある方は、「create-react-app」を使ってプロジェクト作成し、react-scriptsを追うとお勉強になります。

//list[][webpack.config.js]{
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

//blankline
「index.js」に、動作確認用に追加するスタイル指定用の「sytle.css」、「style.scss」も追加します。

//list[][style.css]{
  div {
    background-color: aqua;
  }
//}

//list[][style.scss]{
  $primary-color: #f00;

  div {
    color: $primary-color;
  }
//}

//blankline
適当な画像ファイルを用意し、「src/assets/images」フォルダを作成し追加します。

//blankline
コマンドを「package.json」に、スクリプトとして追加します。

//list[][package.jsonのスクリプト部分]{
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "build": "webpack --mode=production",
    "build:dev": "webpack --mode=development",
    "build:prod": "webpack --mode=production",
    "start": "webpack serve"
  },
//}

まずは、ファイルを出力しないでブラウザで表示します。

//terminal[][ブラウザで表示]{
 > npm run start
//}

「div」要素の背景、文字色も「style.css」、「style.scss」から作成された「main.css」から反映されています。
また、「index.html」には、作成された「main.js」、「main.css」を読み込む部分はありませんが、
webpackが「HtmlWebpackPlugin」で自動で読込部分が追加されています。

//image[webpack_test04][desc][scale=0.6,border=on,pos=H]

次にプロダクション用にビルドしてみます。

//terminal[][ビルド]{
　> npm run build
//}

下図のように、@<br>{}

 * index.html
 * main.js
 * main.css
 * images/画像ファイル

が出力されていますので、ファイル開き内容を確認してください。

//image[webpack_test05][][scale=1.0]

//clearpage

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 03_setup-webpack-config-file https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}



==={sec-04-webpack-config-all} webpack設定ファイルを分割する
問題なく動作した「webpack.config.js」ですが、今後の運用を考え「開発用」、「プロダクション用」、「共通分」に切り分けます。
devServer関連はプロダクションには関係ありませんし、minimizer関連は開発時には邪魔です。

@<href>{https://webpack.js.org/guides/production/, 本家でも推奨}されています。

//image[divid][][scale=0.7,pos=H]

//blankline
「webpack.config.js」を以下のよう分割し、共用部分は「webpack-merge」を使用して統合します。@<br>{}

 * 共用 webpack.common.js
 * 開発用 webpack.dev.js
 * プロダクション用 webpack.prod.js

 開発用はdevServer関係、プロダクション用はminimizer関係、それ以外は共用として分けていきます。

//blankline
「webpack.dev.js」を作成し、「webpack.config.js」全体を貼り付けdevServer、debtoolを
残し、「module」はCSS関係のみで「style-loader」を使うように変更します。

//blankline
また、「mode:'development'」を追加します。

//list[][webpack.dev.js]{
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

//blankline
こちらは、「mode:'production'」を追加します。

//list[][webpack.prod.js]{
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

//list[][webpack.common.js]{
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

//list[][package.jsonのスクリプト部分]{
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

==={sec04-babeljs} Babel.jsのインストールと設定
Babel.jsとは、Babel.jsのトップページの例にあるように、
モダンJS(ES2015移行のJavaScript)を未対応の古いブラウザでも解釈できるようなJavaScriptに変換してくれる
トランスコンパイラ(変換器)です。

//image[babel01][Babel.js本家ページ][scale=0.9,pos=H]

それでは、プロジェクトに「Babel.js」を導入していきます。

//image[transpaile][][scale=0.8,pos=H]

Babel.jsのトップページの上部にあるメニューの「Setup」をクリックします。すると、手順に従うように番号のついた案内ページが表示されます。

//image[babel02][使用するツールを選択][scale=0.9,pos=H]

このプロジェクトでは、「webpack」を使用しますので、「webpack」ボタンをクリックします。

//blankline
手順2〜4が表示されましたので、順に実行していきます。

//image[babel03][babelのインストール手順][scale=0.9,pos=H]

//clearpage
最初に指示されているパッケージをインストールします。今までnpmでインストール時に「-D」としていたのは、
「--save-dev」の略です。
右端にあるコピーアイコンをクリックしてターミナルに貼り付けても良いです。

//terminal[][Babel.jsパッケージインストール]{
 > npm install --save-dev babel-loader @babel/core
//}

次に、手順3のコードを「webpack.common.js」へコピーします。コピー後の「webpack.common.js」です。

//list[][webpack.common.js,Babelローダの導入]{
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
          test: /\.m?js$/,
          exclude: /node_modules/,
          use: {
            loader: 'babel-loader',
            options: {
              presets: ['@babel/preset-env'],
            },
          },
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

次に、手順4に進みます。最初に「@babel/preset-env」パッケージをインストールします。

//terminal[][@babel/preset-envのインストール]{
 > npm install --save-dev @babel/preset-env
//}

インストールが完了しましたら、プロジェクトフォルダ直下に「babel.config.json」ファイルを作成し、手順4の内容を貼り付けます。

//list[][babel.config.json]{
  {
    "presets": ["@babel/preset-env"]
  }
//}

以上で、Babel.jsの導入は完了です。

==== 動作を確認してみる。

//image[pray2][][scale=0.8,pos=H]

「src/index.js」に少しコードを追加します。
ES6で新しく使えるようになったテンプレートリテラルを使用したコードです。

//list[][src/index.js]{
  import _ from 'lodash';
  import './style.css';
  import './style.scss';

  import Yaruo from './assets/images/yaruo.png';

  function component() {
    const element = document.createElement('div');

    // Lodash, now imported by this script
    const myName = 'やる夫';
    const words = 'こまけぇこたぁいいんだよ〜';
    const message = `<br />${myName}の口グセなのか？<br />${words}`;
    element.innerHTML = _.join(['webpack', '動いてるお〜'], ' ') + message;

    return element;
  }

  document.body.appendChild(component());

  const image = new Image();
  image.src = Yaruo;

  document.body.appendChild(image);

//}

//clearpage
Babel.js導入前の実行結果です。
//image[babel06][Babel.js導入前ですので、そのまま][scale=0.9]

//clearpage
Babel.js導入後の実行結果です。
//image[babel07][concatに変換されています。][scale=0.9]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 05_babel-install https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}

==={sec04-react} Reactのインストール
//warning[index.tsを削除してね。]{
ここで気が付いたのですが、「src/index.ts」は、現時点で不要なので削除してください。
//}

そろそろ完成に近付いてきました。Reactをインストールします。

//blankline
Reactは、拡張子「.jsx」を使ったHTMLにJavaScriptを埋め込むコンポーネントがメインです。
通常のJavaScriptとは記法が違うため「Babel.js」に理解してもらえるように「@babel/preset-react」を
インストールします。

//image[react-kita][][scale=0.8,pos=H]

//image[babel08][@babel/preset-react][scale=0.9]

//clearpage
ターミナルに以下のコマンドでインストールします。

//terminal[][@babel/preset-reactのインストール]{
 > npm install -D @babel/preset-react
//}

インストールが完了しましたら、「babel.config.json」へプリセットを追加します。

//list[][babel.config.json]{
  {
    "presets": [["@babel/preset-env"], ["@babel/preset-react"]]
  }
//}

//blankline
#@#<!-- textlint-disable -->
Reactを使うためにインストールするパッケージは、
#@#<!-- textlint-enable -->

 * react(react本体)
 * react-dom(DOMへのエントリポイント、Reactの描画を提供)

の2つです。

//terminal[][Reactのインストール]{
 > npm install react react-dom
//}

以上で、Reactのインストールは完了しましたので動作確認を行います。

//image[pray3][][scale=0.7,pos=H]

手順は、

 1. src/index.htmlに描画する場所を指定する。
 2. src/index.jsで上記「index.html」へReactDOMで描画する。
 3. Appコンポーネントをsrc/components/App.jsxファイルへ作成する。
 4. 「webpack.common.js」へReactコンポーネント「jsx」を扱うよう変更する。

となります。

「src/index.html」は、Reactの描画する部分を指定します。

//list[][src/index.html]{
  <!DOCTYPE html>
  <html>
    <head>
      <meta charset="utf-8" />
      <title>React Appだお〜</title>
    </head>
    <body>
      <div id="root"></div>
    </body>
  </html>

//}

「src/index.js」にてReactDOMを使用して「public/index.html」へ描画する。

//list[][src/index.js]{
  import React from 'react';
  import ReactDOM from 'react-dom';
  import App from './App';

  ReactDOM.render(
    <div>
      <App />
    </div>,
    document.getElementById('root')
  );
//}

「src/components/App.jsx」にAppコンポーネントを作成します。Reactコンポーネントは、
HTML内にJavaScriptを埋め込む記法となります。

//list[][src/components/App.jsx]{
  import React from 'react';
  import _ from 'lodash';
  import Yaruo from '../assets/images/yaruo.png';

  const App = () => {
    const myName = 'やる夫';
    const words = 'こまけぇこたぁいいんだよ〜';
    return (
      <div>
        {_.join(['webpack', '動いてるお〜'], ' ')}
        <br />
        {myName}口グセなのか？
        <br />
        {words}
        <div>
          <img src={Yaruo} />
        </div>
      </div>
    );
  };

  export default App;
//}

「webpack.common.js」を以下のように変更します。

 * Reactコンポーネントの拡張子「.jsx」を扱うように変更する。
 * テンプレートを「src/index.html」に変更する。

//list[][webpack.common.js]{
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
        template: 'src/index.html',
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
          test: /\.(js|jsx)/i,
          exclude: /node_modules/,
          use: {
            loader: 'babel-loader',
            options: {
              presets: ['@babel/preset-env'],
            },
          },
        },
        {
          test: /\.(eot|svg|ttf|woff|woff2|png|jpg|gif)$/i,
          type: 'asset',
        },
      ],
    },
    resolve: {
      extensions: ['.tsx', '.ts', '.js', '.jsx'],
    },
  };

//}

動作確認を行います。

//terminal[][reactの動作確認]{
 > npm run start
//}

//image[babel09][reactの動作確認][scale=0.7]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 06_react-install https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}


==={sec04-typescript} TypeScriptのインストール
ここまで作成したReactプロジェクトにTypeScriptを導入します。
本家Reactでは、@<href>{https://ja.reactjs.org/docs/static-type-checking.html#typescript, TypeScriptの導入}に関して
以下のような手順を示しています。

//image[typescript01][TypeScriptの導入][scale=0.8]

では手順に従って、TypeScriptを導入していきます。

//blankline
最初は、TypeScriptパッケージのインストールです。

//terminal[][TypeScriptパッケージのインストール]{
 > npm install -D typescript
//}

次に、TypeScriptのコンパイラ設定ファイル「tsconfig.json」を作成します。

//image[tsconfig][][scale=0.7,pos=H]

//terminal[][tsconfig.jsonの作成]{
 > npx tsc --init

Created a new tsconfig.json with:
                                                                                                                  TS
  target: es2016
  module: commonjs
  strict: true
  esModuleInterop: true
  skipLibCheck: true
  forceConsistentCasingInFileNames: true


You can learn more at https://aka.ms/tsconfig.json
//}

コマンドを実行すると、「tsconfig.json」ファイルが作成されます。
コメントアウトされているものは、デフォルト値です。

//image[typescript04][作成されたtsconfig.json][scale=0.8]

//clearpage
TypeScriptコンパイラのオプションは、
@<href>{https://www.typescriptlang.org/docs/handbook/tsconfig-json.html, こちら}
で確認できます。

//blankline
TypeScript開発元のMicrosoftは、Reactへ導入した
@<href>{https://github.com/Microsoft/TypeScript-React-Starter/blob/master/tsconfig.json, 「tsconfig.json」のお勧め}
を以下のようにしています。

//list[][Microsoftお勧めReact下のtsconfig.json]{
  {
    "compilerOptions": {
      "outDir": "build/dist",
      "module": "commonjs",
      "target": "es5",
      "lib": ["es6", "dom"],
      "sourceMap": true,
      "allowJs": true,
      "jsx": "react",
      "moduleResolution": "node",
      "rootDir": "src",
      "noImplicitReturns": true,
      "noImplicitThis": true,
      "noImplicitAny": true,
      "strictNullChecks": true
    },
    "exclude": [
      "node_modules",
      "build",
      "scripts",
      "acceptance-tests",
      "webpack",
      "jest",
      "src/setupTests.ts"
    ],
    "types": [
      "typePatches"
    ]
  }
//}

Microsoftお勧めの設定に修正したものが、こちらです。コメントアウトされているものは削除しています。

//list[][修正後のtsconfig.json][fold=off]{
  {
    "compilerOptions": {
      "target": "es5",
      "lib": [
        "es6",
        "dom"
      ],
      "jsx": "react",
      "module": "commonjs",
      "rootDir": "src",
      "outDir": "public",
      "esModuleInterop": true,
      "forceConsistentCasingInFileNames": true,
      "strict": true,
      "skipLibCheck": true
    },
    "exclude": ["node_modules", "public", "webpack"]
  }

//}

TypeScriptは、ファイル拡張子が、

 * .js ---> .ts
 * .jsx --> .tsx

 となるため、「webpack.common.js」の「entry」のファイル名の拡張子を「.tsx」に変えます。

//list[][webpack.common.jsの一部]{
  const path = require('path');
  const HtmlWebpackPlugin = require('html-webpack-plugin');

  module.exports = {
    entry: './src/index.tsx',
    output: {
      path: path.resolve(__dirname, 'public'),
      assetModuleFilename: 'images/[name][ext][query]',
      clean: true,
    },
//}

プロジェクト内のファイル名も変更します。

 * 「src/index.js」---> 「src/index.tsx」
 * 「src/components/App.jsx」 --> 「src/components/App.tsx」


次に、使用するライブラリの型定義をインストールします。
ライブラリによっては自身が型定義を持っている場合もありますし、
有志で作成された型定義ファイルは、npmリポジトリの「@types/」に
ある場合もあります。

//blankline
使用するReact、Node.jsの型定義ファイルは、「@types/」以下にありますので
インストールします。

//terminal[][React、Node.jsの型定義のインストール]{
 > npm install -D @types/node @types/react @types/react-dom
//}


型定義のインストールが完了しても、「App.tsx」で、

 * lodashの型定義がない
 * yaruo.pngの型定義がない

 と、エラーが表示されています。

//image[typescript02][App.tsxでエラー表示][scale=0.7,pos=H]

//clearpage
「lodash」の型定義はインストールすればエラーが消えますが、今後「lodash」は使わないので
 アンインストールし、該当コードも削除します。

//terminal[][lodashのアンインストール]{
 > npm uninstall lodash
//}

「png」については、プロジェクト用の型定義ファイルを作成します。

//blankline
「src/types/index.d.ts」を作成し、以下のように記入します。

//list[][src/types/index.d.ts]{
declare module '*.png'
//}

作成したファイルを「tsconfig.json」に型定義ファイルの位置を追加します。

//list[][tsconfig.json]{
  "compilerOptions": {
    "typeRoots": [
      "types"
    ]
  }
//}

動作確認を行います。

//terminal[][動作確認]{
 > npm run start
//}

lodash部分のコードが削除されたトップページを表示します。

//image[typescript03][TypeScript導入後動作確認][scale=0.6,pos=H]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 07_typescript-install https://github.com/yaruo-react-redux/yaruo-start-template.git
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

//image[linter][][scale=0.7,pos=H]

//blankline
「eslint」は、設定ファイルで指定されたルールと違うコードの書き方をしている部分を指摘してくれます。
その指定されたルールとは、たいていの場合にはJavaScriptに詳しい人達が決めたもので、良く使われるものは、かの有名なAirBnBの開発チームのものです。
もちろん、ルールは改変・追加もできます。

//blankline
#@#<!-- textlint-disable -->
チェックしてくれるのは、たとえば、
#@#<!-- textlint-enable -->

 * constで宣言している変数への代入
 * 未定義の変数やモジュールの使用
 * 分割代入の使用を推奨

などがありますが、何をチェックするのかは、チーム毎、プロジェクト毎に自由に決めることができます。

//blankline
「prettier」は、コードを整形(インデント、改行など)してくれるツールです。
実は、eslintでもコード整形はできるのですが、コード整形はprettierの方が優れいます。

//blankline
#@#<!-- textlint-disable -->
そのために、
#@#<!-- textlint-enable -->

 * コードチェックは、eslint
 * コード整形は、prettier

と、得意なものに任せます。

==={sec-03eslint} eslint、prettierのインストール

===={sec-03eslint-install} eslintのパッケージ追加と設定
//note[create-react-appで作成したプロジェクト]{
「create-react-app」を使用して作成したスタートアッププロジェクトには、eslintは導入済みです。

//blankline
追加のパッケージ、設定については、本章の後半で解説しています。
//}

ターミナルに以下のように「eslint --init」と初期化コマンドを入力します。
「eslint」が未インストール状態でしたら、「eslint」をインストールするのか問われます。

//terminal[][eslintの初期化]{
$ npx eslint --init
Need to install the following packages:
  eslint
Ok to proceed? (y) y
//}

「y」を入力しエンターキーを押すと「eslint」がインストールされ、設定ファイルを作成するための質問が始まります。

//blankline
「?」が行頭にある質問と選択枝が表示されますので、カーソルキーで選択枝を選びエンターキーで次ぎの質問に移ります。
//terminal[][eslintの質問に答える]{
  ? How would you like to use ESLint? …
    To check syntax only　　　　　　　　　　　　
  > To check syntax and find problems    @<balloon>{選択したものに　＞ が表示される}
    To check syntax, find problems, and enforce code style
//}

最後の質問に答えると必要なパッケージをインストールするか尋ねられますので「Yes」と答えてます。
//terminal[][eslintへの答え]{
  ✔ How would you like to use ESLint? · style
  ✔ What type of modules does your project use? · esm
  ✔ Which framework does your project use? · react
  ✔ Does your project use TypeScript? · No / Yes  @<balloon>{Yesを選択}
  ✔ Where does your code run? · browser
  ✔ How would you like to define a style for your project? · guide
  ✔ Which style guide do you want to follow? · airbnb
  ✔ What format do you want your config file to be in? · JavaScript
  Checking peerDependencies of eslint-config-airbnb@latest
  Local ESLint installation not found.
  The config that you've selected requires the following dependencies:

  eslint-plugin-react@^7.27.1 @typescript-eslint/eslint-plugin@latest eslint-config-airbnb@latest eslint@^7.32.0 || ^8.2.0 eslint-plugin-import@^2.25.3 eslint-plugin-jsx-a11y@^6.5.1 eslint-plugin-react-hooks@^4.3.0 @typescript-eslint/parser@latest
  ? Would you like to install them now with npm? › No / Yes @<balloon>{Yesを選択}
//}

//list[][package.jsonにeslint関連のパッケージがインストールされました。]{
  "devDependencies": {
    "@typescript-eslint/eslint-plugin": "^5.8.0",
    "@typescript-eslint/parser": "^5.8.0",
    "@webpack-cli/generators": "^2.4.1",
    "eslint": "^8.5.0",
    "eslint-config-airbnb": "^19.0.2",
    "eslint-plugin-import": "^2.25.3",
    "eslint-plugin-jsx-a11y": "^6.5.1",
    "eslint-plugin-react": "^7.28.0",
    "eslint-plugin-react-hooks": "^4.3.0",
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
          "plugin:react/recommended",
          "airbnb"
      ],
      "parser": "@typescript-eslint/parser",
      "parserOptions": {
          "ecmaFeatures": {
              "jsx": true
          },
          "ecmaVersion": 13,
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

//image[rules][][scale=0.7,pos=H]

//blankline
書き出されたルールは、ルール名に適用方法{"off(適用しない)","warn(警告)","error(エラー)"}が記されています。
表記は、{0,1,2}の数字で表示される場合もあります。
同じルールがあった場合には、後から読み込まれたルールに上書きされます。
個別に上書きしたいものは「.eslintrc.js」ファイルの「rules」セクションに追加します。

//terminal[][eslint設定で適用されるルール]{
$ npx eslint --print-config .eslintrc.js > current_rules.txt
//}

「eslint --init」時にインストールされたルールが適用されるように「extends」に追加します。

//blankline
次に、TypeScriptもチェックできるようにルールを追加します。「plugin:」の下3行を追加しました。
//list[][.eslintrc.jsのextends部分]{
  "extends": [
  'plugin:react/recommended',
  'airbnb',
  'airbnb/hooks',
  'plugin:@typescript-eslint/recommended',
  'plugin:@typescript-eslint/recommended-requiring-type-checking',
  'plugin:import/recommended',
  'plugin:import/typescript',
  ],
//}

再度、ルールを出力すると適用されるルールがずいぶん増えているのが分かります。

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

//image[rules2][][scale=0.7,pos=H]

ルール「import/extensions」は、インポート宣言でnode_modules以下にあるパッケージからは拡張子が不要(import aaa from 'aaa')
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

「no-void」は、void演算子を使用するとundefinedを返すため禁止してあります。
「create-react-app」で作成される「reportWebVitals.ts」でvoid使います。
文としての使用だけを可能にします。
//list[][no-voidの現在]{
  "no-void": [
    "error"
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
        'no-void': [
          'error',
          {
            allowAsStatement: true,
          },
        ],
  }
//}

===={sec-03prettier} Prettierのインストールと設定

ここからは、Prettierのインストールと設定をします。
//terminal[][Prettierのインストール]{
  > npm install -D prettier eslint-config-prettier
//}

インストールが完了すると、package.jsonに追加されます。
//list[][package.json]{
  "devDependencies": {
    "eslint-config-prettier": "^8.3.0",
    "prettier": "^2.5.1"
  }
//}

Pretterのチェックを「.eslintrc.js」へ追加します。

//image[prettier][][scale=0.7,pos=H]

//list[][.eslintrc.js]{
  "extends": [
  'plugin:react/recommended',
  'airbnb',
  'airbnb/hooks',
  'plugin:@typescript-eslint/recommended',
  'plugin:@typescript-eslint/recommended-requiring-type-checking',
  'plugin:import/recommended',
  'plugin:import/typescript',
  'prettier' 　@<balloon>{prettierを追加}
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
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "build": "webpack --config webpack.prod.js",
    "build:dev": "webpack --config webpack.dev.js",
    "build:prod": "webpack --config webpack.prod.js",
    "start": "webpack serve --config webpack.dev.js",
    "lint": "eslint 'src/**/*.{js,jsx,ts,tsx}'", @<balloon>{lint:チェック}
    "fix": "npm run format && npm run lint:fix", @<balloon>{fix:整形してチェックして自動修復}
    "format": "prettier --write 'src/**/*.{js,jsx,ts,tsx}'", @<balloon>{format:整形}
    "lint:fix": "eslint --fix 'src/**/*.{js,jsx,ts,tsx}'",  @<balloon>{lint:fixチェック後修復}
  },
},
//}

Eslint、Prettierの設定が完了しましたので、srcフォルダにある「App.tsx」を開いてみると、
ルールから外れるものは指摘されています。

//blankline
以上で環境構築は完了なのですが、「.eslintrc.js」にてエラーが表示されています。

//quote{
Parsing error: "parserOptions.project" has been set for @typescript-eslint/parser.
The file does not match your project config: .eslintrc.js.
The file must be included in at least one of the projects provided.
//}

このエラーは、「parserOptions.project」で「tsconfig.json」を指定していますが、
「tsconfig.json」では、「module」で「commonjs」を指定しています。

//blankline
そのため、「eslintrc.js」ファイルが、どこからもimportされていないので警告が出ています。

//blankline
解決策として、「eslint」の対象外とするために「.eslintignore」を作成し、「eslintrc.js」を指定します。

//list[][.eslintignore]{
.eslintrc.js
//}

これでエラーが解消されます。

//note[]{
ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
> git clone -b 07_typescript-install https://github.com/yaruo-react-redux/yaruo-start-template.git
//}
#@#<!-- textlint-enable -->
//}


==={sec04-cra-with-eslint} create-react-app作成のプロジェクトへ「eslint,prettier」を設定
「create-react-app」で作成したプロジェクトには、下図のようにeslintが組み込まれています。

//image[cra-eslint01][create-react-appのeslint][scale=0.8,pos=H]

「npx eslint --init」でインストールした、

 * eslint-plugin-react@^7.27.1
 * @typescript-eslint/eslint-plugin@latest
 * eslint-config-airbnb@latest
 * eslint@^7.32.0 || ^8.2.0
 * eslint-plugin-import@^2.25.3
 * eslint-plugin-jsx-a11y@^6.5.1
 * eslint-plugin-react-hooks@^4.3.0
 * @typescript-eslint/parser@latest

のうち、airbnb以外はインストールされています。

//blankline
そのため、「eslint-config-airbnb」だけをインストールします。

//terminal[][create-react-app作成プロジェクトへeslint-config-airbnbのインストール]{
　❯ npm install -D eslint-config-airbnb
//}

設定ファイル「.eslintrc.js」を「ゼロからの構築」と同じものを作成します。

//list[][.eslintrc.js]{
  module.exports = {
    env: {
      browser: true,
      es2021: true,
    },
    extends: [
      'plugin:react/recommended',
      'airbnb',
      'airbnb/hooks',
      'plugin:@typescript-eslint/recommended',
      'plugin:@typescript-eslint/recommended-requiring-type-checking',
      'plugin:import/recommended',
      'plugin:import/typescript',
      'prettier',
    ],
    parser: '@typescript-eslint/parser',
    parserOptions: {
      ecmaFeatures: {
        jsx: true,
      },
      ecmaVersion: 13,
      sourceType: 'module',
      tsconfigRootDir: __dirname,
      project: ['./tsconfig.json'],
    },
    plugins: ['react', '@typescript-eslint'],
    rules: {
      'import/extensions': [
        'error',
        {
          js: 'never',
          jsx: 'never',
          ts: 'never',
          tsx: 'never',
        },
      ],
      'react/jsx-filename-extension': [
        'error',
        {
          extensions: ['.jsx', '.tsx'],
        },
      ],
      'react/react-in-jsx-scope': 'off',
      'react/function-component-definition': [
        'error',
        {
          namedComponents: 'arrow-function',
          unnamedComponents: 'arrow-function',
        },
      ],
    },
  };

//}

Prettierはインストールされていないためインストールします。

//terminal[][create-react-app作成プロジェクトへprettierのインストール]{
 > npm install -D prettier eslint-config-prettier
//}

「.eslintignore」、「.prettierrc」を作成します。

//list[][.eslintignore]{
.eslintrc.js
//}

//list[][.prettierrc]{
  {
    "singleQuote": true,
    "jsxSingleQuote": true
  }
//}

「package.json」にある「eslint」の設定を削除します。

//list[][package.jsonのeslint設定を削除]{
  "eslintConfig": {
    "extends": [
      "react-app",
      "react-app/jest"
    ]  },
//}


最後に、「package.json」にスクリプトを追加し、eslint、prettierが動作するようにします。

//list[][package.json]{
  "scripts": {
    "start": "react-scripts start",
    "build": "react-scripts build",
    "test": "react-scripts test",
    "eject": "react-scripts eject",
    "lint": "eslint 'src/**/*.{js,jsx,ts,tsx}'",
    "fix": "npm run format && npm run lint:fix",
    "format": "prettier --write 'src/**/*.{js,jsx,ts,tsx}'",
    "lint:fix": "eslint --fix 'src/**/*.{js,jsx,ts,tsx}'"
  },
//}

以上で、「create-react-app」で作成したプロジェクトに追加でairbnbのチェックを追加できました。


=={sec-04fix} eslint、prettierの指摘を修正
ESlint、Prettierは指摘するだけではなく、修正案の提示・修正(できるものだけですが...)までしてくれます。

//image[shutup][][scale=0.6]
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
まずは、App.tsxファイルを修正します。

//blankline
エラー内容は、「Functionコンポーネントは、arrow関数にしなさい。」とのことで、
これは、rulesに追加したためです。

//image[cra-fix_app_tsx][App.tsxの修正][scale=0.8]

//note[]{
  筆者がVSCodeを日本語化していないのは、エラーメッセージでググる場合を考えてのことです。
  英語でのエラーメッセージの方が的確なページをみつけやすいと考えています。
//}

では、指摘されている点を修正していきます。

//list[][修正後のApp.tsx]{
  import React from 'react';
  import logo from './logo.svg';
  import './App.css';

  const App = () => (
    <div className='App'>
      <header className='App-header'>
        <img src={logo} className='App-logo' alt='logo' />
        <p>
          Edit <code>src/App.tsx</code> and save to reload.
        </p>
        <a
          className='App-link'
          href='https://reactjs.org'
          target='_blank'
          rel='noopener noreferrer'
        >
          Learn React
        </a>
      </header>
    </div>
  );

  export default App;
//}

次に、「repotWebVitals.ts」でエラーが発生しています。これはimpor文に「void」を付けることで解決します。

//list[][修正後のreportWebVitals.ts]{
  import { ReportHandler } from 'web-vitals';

  const reportWebVitals = (onPerfEntry?: ReportHandler) => {
    if (onPerfEntry && onPerfEntry instanceof Function) {
      void import('web-vitals').then(
        ({ getCLS, getFID, getFCP, getLCP, getTTFB }) => {
          getCLS(onPerfEntry);
          getFID(onPerfEntry);
          getFCP(onPerfEntry);
          getLCP(onPerfEntry);
          getTTFB(onPerfEntry);
        }
      );
    }
  };

  export default reportWebVitals;

//}


これで現時点での指摘はすべて修正できました。動作確認を行います。

//terminal[][create-react-appの動作確認]{
 > npm run start
//}

これで、トップページが表示されます。

//image[ok3][][scale=0.5]

//note[]{
  ここまでの内容は、GitHub上で、以下のコマンドでクローンできます。
#@#<!-- textlint-disable -->
//terminal[][GitHub]{
  $ > git clone https://github.com/yaruo-react-redux/yaruo-cra-template.git
//}
#@#<!-- textlint-enable -->
//}

=={sec-chap02review} 第2章のまとめ
#@#<!-- textlint-disable -->
Reactを使用しスタートアップ用のアプリケーションの作成方法を
#@#<!-- textlint-enable -->

 * 「create-react-app」コマンドで作成
 * ゼロから構築

 の2通りで解説しました。

//blankline
バグの混入を防いだりより良いコーディングをするためにも、ESlint、Prettierを導入しましょう。
