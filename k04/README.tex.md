# 課題4 レポート

bb35319037 平松響

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
1~4.ヘッダファイルを読み込む
6~11.構造体を定義する
13.main関数が始まる
15~17.引数を宣言
18.FILE構造体のポインタを宣言
19.構造体の名前を新しい名前に変更
21~25.ファイルを入力する
26~30.ファイルが入らなかったら、失敗と書く
32。空読みする
33~37.ストリームから1行読み込み,何も入ってなかったら、それぞれの引数に入力することを繰り返す。
38~42.クローズできなかったら、エラーがあったことを示し、プログラムを終了させる
43~45.fnameの指すバッファに格納する
46.文を出力する
47.オープンして、ｆｐにポインタを代入する
48~52.ｆｐに何も入っていなかったら、エラーがでたことを表示する
54.iを初期化する
55~59.ストリームから1行読み込み,何も入ってなかったら、それぞれの引数に入力することを繰り返す
60~64.クローズできなかったら、エラーがあったことを示し、プログラムを終了させる
65.文字を出力する
66.特定の文字を入力させる
67.iを初期化
69.while文で14周suru
71.構造体の中に入力したidと一致したら、次に進み、一致しなかったら終了。
73.一致していたら、引数に１を代入
74~81.idが一致していて、genderが１なら、id,male,heightを出力し、それ以外はid,female,heightを出力する。
84.i=i+1する
86,86.idが見つからなかったら、見つからなかったことを示す。
88.main関数が終了




## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```
input the filename of sample_heght;c:/Users/kyo/Downloads/Excel練習問題/35319037/2020psp2/sample/heights.csv
the filename of sample_ID:c:/Users/kyo/Downloads/Excel練習問題/35319037/2020psp2/sample/heights.csv
input filename of sample ID:c:\Users\kyo\Downloads\Excel練習問題\35319037\2020psp2\sample\IDs.csv
filename of sample:c:\Users\kyo\Downloads\Excel練習問題\35319037\2020psp2\sample\IDs.csv
which ID's data do you want?
45313124
No data

input the filename of sample_heght;c:/Users/kyo/Downloads/Excel練習問題/35319037/2020psp2/sample/heights.csv
the filename of sample_ID:c:/Users/kyo/Downloads/Excel練習問題/35319037/2020psp2/sample/heights.csv
input filename of sample ID:c:\Users\kyo\Downloads\Excel練習問題\35319037\2020psp2\sample\IDs.csv
filename of sample:c:\Users\kyo\Downloads\Excel練習問題\35319037\2020psp2\sample\IDs.csv
which ID's data do you want?
45313125
ID:45313125 gender:female height:152.400000
## 修正履歴

[comment0729宮下]
出力が例と異なっています。空読みができていないようです。
- L32 fgets(fname,sizeof(fname),stderr);　ではなく　fgets(buf, sizeof(buf),fp);　です。

[comment0730宮下]

課題提出お疲れさまでした！修正点はありません。k04完了です。