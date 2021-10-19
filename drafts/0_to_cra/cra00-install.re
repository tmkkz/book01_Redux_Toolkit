= ゼロから始める

//image[01_00asignToFrontend][やる夫が、突然の移動を命じられたお！][scale=1.0]

//abstract{
  この章では、React、Reduxの開発環境を作成します。

  * node.js
  * yarn
  * Microsoft Visual Studio Code + 拡張機能
  * Google Chrome + 拡張機能

  上記は、全て無償で提供されています。

  これらの準備が整っている方は、この章を読み飛ばしていただいても構いません。
//}

#@#//makechaptitlepage[toc=on]



=={sec-node.js} node.js

=== node.js
: node.jsとは？
「node.js」は、通常ブラウザ上で実行されるjavascriptをサーバーやPC上で実行できるようする
「@<B>{javascript実行環境}」です。

例えば、WindowsにPythonをインストールすると「python.exe」を使いpythonファイルをWindows上で実行できるようになります。
同じように、@<B>{node.js}をインストールすると、「node.exe」を使いjavascriptファイルを実行することができます。

ブラウザからでは、OS上の機能を使用する(例えば、ファイルの書込み・読込み)などは制限されますが、
node.jsで実行するとOSの機能を使用することができるようになります。

//note[]{
詳しくは、本家の「@<href>{https://nodejs.org/ja/about/, Node.jsとは}」を参照してください
}

