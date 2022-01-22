= ゼロから始める(開発環境構築)

//image[01_00asignToFrontend][やる夫が、突然の移動を命じられたお！][scale=1.0]

//abstract{
  本章では、React、Reduxの開発環境を作成します。@<br>{}

「なぜ、これらが必要なのか？」@<br>{}

  は、とりあえず置いといて@<br>{}
  　・ Node.js@<br>{}
  　・ Microsoft Visual Studio Code + 拡張機能@<br>{}
  　・ Google Chrome + 拡張機能@<br>{}
をインストールしてください。これらは、すべて無償で提供されています。@<br>{}
@<br>{}
なお、これらの準備が整っている方は、本章を読み飛ばしていただいてもかまいません。
//}

#@#//makechaptitlepage[toc=on]

=={sec-nodejs}　Node.js

=== Node.jsについて
==== Node.jsとは？
「Node.js」は、通常ブラウザ上で実行されるJavaScriptをサーバやPC上で実行できるようする
「@<B>{JavaScript実行環境}」です。
たとえば、WindowsにPythonをインストールすると「python.exe」を使いpythonファイルをWindows上で実行できます。

//image[y01][pythonを実行][scale=1.0]

同じように、@<B>{Node.js}をインストールすると、「node.exe」を使いJavaScriptファイルを実行できます。
たとえば、以下のように「test01.js」ファイルを作成します。

//list[test01.js]{
  const name='やる夫';
  const message='こまけぇこたぁいいんだよ';

  console.log(`${name}が、こんなこと言ってます。${message}`);
//}

このスクリプトをターミナル上で実行します。「node」コマンドに実行したいJavaScriptファイルを引数として渡します。

//terminal[?][app.jsを実行]{
  ❯ node test01.js
  やる夫が、こんなこと言ってます。こまけぇこたぁいいんだよ
//}

このように、今まではJavaScriptの実行環境はブラウザでしたが、NodeがあればJacaScriptをPC、サーバで実行できます。

//image[denojs][][scale=0.6,pos=H]

//clearpage

