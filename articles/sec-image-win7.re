#@# -*- coding: utf-8 -*-

= 図を埋め込む（Windows編）

本章では前章に引き続き、図を作成する方法、原稿に埋め込む方法、および印刷用に高解像度の画像を作成する方法を紹介します。
前章の構成に沿っていますが、前章と違うのはWindowsでPowerpointを使っているところです。
OSやソフトがことなるとできることも変わってきますので、内容が簡略化されています。

=={sec-image-win7-install} Powerpointについて
PowerPointはプレゼンテーション用のスライド作成およびプレゼンテーションを行うソフトウェアです。
Officeシリーズを購入すると大体バンドルされていますが、
Office Personalには含まれていません。
#footnote https://products.office.com/ja-jp/buy/compare-microsoft-office-products?tab=1
単体で購入することもできますが、かなり割高です。
#footnote https://www.microsoft.com/ja-jp/store/collections/officesingleapps?SilentAuth=1&wa=wsignin1.0
技術同人誌を書きたいと考えている方でWindowsを利用している方は、
おそらく高確率で所有していると思われますので、インストールの細かい方法は省略します。

=={sec-image-win7-draw} Powerpointで作図する
PowerPointで作図してみましょう。
PowerPointを起動する。タイトルスライドのみの新規スライドが表示されます。
スライドを右クリックし、レイアウトを白紙に変更しましょう。
#footnote 意外にこれをやらない人が多いのです
リボンの挿入タブから図形を選択し、図形を描いてみます。
ファイルタブの名前を付けて保存を選択して、スライドを保存します。
Ctrl+Sでも保存できます。場所は、前章に倣ってimages.pptxとしておきましょう。

=={sec-image-win7-png} 図をPNG画像として保存する
PowerPointで作成した図形を画像に変換する方法は三通りあります。
 1. スライドを画像として保存する方法。ファイルタブの名前を付けて保存からファイルの種類をjpg,png,tiff,bmpを選ぶと、スライド全て、あるいは1枚だけが画像に変換されて保存されます。
 2. 図形を画像として保存する方法。保存したい図形全てを選択した状態で図形を右クリックし、図として保存するを選択すると、図として保存ダイアログから保存できます。
 3. 画像編集ソフト（ペイントなど）を使う方法。保存したい図形全てを選択した状態で図形を全てクリップボードにコピーしてペイントに貼り付けたあと、名前を付けて保存します。

保存した図形は、前章のリスト1のようにします。

=={sec-image-win7-width} 図形の幅を設定する
Re:VIEWの原稿に図を埋め込んだ際、思ったより大きく場合は、三通りの方法で大きさを調整できます。
一つ目は、Re:VIEWで画像の倍率を指定する方法です。これは前章4節、リスト2を参照してください。

二つ目は、これも前章と同じように、透明な四角形を図形の背景に置く方法です。
 1. 挿入タブの図形から四角形を選択し、画像を覆うくらいの四角形を描きます。
 2. 四角形を右クリックして最背面へ移動します。
 3. 四角形を右クリックして図形の書式設定を選び、塗りつぶしなし、線なしに設定します。
 4. 図形の書式設定からサイズを選び、図形の幅を設定します。紙面の幅に応じて幅を調整してください。このとき、単位まで書けばptでも指定できます。

三つ目は、スライドのサイズを紙面のサイズにして、狙った大きさの図を作る方法です。
 1. 新規にプレゼンテーションを作成する。
 2. デザインタブのページ設定をクリックし、ページ設定ダイアログからページのサイズと向きを指定する。このとき、メニューにあるA4やB5などを選ぶと、一回り小さいサイズのスライドになります。必ず、ユーザー設定で幅と高さを指定してください。
 3. スライドを白紙にして、図を作ります。試しにスライドの大きさをA4サイズにして先ほど作った図形を貼り付けてみると、かなり大きかった事が分かります。いい感じになるように縮小して、図として保存しましょう。

全ての方法で画像の大きさを適切に設定できます。
一つ目の方法は画像ごとの適切な大きさを見つけるのが試行錯誤的で、大変です。
二つ目と三つ目は作図の段階で大きさが分かるという点では同じです。
いちいち四角形を置くより三つ目の方が楽なように感じますがが、図形を高解像度にする際に面倒くささが変わってきます。

=={sec-image-win7-dpi} 出力される画像の解像度を上げる
前小節の方法で変換された画像は、96dpiです。
dpiの説明については前章5節を参照してください。
これはPowerpointの標準設定です。
前章では三通りの方法が説明されていましたが、そのうち三つ目、ImageMagickのconvertコマンドを使う方法はWindowsでも可能です。
ですが、ここではPowerPointの設定を変更して直接高解像度の画像を出力できるようにしてみましょう。
ただし、この方法は、本章？節で紹介した打ち、2番目の方法（名前を付けて保存する際に形式を画像にする方法）にしか反映されません。
また、この方法はレジストリと呼ばれる、Windowsの設定を一括して管理しているところを編集しますので、
万が一に備えてバックアップを取っておくことをお勧めします。


