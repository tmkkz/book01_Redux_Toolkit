= はじめに

このたびは、「やる夫で学ぶ-Redux- Redux Toolkitは簡単だお･･･」を手にしていただき、誠にありがとうございます。

//blankline
最初に、この本を書くきっかけになった「2chのやる夫スレ」に投稿された皆様と、
「AAスレ作成アプリAAストーリーボード」を開発されたtkg様に感謝します。

//image[r401][][scale=0.5,pos=H]

//image[greetings][][scale=0.8]
//blankline
//blankline
私は15年近く、Visual Studio上でC#を使ってUIのあるプログラムを書いていました。
最近は、同一コードでマルチプラットフォーム上で動作するアプリケーションの構築は幾通りもの方法がありますが、
以前は方法が限られていました。

//blankline
あるとき、あるプロジェクトでは「Windows、Mac上にて同一UIで動作」が要求されました。
そのために選択したのが、ブラウザ上で動作するWebアプリケーションです。

//blankline
さらに、Webアプリケーションではローカルファイルにアクセスできないため、Electronを使用することで、
Webアプリケーションをマルチプラットフォームで動作するアプリケーションにしました。

//blankline
当時はWebアプリケーションのフレームワークとしてAngularとReactが候補に挙がりましたが、
Reactの方が学習コストが低いと言われていたため、Reactを学びました。

学習コストが低いとはいえ、壁にブチ当たるたび、時間をかけて調べることを繰り返しました。
//image[greetings02][][scale=0.7,pos=H]

//blankline
本書は、私がReactやReduxを使い始めたときに「こんな本があれば良かったのに･･･」を目指して書きました。
React、Reduxの初学者から中級の方のお役に立てれば幸いです。

//blankline
React、Reduxの解説書やチュートリアルは、書籍・インターネット上にたくさんあります。
しかし、つぎつぎと新機能が追加され、本家以外の情報はあっという間に古くなってしまいます。
この書籍は掲載情報を最新にするため、電子書籍のみとし、古くなった情報は随時更新していきたいと思っています。

//image[greetings03][][scale=0.7,pos=H]

お気付きの点がございましたら、GitHub上へお寄せください。

//blankline
#@#<!-- textlint-disable -->
本書は、フロントエンド開発で使用されている
#@#<!-- textlint-enable -->

 * react
 * redux(redux-toolkit)
を習得するために、開発環境の作成(つまりゼロ)から始め、読書日記アプリケーションを作成します。

//blankline
すでに開発環境を整えている方は、第1章、第2章を飛ばしてもかまいません。

//blankline
また、ゼロからの環境構築、サンプルアプリケーションはGitHubに公開していますが、こちらも最新の情報に更新していくつもりです。
GitHubでは、章毎に別ブランチにしてありますので、写経がメンドウな方は章に対応したブランチを使ってください。

//blankline
git、GitHubの使い方については、本書では取り扱いません。


//blankline
#@#<!-- textlint-disable -->
本書は、チュートリアルによくあるToDoリストを日記アプリケーションとし、
#@#<!-- textlint-enable -->

 1. Reduxなしで作成
 2. Reduxを導入
 3. Redux Toolkitを導入

と書き換えていくことで、Reduxを用いた「状態管理(アプリケーション全体でのデータ)」を
理解してもらえるようになっています。


//blankline
必要なものは、すべて無料でそろえることができる以下のものです。これらが何なのか、そして、インストール方法は
第１章にて解説しています。

 * Node.js
 * yarn（npmを使われる方は不要）
 * Microsoft Visual Studio code
 * Google Chrome

//blankline
それでは、始めていきましょう。

//image[greetings04][][scale=1.0]