==== Node.jsについて
//image[y01_getNodejs][Node.jsをインストールするお！][scale=1.0]
//image[yr01_aboutNodejs][Node.jsのバージョンには注意][scale=1.0]
では、Node.jsの本家トップページ:@<href>{https://nodejs.org/ja/}へアクセスします。

//image[01_01nodejsTop][Node.jsトップページ][scale=1.0,pos=H]

ここでダウンロード可能なのは、「16.13.2 LTS(Long Term Support)推奨版」と「17.4.0最新版」@<fn>{fn-101}の2つがあります。
//footnote[fn-101][2022/1/17現在]

LTS版、最新版は以下のロードマップにより更新されます。

//image[newRelease][][scale=1.0,pos=H]

//image[01_02nodejsRoadmap][Node.jsロードマップ][scale=1.0,pos=H]
//clearpage

Node.jsのReleases:@<href>{https://nodejs.org/ja/about/releases/}にあるように、
#@#<!-- textlint-disable -->
Node.jsは、各年の4月、10月にリリースされ、
#@#<!-- textlint-ensable -->

 * Current
 * Active
 * Maintenance
のフェーズを経ますが、メジャーバージョン番号が偶数のものだけが、Active期間を経て長期サポートされます。

//blankline
上記トップページにあるNode.js 16は、2024/4/30までの長期サポートとなります。
実際のプロジェクトで使用する場合は、よほどの理由がない限りは最新のLTS版を使用します。



=== Node.jsのインストールの前に
//image[y01_whichNodeVer][][scale=1.0]
Node.jsは、ロードマップにより定期的にバージョンアップされます。又、Node.js自体の不具合の修正などで
マイナーバージョンアップも行われます。

//blankline
プロジェクト開発中のマイナーバージョンアップでも検証が必要になりますが、
メジャーバージョンアップの場合はさらに大きな検証が必要になります。
場合によっては、ソースコードの大幅な改良をしなければならなくなります。

//blankline
それを避けるためにも、プロジェクト毎にNode.jsのバージョンは固定して開発します。

//blankline
通常は、OSにインストールできるNode.jsのバージョンはひとつですが、長期にわたるサポートや新規プロジェクト開発のためには、
複数のNode.jsのバージョンを切り替えて使用できるしくみを用意しましょう。

//blankline
私が使用しているのは、nvm(node version manager):@<href>{https://github.com/nvm-sh/nvm}です。
いろいろなバージョンのNode.jsを、簡単にインストール・アンインストール・切替ができます。

//blankline
「nvm」も含めたNode.jsバージョン管理ツールについては、
こちらの@heppokofrontendさんの良記事が参考になります。
//image[01_nodeVersionChange][][scale=1.0]
@<href>{https://qiita.com/heppokofrontend/items/5c4cc738c5239f4afe02, Node.jsのバージョン管理ツールを改めて選定する【2021年】}


=== nvm

nvm(node version manager)を使えば、複数バージョンのNode.jsを1台のPCにインストールし、
バージョンを切り替えることが簡単にできます。

//image[switchNodejs][][scale=0.6,pos=H]

//blankline
GitHub上のnvmは、Shellscript(sh, dash, zsh, bash)上で動作するため、Linux(UNIX系)、macOSにインストールできます。

//blankline
Windows版:@<href>{https://github.com/coreybutler/nvm-windows}は、別な方がGitHub上で公開されています。
コマンドが本家と少し違いますが、複数バージョンのインストール・バージョンの切り替えなど機能は問題ありません。

===== nvmのインストール

===== macOS

お使いのTerminalから以下のコマンドを実行してください。

//terminal[?][nvmのインストール]{
  >curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.0/install.sh | bash
//}

インストール完了後には、.zshrcへ以下を追加してください。
//terminal[][.zshrcへ追加]{
  export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" # This loads nvm
//}

//paragraphend

===== Windows

nvm-windowsのリリースページ:@<href>{https://github.com/coreybutler/nvm-windows/releases/tag/1.1.8}より、
最新版をダウンロードしインストールしてください。

//paragraphend

==== nvmの使い方

macOSではターミナルを起動し、Windowsではコマンドプロンプト、または、Windows Terminalを起動してください。

nvmとnvm-windowsでは、コマンドが少し違いますが、「nvm --help」を入力することで使用できるコマンドが表示されます。

//terminal[][Mac OSX]{
> nvm --help

Node Version Manager (v0.37.2)
@<balloon>{中略}
Example:
  nvm install 8.0.0                     Install a specific version number
  nvm use 8.0                           Use the latest available 8.0.x release
  nvm run 6.10.3 app.js                 Run app.js using node 6.10.3
  nvm exec 4.8.3 node app.js            Run `node app.js` with the PATH pointing to node 4.8.3
  nvm alias default 8.1.0               Set default node version on a shell
  nvm alias default node                Always default to the latest available node version on a shell

@<balloon>{中略}
Note:
  to remove, delete, or uninstall nvm - just remove the `$NVM_DIR` folder (usually `~/.nvm`)
//}

もし、32bit版Windowsをお使いの場合には、インストールの際に32bit版を指定する「32」をコマンドの最後につけてください。

//terminal[][windows]{
PS C:\Users\inabakazuya> nvm --help

Running version 1.1.7.

Usage:

  nvm arch                     : Show if node is running in 32 or 64 bit mode.
  nvm install <version> [arch] : The version can be a Node.js version or "latest" for the latest stable version.
                                 Optionally specify whether to install the 32 or 64 bit version (defaults to system arch).
                                 Set [arch] to "all" to install 32 AND 64 bit versions.
                                 Add --insecure to the end of this command to bypass SSL validation of the remote download server.
  nvm list [available]         : List the Node.js installations. Type "available" at the end to see what can be installed. Aliased as ls.
@<balloon>{中略}
  nvm uninstall <version>      : The version must be a specific version.
  nvm use [version] [arch]     : Switch to use the specified version. Optionally specify 32/64bit architecture.
                                 nvm use <arch> will continue using the selected version, but switch to 32/64 bit mode.
  nvm root [path]              : Set the directory where nvm should store different versions of Node.js.
                                 If <path> is not set, the current root will be displayed.
  nvm version                  : Displays the current running version of nvm for Windows. Aliased as v.
//}

//paragraphend
===== インストール可能なNode.jsを表示
まずは、インストール可能なNode.jsのバージョンを表示してみます。
macOSの場合には、古いバージョンから最新バージョンまでが表示されます。

//terminal[][Mac OSX]{
>nvm ls-remote
@<balloon>{古いバージョンから全て表示されるので中略}
v14.13.1
v14.14.0
v14.15.0   (LTS: Fermium)
v14.15.1   (LTS: Fermium)
v14.15.2   (Latest LTS: Fermium)
 v15.0.0
 v15.0.1
 v15.1.0
 v15.2.0
 v15.2.1
 v15.3.0
 v15.4.0
//}

//image[waiting][][scale=0.5,pos=H]

//clearpage
一方、Windowsの場合には、表形式で表示されます。新しいバージョンが上に表示されます。

//terminal[][Windows]{
PS C:\Users\inabakazuya> nvm list available

|   CURRENT    |     LTS      |  OLD STABLE  | OLD UNSTABLE |
|--------------|--------------|--------------|--------------|
|    15.4.0    |   14.15.2    |   0.12.18    |   0.11.16    |
|    15.3.0    |   14.15.1    |   0.12.17    |   0.11.15    |
|    15.2.1    |   14.15.0    |   0.12.16    |   0.11.14    |
|    15.2.0    |   12.20.0    |   0.12.15    |   0.11.13    |
|    15.1.0    |   12.19.1    |   0.12.14    |   0.11.12    |
|    15.0.1    |   12.19.0    |   0.12.13    |   0.11.11    |
|    15.0.0    |   12.18.4    |   0.12.12    |   0.11.10    |
|   14.14.0    |   12.18.3    |   0.12.11    |    0.11.9    |
|   14.13.1    |   12.18.2    |   0.12.10    |    0.11.8    |
|   14.13.0    |   12.18.1    |    0.12.9    |    0.11.7    |
|   14.12.0    |   12.18.0    |    0.12.8    |    0.11.6    |
|   14.11.0    |   12.17.0    |    0.12.7    |    0.11.5    |
|   14.10.1    |   12.16.3    |    0.12.6    |    0.11.4    |
|   14.10.0    |   12.16.2    |    0.12.5    |    0.11.3    |
|    14.9.0    |   12.16.1    |    0.12.4    |    0.11.2    |
|    14.8.0    |   12.16.0    |    0.12.3    |    0.11.1    |
|    14.7.0    |   12.15.0    |    0.12.2    |    0.11.0    |
|    14.6.0    |   12.14.1    |    0.12.1    |    0.9.12    |
|    14.5.0    |   12.14.0    |    0.12.0    |    0.9.11    |
|    14.4.0    |   12.13.1    |   0.10.48    |    0.9.10    |

This is a partial list. For a complete list, visit https://nodejs.org/download/release
//}

//paragraphend
===== Node.js 最新LTS版をインストール

それでは、最新のLTS版をインストールします。
インストールは、Mac、Windowsとも、「nvm install xx.yy.zz(インストールするバージョン番号)」でインストールできます。

//terminal[][Mac OSX]{
> nvm install v14.15.2
Downloading and installing node v14.15.2...
Downloading https://nodejs.org/dist/v14.15.2/node-v14.15.2-darwin-x64.tar.xz...
################################################################################################################# 100.0%
Computing checksum with shasum -a 256
Checksums matched!
Now using node v14.15.2 (npm v6.14.9)
//}


//terminal[][Window]{
PS C:\Users\inabakazuya> nvm install v14.15.2
Downloading Node.js version 14.15.2 (64-bit)...
Complete
Creating C:\Users\inabakazuya\AppData\Roaming\nvm\temp

Downloading npm version 6.14.9... Complete
Installing npm v6.14.9...

Installation complete. If you want to use this version, type

nvm use 14.15.2
//}

===== インストールされているNode.jsのバージョンの確認

インストールされているNode.jsのバージョンは、「nvm ls」で表示させ確認できます。

//terminal[][Mac OSX]{
$ > nvm ls
          v8.17.0
         v12.19.0
         v14.15.0
  ->     v14.15.2
           system
  default -> v12.18.3
  iojs -> N/A (default)
  unstable -> N/A (default)
  node -> stable (-> v14.15.2) (default)
  stable -> 14.15 (-> v14.15.2) (default)
  lts/* -> lts/fermium (-> v14.15.2)
  lts/argon -> v4.9.1 (-> N/A)
  lts/boron -> v6.17.1 (-> N/A)
  lts/carbon -> v8.17.0
  lts/dubnium -> v10.23.0 (-> N/A)
  lts/erbium -> v12.20.0 (-> N/A)
  lts/fermium -> v14.15.2
//}

//terminal[][Windows]{
PS C:\Users\inabakazuya> nvm ls

    14.15.2
    14.15.1
    12.13.1
  * 8.16.1 (Currently using 64-bit executable)
//}

//clearpage
===== 使用するNode.jsのバージョン切り替え

先ほどの「インストールされているNode.jsのバージョン表示」で、現在使われているNode.jsのバージョンも表示されています。
使用するNode.jsのバージョンを変更する場合には、「nvm use xx.yy.xx(使用するバージョン番号)」で切り替えます。

//terminal[][Node.jsのバージョン確認と切替]{
$ > node -v
v14.15.2
[~]
$ > nvm use v12.18.3
Now using node v12.18.3 (npm v6.14.6)
[~]
$ > node -v
v12.18.3
//}


以上で、複数のバージョンのNode.jsを切り替えて使える環境が構築できました。

//image[hanamaru][][scale=0.8]

=={sec-vscode} Microsoft Visual Studio Code + 拡張機能
Microsoft社が無料で提供している「テキストエディタ」です。Electron:@<href>{https://www.electronjs.org/}をベースにしたオープンソースで開発されています。

//blankline
Electronは、GitHub社が「Atom(テキストエディタ)」を開発するために構築したフレームワークで、
HTML・CSS・JavaScriptを使用して、Windows、Mac、Linuxのマルチプラットフォームで動作するアプリケーションを開発できます。

//blankline
Visual Studio Code(以後は、VSCodeと表記します。)は、コードを記述する「テキストエディタ」として非常に優秀ですが、
拡張機能(Google ChromeやFirefoxなどのブラウザ同様に拡張機能が多くの開発者により公開されています。)を追加することで
JavaScript以外の言語(C#、pythonなど)でも使えます。

//blankline
デバッグなども行えるため、Web開発では、事実上の標準と言っても良いでしょう。有料では、Jetbrains社:@<href>{https://www.jetbrains.com/}の
Webstormがありますが、今回は、無償のVSCodeを使用します。

//image[freeSoftware][][scale=0.5,pos=H]
=== VSCodeのインストール

VSCodeのインストールは@<br>{}
本家サイト
@<href>{https://code.visualstudio.com/}

//blankline
から、ダウンロード後インストールしてください。

//blankline
または、以下の方法でもインストールできます。

==== Windows
パッケージマネージャー「winget」をお使いの方は、
//terminal[][winget]{
  winget install -e --id Microsoft.VisualStudioCode
//}
にて、インストールできます。

==== macOS
パッケージマネージャーに「brew」をお使いの方は、
//terminal[][Homebrew]{
  > brew update
  > brew cask install visual-studio-code
//}
にて、インストールできます。

=== VSCodeの拡張機能
VSCodeは、プラグイン形式で拡張機能を追加できます。

React、Reduxを使用したプロジェクトでは、以下をインストールすると便利です。

//image[extensions][][scale=0.5]

VSCodeを起動し、左ツールバーの拡張機能アイコンをクリックします。
//image[01_03vscodeExtension][VSCodeの拡張機能][scale=0.9,pos=H]

ここの検索窓に拡張機能の名前、キーワードを入力して検索します。

==== Debugger for Chrome
デバッグの際に、PCにインストールされているChromeを自動で起動してくれます。
ChromeのDevToolsは、非常に強力です。また、ChromeにもReact、Redux用の拡張機能を追加すると
更に便利になります。

//image[01_06vscodeExtension_debuggerForChrome][Beautify][scale=1.0,pos=H]

=== Eslint
コード記法の間違いを指摘・修正してくれます。

//image[01_07vscodeExtension_eslint][Beautify][scale=1.0,pos=H]

=== Prettier
Eslintと同じように、コード記法の間違いの指摘・修正やコードフォーマットを行います。Eslintを合わせて使うと最強です。

//image[01_08vscodeExtension_prettier][Beautify][scale=1.0,pos=H]

=={sec-chrome} Google Chrome + 拡張機能
ご存じGoogle社が提供するブラウザです。

PCへインストールされていない方は、@<br>{}

=== Google Chromeのインストール
Google Chrome:@<href>{https://www.google.com/intl/ja/chrome/}
//image[01_09googleChrome][Google Chrome][scale=1.0,pos=H]


==== Google Chromeの拡張機能
こちらも、VSCodeと同様に拡張機能を追加することで、さらに便利に使うことができます。

React、Reduxの開発では、以下の拡張機能は必須と言っても良いほどです。

//blankline
拡張機能のインストールは、下記のChrome Web storeで検索してください。

//blankline
Chrome Web store:@<href>{https://chrome.google.com/webstore/category/extensions?hl=ja}
//image[01_13chromeWebstore][Chrome Web store][scale=1.0,pos=H]

//clearpage


==== React Developer Tools
Reactを使用して作成したページは、最終的にはページ出力用JavaScriptに変換され、ブラウザで表示されるときにはHTMLとして出力されます。
この拡張機能を使うと、Google ChromeのDevToolsにComponentsタブが作成され、Props、Stateを確認できます。


//image[01_10chromeExtReactDevTools][React Developer Tools][scale=1.0,pos=H]

//image[01_12chromeExtReactDevTools01][React DevToolsでAppを表示][scale=1.0,pos=H]

//clearpage

==== Redux DevTools
のちほど、Reduxの章であらためて説明しますが、「タイムトラベルデバッグ(実行されたアクションをさかのぼる)」が簡単にできます。
また、実行されたアクション、変更されたStateが「新」「旧」とあり、どの部分が変更されたのかも確かめるのも簡単です。


//image[01_11chromeExtReduxDevTools][React DevloperTools拡張機能][scale=1.0,pos=H]


=={sec-chap01review} 第1章のまとめ
React、Reduxの開発環境は、できましたでしょうか？


 * nvm
 * node
 * VSCode + 拡張機能
 * Google Chrome + 拡張機能

のインストールを完了してください。

//image[chap01-done][][scale=0.6]
