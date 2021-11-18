= スタートプロジェクトの作成

//abstract{
  本章では、reactアプリケーションのひな型がコマンドひとつで作成できる「create-react-app」を使用して、
スタート用のアプリケーションを作成し、ブラウザで表示するまでを行います。

　また、作成するプロジェクトは、TypesScriptを使用します。コード記法の指摘・修正を行えるよう「eslint」、「prettier」の設定も行います。

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
また、使用するライブラリによっては、Babelのプラグインのインストールや設定など、アプリケーションのコードを書き始める前の作業がたいへんです。

//blankline
しかし、「そんなメンドウなことは、やってられない。」と誰しもが思ったか、
すぐにでもコードを書き始めることのできるスタート用アプリケーションが、react開発元のFacebookから提供されています。

//blankline
さらに、そのスタート用アプリケーションは、コマンド一発でインストールできます。

//blankline
では、実際に手を動かしましょう。
ターミナルを起動し、プロジェクトフォルダを作成するフォルダへ移動します。

//terminal[][create-react-appでスタート用アプリケーション作成]{
  $ > npx create react-app プロジェクト名 --template typescript
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
ターミナルには、Facebookが関わっているノード・パッケージマネージャーの「yarn」を使ったコマンドが表示されています。

 : yarn start
    開発用サーバの開始。
 : yarn build
    製品用に静的はファイルにアプリケーションをまとめる。
 : yarn test
    テストランナーの開始。
 : yarn eject
    ツール(create-react-app)を取り除き、依存関係、設定ファイル、スクリプトをappディレクトリにコピーする。

と、あります。

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
$ > git clone -b 01_create-react-app https://github.com/yaruo-react-redux/yaruo-diary.git
//}
#@#<!-- textlit-enable -->
//}

=={sec-02yarnstart} アプリケーションを実行
アプリケーションが作成できましたので、実行してみます。

ターミナルに表示されているように、プロジェクトフォルダへ移動し、スタート用のコマンドを入力します。

//terminal[][]{
$ cd プロジェクト名
$ npm start
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

//blankline
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

//blankline
package.jsonの「dependencies」には、実行に必要でインストール済みのnpmパッケージが記載されています。
必要なnpmパッケージをインストールすると、ここに自動的に追記されます。

//blankline
また、開発時のみ必要なパッケージ(buildしたときには組み込まれない)は、「devDependencies」に追加されます。

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