レジストリを編集するレジストリエディタを起動します。スタートメニューのプログラムとファイルの検索ボックスにregeditと入力します。
そうするとレジストリエディタが見つかるので、ダブルクリックで起動します。
ユーザーアカウント制御が割り込んで来ますが、はいを押して起動してください。
図のように、左側にフォルダのようなものが表示されています。これはキーと呼ばれ、いわゆる設定の項目を一括して管理しています。
このキー名をダブルクリックするか、フォルダアイコンの左の三角形をクリックして、キーを展開していきます。
PowerPointの解像度に関する設定は、HKEY_CURRENT_USER\Software\Microsoft\Office\14.0\PowerPoint\Optionsにありますので、
一つずつ辿っていってください。当該のキー名をクリックすると、右のペインに設定が表示されます。
ここに、画像への変換時の解像度に関する設定を追加します。
設定にかんしては、Microsoftが詳しい説明をしていますので、一読しておいてください。
右ペインで右クリックし、新規->DWARD値（32ビット）値を選択します。右クリックする位置は、書く設定の名前以外ならどこでもかまいません。
設定項目が作られるので、名前をExportBitmapResolutionとします。
この設定の名前をダブルクリックすると値の編集ができるので、標記を10進数、値のデータを300にします。
必ず標記を先に設定してください。標準の標記は16進数なので、値のデータに300を入力してから10進数に変更すると16進数の300が10進数に変換されます。
OKを押して設定を終え、レジストリエディタを終了します。
これで、PowerPointスライドを画像として保存するときの解像度が30dpiに変更されました。

いちいちレジストリエディタを開くのは面倒ですが、レジストリには、ファイルに書かれた設定を取り込む機能があります。
レジストリの設定（拡張子が.reg）が記録された登録ファイルをダブルクリックするだけで、設定が取り込まれます。
私の手元で用意できる環境用（Windows7 64bit、PowerPoint2010）の登録ファイルを用意しています。
使い方は、登録ファイル（ExportBitmapResolution_300dpi_win7_x64_office2010.reg）をダウンロードし、Officeを終了した状態でファイルをダブルクリックするだけです。
あくまで情報提供として用意しているだけなので、くれぐれも自己責任でお願いします。

試しに出力を比べてみましょう。
なにも設定しない場合（96dpi）のとき、出力された画像ファイルのサイズは960x720ピクセルでしたが、
解像度を300dpiに指定すると、画像ファイルが3000x2250ピクセルになりました。
一度解像度の設定をすると、後なにも気にせず高解像度の画像として保存できるのでとても楽なのですが、
先に述べたとおり、スライドを画像として保存する場合にしか有効にならず、
図形を右クリックして図として保存したり、図形をコピーしてペイントなどに貼り付ける場合には、相変わらず96dpiになってしまいます。
そのため、「高解像度の図形の画像」が欲しい場合には、画像に変換されたスライドをペイントなどでトリミングする必要があります。

Windows版のPowerpointにはサイズの制約があり、307dpi、3072 × 2304ピクセルが上限です。

=={sec-image-win7-switch} 低解像度画像と高解像度画像の切り替え
画像の解像度が高くなるとファイルサイズが増え、原稿のPDFファイルを作るのに時間がかかるようになります。
これは非常に大きなストレスになるので、前章では、原稿執筆中に低解像度の画像を参照するようにし、
原稿が完成して印刷用のPDFを作る際にだけ高解像度の画像を参照する方法が提案されています。
それを実現する方法として、低解像度用のフォルダ（images_low）と高解像度用のフォルダ（images_high）を用意し、
Re:VIEWが画像を参照するフォルダ（images）をシンボリックリンクで表現して切り替えます。
あまり知られていませんが、Windowsでもシンボリックリンクを作ることができるので、この方法が使えます。

Windowsでシンボリックリンクを作るにはmklinkコマンドを使います。
mklinkでフォルダのシンボリックリンクを作るには、mklink /d リンク名 リンクされるフォルダ とします。
フォルダへのリンクを解除するにはフォルダを削除する時と同じようにrmdirコマンドを使います。
rmdir リンク名
低解像度の画像を使う場合には次のように実行します。
rmdir images
mklink /D images images_low
高解像度の画像に切り替えるには
rmdir images
mklink /D images images_high
とします。rmdirはフォルダを削除するコマンドなので、リンク先のフォルダまで削除されるのではと少し怖くなりますが、それはありませんし、
rmdirは空でないディレクトリの削除はできません。
なお、シンボリックリンクを作るには管理者としてコマンドプロンプトを実行する必要があります。
コマンドプロンプトを管理者として実行するには、スタートメニューから全てのプログラム->アクセサリと辿り、コマンドプロンプトを右クリックして管理者として実行を選択します。
PowerShellをコマンドプロンプトから呼ぶことで昇格することもできます。
powershell -command "Smart-Process -Verb runas cmd"
残念なことに、同一コマンドプロンプト内で昇格することはできず、必ず新しいコマンドプロントが起動されます。
そのため、VSCodeの統合ターミナル内だけでシンボリックリンクを張ったり削除したりすることはできません。

=={sec-image-win7-summary} まとめ
本章では前章のmacOSに引き続き、Windowsで画像を作る方法を紹介しました。
Powerpointで描いた図を画像として保存してpdfに埋め込みます。
何通りかのやり方を示しましたので、いくつか試してやりやすいやり方を見つけてください。
ここで伝えたいことは、高価な画像処理ソフトを買わなくても何とかなるということです。
他のWindowsやPowerpointのバージョンで本章の内容を試された方、他によいやり方を知っている、プロ級だがやり方を公開してやるよという方がいれば、ぜひ公開してください。