==== node.jsについて
node.jsの本家トップページ:@<href>{https://nodejs.org/ja/}へアクセスします。

//image[01_01nodejsTop][Node.Jsトップページ][scale=1.0]

ここで、ダウンロード可能なのが「14.15.2LTS 推奨版」と「15.4.0 最新版」@<fn>{fn-101}の2つがあります。
これは、LTS版(Long Term Support-長期サポート-)と、新機能が追加される最新版となります。
LTS版、最新版は以下のロードマップにより更新されます。

//footnote[fn-101][2020/12/16現在]

Node.jsのReleases:@<href>{https://nodejs.org/ja/about/releases/}にあるように、
Node.jsは、各年の4月、10月にリリースされ、
* Current
* Active
* Maintenance
のフェーズを経ますが、メジャーバージョン番号が偶数のものだけが、Active期間を経て長期サポートされます。

上記トップページでは、Node.js 14が、2023/4/30までの長期サポートとなります。
実際のプロジェクトで使用する場合は、よほどの理由がない限りはLTS版を使用します。

//image[01_02nodejsRoadmap][Node.jsロードマップ][scale=1.0]

=== node.jsのインストールの前に

Node.jsには、LTS版と最新版がありますが、納品後のプロジェクトでも、不具合確認・修正・機能追加などがあり、
LTS版でも複数のバージョン(例えば、node12とnode14)に対応が必要とされます。

そのためには、1台のPC上で複数のNode.jsバージョンを切り替えできる仕組みを事前に用意しておきましょう。

私が使用しているのは、nvm(Node version manager):@<href>{https://github.com/nvm-sh/nvm}で、
いろいろなバージョンのnode.jsを、簡単にインストール・アンインストール・切替ができます。

Windows版:@<href>{https://github.com/coreybutler/nvm-windows}も、別な方がGithub上で公開されています。

==== nvm

===== nvmのインストール

====== Mac OSX
お使いのTerminalから以下のコマンドを実行してください。

//terminal[?][nvmのインストール]{
  $curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.37.2/install.sh | bash
//}

インストール完了後には、.zshrcへ以下を追加してください。
//terminal[][.zshrcへ追加]{
  export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" # This loads nvm
//}

====== Windows

nvm-windowsのリリースページ:@<href>{https://github.com/coreybutler/nvm-windows/releases/tag/1.1.7}より、
最新版をダウンロードしインストールしてください。

===== nvmの使い方

Mac OSXでは、ターミナルを起動し、Windowsでは、コマンドプロンプト、又は、Windows Terminalを起動してください。

nvmとnvm-windowsでは、コマンドが少し違いますが、「nvm --help」を入力することで使用できるコマンドが表示されます。

//terminal[][Mac OSX]{
$ > nvm --help

Node Version Manager (v0.37.2)

Note: <version> refers to any version-like string nvm understands. This includes:
  - full or partial version numbers, starting with an optional "v" (0.10, v0.1.2, v1)
  - default (built-in) aliases: node, stable, unstable, iojs, system
  - custom aliases you define with `nvm alias foo`

 Any options that produce colorized output should respect the `--no-colors` option.

Usage:
  nvm --help                                  Show this message
    --no-colors                               Suppress colored output
  nvm --version                               Print out the installed version of nvm
  nvm install [<version>]                     Download and install a <version>. Uses .nvmrc if available and version is omitted.
   The following optional arguments, if provided, must appear directly after `nvm install`:
    -s                                        Skip binary download, install from source only.
    --reinstall-packages-from=<version>       When installing, reinstall packages installed in <node|iojs|node version number>
    --lts                                     When installing, only select from LTS (long-term support) versions
    --lts=<LTS name>                          When installing, only select from versions for a specific LTS line
    --skip-default-packages                   When installing, skip the default-packages file if it exists
    --latest-npm                              After installing, attempt to upgrade to the latest working npm on the given node version
    --no-progress                             Disable the progress bar on any downloads
    --alias=<name>                            After installing, set the alias specified to the version specified. (same as: nvm alias <name> <version>)
    --default                                 After installing, set default alias to the version specified. (same as: nvm alias default <version>)
  nvm uninstall <version>                     Uninstall a version
  nvm uninstall --lts                         Uninstall using automatic LTS (long-term support) alias `lts/*`, if available.
  nvm uninstall --lts=<LTS name>              Uninstall using automatic alias for provided LTS line, if available.
  nvm use [<version>]                         Modify PATH to use <version>. Uses .nvmrc if available and version is omitted.
   The following optional arguments, if provided, must appear directly after `nvm use`:
    --silent                                  Silences stdout/stderr output
    --lts                                     Uses automatic LTS (long-term support) alias `lts/*`, if available.
    --lts=<LTS name>                          Uses automatic alias for provided LTS line, if available.
  nvm exec [<version>] [<command>]            Run <command> on <version>. Uses .nvmrc if available and version is omitted.
   The following optional arguments, if provided, must appear directly after `nvm exec`:
    --silent                                  Silences stdout/stderr output
    --lts                                     Uses automatic LTS (long-term support) alias `lts/*`, if available.
    --lts=<LTS name>                          Uses automatic alias for provided LTS line, if available.
  nvm run [<version>] [<args>]                Run `node` on <version> with <args> as arguments. Uses .nvmrc if available and version is omitted.
   The following optional arguments, if provided, must appear directly after `nvm run`:
    --silent                                  Silences stdout/stderr output
    --lts                                     Uses automatic LTS (long-term support) alias `lts/*`, if available.
    --lts=<LTS name>                          Uses automatic alias for provided LTS line, if available.
  nvm current                                 Display currently activated version of Node
  nvm ls [<version>]                          List installed versions, matching a given <version> if provided
    --no-colors                               Suppress colored output
    --no-alias                                Suppress `nvm alias` output
  nvm ls-remote [<version>]                   List remote versions available for install, matching a given <version> if provided
    --lts                                     When listing, only show LTS (long-term support) versions
    --lts=<LTS name>                          When listing, only show versions for a specific LTS line
    --no-colors                               Suppress colored output
  nvm version <version>                       Resolve the given description to a single local version
  nvm version-remote <version>                Resolve the given description to a single remote version
    --lts                                     When listing, only select from LTS (long-term support) versions
    --lts=<LTS name>                          When listing, only select from versions for a specific LTS line
  nvm deactivate                              Undo effects of `nvm` on current shell
    --silent                                  Silences stdout/stderr output
  nvm alias [<pattern>]                       Show all aliases beginning with <pattern>
    --no-colors                               Suppress colored output
  nvm alias <name> <version>                  Set an alias named <name> pointing to <version>
  nvm unalias <name>                          Deletes the alias named <name>
  nvm install-latest-npm                      Attempt to upgrade to the latest working `npm` on the current node version
  nvm reinstall-packages <version>            Reinstall global `npm` packages contained in <version> to current version
  nvm unload                                  Unload `nvm` from shell
  nvm which [current | <version>]             Display path to installed node version. Uses .nvmrc if available and version is omitted.
    --silent                                  Silences stdout/stderr output when a version is omitted
  nvm cache dir                               Display path to the cache directory for nvm
  nvm cache clear                             Empty cache directory for nvm
  nvm set-colors [<color codes>]              Set five text colors using format "yMeBg". Available when supported.
                                               Initial colors are:
                                                   g  b  y  r  e
                                               Color codes:
                                                 r/R = red / bold red
                                                 g/G = green / bold green
                                                 b/B = blue / bold blue
                                                 c/C = cyan / bold cyan
                                                 m/M = magenta / bold magenta
                                                 y/Y = yellow / bold yellow
                                                 k/K = black / bold black
                                                 e/W = light grey / white

Example:
  nvm install 8.0.0                     Install a specific version number
  nvm use 8.0                           Use the latest available 8.0.x release
  nvm run 6.10.3 app.js                 Run app.js using node 6.10.3
  nvm exec 4.8.3 node app.js            Run `node app.js` with the PATH pointing to node 4.8.3
  nvm alias default 8.1.0               Set default node version on a shell
  nvm alias default node                Always default to the latest available node version on a shell

  nvm install node                      Install the latest available version
  nvm use node                          Use the latest version
  nvm install --lts                     Install the latest LTS version
  nvm use --lts                         Use the latest LTS version

  nvm set-colors cgYmW                  Set text colors to cyan, green, bold yellow, magenta, and white

Note:
  to remove, delete, or uninstall nvm - just remove the `$NVM_DIR` folder (usually `~/.nvm`)
//}




//terminal[][windows]{
PS C:\Users\inabakazuya> nvm --help

Running version 1.1.7.

Usage:

  nvm arch                     : Show if node is running in 32 or 64 bit mode.
  nvm install <version> [arch] : The version can be a node.js version or "latest" for the latest stable version.
                                 Optionally specify whether to install the 32 or 64 bit version (defaults to system arch).
                                 Set [arch] to "all" to install 32 AND 64 bit versions.
                                 Add --insecure to the end of this command to bypass SSL validation of the remote download server.
  nvm list [available]         : List the node.js installations. Type "available" at the end to see what can be installed. Aliased as ls.
  nvm on                       : Enable node.js version management.
  nvm off                      : Disable node.js version management.
  nvm proxy [url]              : Set a proxy to use for downloads. Leave [url] blank to see the current proxy.
                                 Set [url] to "none" to remove the proxy.
  nvm node_mirror [url]        : Set the node mirror. Defaults to https://nodejs.org/dist/. Leave [url] blank to use default url.
  nvm npm_mirror [url]         : Set the npm mirror. Defaults to https://github.com/npm/cli/archive/. Leave [url] blank to default url.
  nvm uninstall <version>      : The version must be a specific version.
  nvm use [version] [arch]     : Switch to use the specified version. Optionally specify 32/64bit architecture.
                                 nvm use <arch> will continue using the selected version, but switch to 32/64 bit mode.
  nvm root [path]              : Set the directory where nvm should store different versions of node.js.
                                 If <path> is not set, the current root will be displayed.
  nvm version                  : Displays the current running version of nvm for Windows. Aliased as v.
//}

====== インストール可能なnode.jsを表示

まずは、インストール可能なNode.jsのバージョンを表示してみます。
Mac OSXの場合には、古いバージョンから最新バージョンまでが表示されます。

//terminal[][Mac OSX]{
$ >nvm ls-remote
@<balloon>{古いバージョンから全て表示される}
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

一方、Windowsの場合には、表形式で表示されます。

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

====== node.js 最新LTS版をインストール

それでは、最新のLTS版をインストールします。
インストールは、Mac、Windowsとも「nvm install インストールするバージョン番号」でインストールすることができます。

//terminal[][Mac OSX]{
$ > nvm install v14.15.2
Downloading and installing node v14.15.2...
Downloading https://nodejs.org/dist/v14.15.2/node-v14.15.2-darwin-x64.tar.xz...
################################################################################################################# 100.0%
Computing checksum with shasum -a 256
Checksums matched!
Now using node v14.15.2 (npm v6.14.9)
//}


//terminal[][]{
PS C:\Users\inabakazuya> nvm install v14.15.2
Downloading node.js version 14.15.2 (64-bit)...
Complete
Creating C:\Users\inabakazuya\AppData\Roaming\nvm\temp

Downloading npm version 6.14.9... Complete
Installing npm v6.14.9...

Installation complete. If you want to use this version, type

nvm use 14.15.2
//}

====== インストールされているnode.jsのバージョン

インストールされているnode.jsのバージョンは、「nvm ls」で表示することができます。

//terminal[][Mac OSX]{
$ > nvm ls
          v8.17.0
         v12.18.2
         v12.18.3
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
}

//terminal[][Windows]{
PS C:\Users\inabakazuya> nvm ls

    14.15.2
    14.15.1
    12.13.1
  * 8.16.1 (Currently using 64-bit executable)
//}


====== 使用するnode.jsのバージョン切り替え

先ほどの「インストールされているnode.jsのバージョン表示」で、現在使われているnode.jsのバージョンも表示されています。
使用するnode.jsのバージョンを変更する場合には、「nvm use 使用するバージョン番号」で切り替えます。

//terminal[][node.jsのバージョン確認と切替]{
$ > node -v
v14.15.2
[~]
$ > nvm use v12.18.3
Now using node v12.18.3 (npm v6.14.6)
[~]
$ > node -v
v12.18.3
//}


以上で、複数のバージョンのnode.jsを切り替えて使える環境が構築できました。


=={sec-yarn} yarn
=== yarnとは？

yarnは、nodeプロジェクトにおいて必要な機能を簡単に追加できるようにするnpm(node package manager)互換の
package management tool(パッケージ管理ツール)です。

npmと比較して
* パッケージのインストールが早い
* コマンドがnpmよりも簡潔
* npmよりもパッケージのバージョン管理がしっかりしている
などの利点があります。

==== yarnのインストール

node.jsをインストールした時点で、node.jsのパッケージ管理ツールである「npm」がインストールされています。

//terminal[][npmのバージョン確認]{
$ > npm -v
6.14.6
//}

yarnをインストールするために、この「npm」コマンドを使用します。

//terminal[][yarnのインストール]{
$ > npm install -g yarn
}

コマンドオプションの「-g」は、global指定でPC全体でコマンドが使用できるようになります。
-gオプションなしでは、そのプロジェクトでのみ有効となります。

yarnの使い方は、今後使う機会毎に説明します。

=={sec-vscode} Microsoft Visual Studio Code + 拡張機能


=={sec-chrome} Google Chrome + 拡張機能
