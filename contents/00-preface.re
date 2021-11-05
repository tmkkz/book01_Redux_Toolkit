= はじめに

このたびは、「やる夫で学ぶ-Redux- Redux Toolkitは簡単だお･･･」を、手にしていただき誠にありがとうございます。
@<br>{}
@<br>{}
私は15年近くVisual Studio上でC#を使ってUIのあるプログラムを書いていました。
しかし、世の中の流れは同一コードでマルチプラットフォーム上で動作するアプリケーションに向かっています。
@<br>{}
今では、Microsoft .NETがマルチプラットフォームで動作するようになり、UIなども充実し始めています。
@<br>{}
しかし、あるプロジェクトは、「Windows、Mac上にて同一UIで動作」
そのために選択したのが、ブラウザ上で動作するWebアプリケーションです。
@<br>{}
さらに、Webアプリケーションではローカルファイルにアクセスできないため、Electronを使用することで、
Webアプリケーションをマルチプラットフォームで動作するアプリケーションにしました。

当時は、WebアプリケーションのフレームワークとしてAngularとReactが候補に挙がりましたが、
Reactの方が学習コストが低いと言われていたため、Reactを学びました。

本書は、私がReactやReduxを使い始めたときに「こんな本があれば良かったのに･･･」を目指して書きました。
React,Reduxの初学者から中級の方のお役に立てれば幸いです。

そして、私が一番欲しかった「常に最新の情報」を掲載していきたいと思っています。

React、Reduxの解説書やチュートリアルは、書籍・インターネット上にたくさんあります。
しかし、つぎつぎと新機能が追加され本家以外の情報は、あっという間に古くなってしまいます。
この書籍は、掲載情報を最新にするために電子書籍のみとし、古くなった情報は随時更新していきたいと思っています。

お気付き点がございましたら、Guthub上へお寄せください。


本書は、フロントエンド開発で使用されている@<br>{}
 * react
 * redux(redux-toolkit)

を習得するために、開発環境の作成(つまりゼロ)から始め、チュートリアルの定番のToDoリストを作成します。

すでに開発環境を整えている方は、第1章を飛ばしてもかまいません。


また、作成するToDoアプリケーションはGutHubに公開していますが、こちらも最新の情報に更新していくつもりです。
GutHubでは、章毎に別ブランチにしてありますので、写経がメンドウな方は章に対応したブランチを使ってください。

Git、GitHubの使い方については、本書では取り扱いません。



本書は、チュートリアルによくあるToDoリストを@<br>{}

 1. Reduxなしで作成
 2. Reduxを導入
 3. Redux Toolkitを導入

と、書き換えていくことでReduxを用いた「状態管理(アプリケーション全体でのデータ)」を
理解してもらえるようになっています。

　create-react-appを使用して、ゼロからの手順を解説しています。写経がメンドウな人は、
GitHubにあるコードを使ってください。


必要なものは、すべて無料でそろえることができる以下のものです。これらが何なのか、そして、インストール方法は
第１章にて解説しています。
　* Node.js
　* yarn（npmを使われる方は不要）
　* Microsoft Visual Studio code
　* Google Chrome

それでは、始めていきましょう。
