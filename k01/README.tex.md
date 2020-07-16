# 課題1 レポート

bb35319037 平松響

## 課題

標本男性の平均と分散を求めよ．また，「適当に選んだ」と言っても所詮聞く相手は周辺の同年代の同じ学部の友達に限定されそうである．周辺に住んでる同年代の工学部の男性の平均と分散を推定せよ．また，この推定される平均値は標本のとるたびに異なるので確率変数であり，今回推定した平均には誤差がある．その誤差（標準誤差）を求めよ．
   
標本平均$\bar{x}$は$\bar{x}=\dfrac{1}{N}\sum_{i=1}^{N}x_{i}$で求められる．また，標本分散$s^2$は$s^2=\dfrac{1}{N}\sum_{i=1}^{N}\left(x_{i}-\bar{x}\right)^2$もしくは，$s^2=\bar{x^2}-\left(\bar{x}\right)^2$で求められるのも有名な事実である．

しかし，プログラムでこれを計算する際に少し問題が出てくる可能性がある．実は上述の相加平均というのは先ず総和を計算してみる必要がある．最終的な相加平均はデータと同じくらいに小さく収まるが，総和はバカデカくなる可能性がある．バカデカいと計算機で扱えない数値になる可能性があるのだ．そこでデータを増やすたびに平均を更新していくという方法を取る．つまり今，$N$個のデータがあるわけだが，$N-1$個目までの平均$\bar{x}_{N-1}$を使って$\bar{x}_{N}$を作る関数 `double ave_online(double val,double ave)` を作ってみよう．また分散についても `var_online`を作ってみよう．
   
$$ \bar{x}_{N} = \frac{1}{N}\sum_{i=1}^{N} x_{i} = \frac{1}{N} \left\{\sum_{i=1}^{N-1}x_{i} + x_{N}\right\} = \frac{1}{N}\left\{(N-1)\bar{x}_{N-1} + x_{N}\right\}$$
   
つまり，$\bar{x}_{N} = \dfrac{N-1}{N} \bar{x}_{N-1} + \dfrac{1}{N} x_{N}$．この場合はバカデカい数値が計算に現れなくなる．
   
分散のほうはどうであろうか．$N-1$個目までの分散$s^2_{N-1}$を使って$s^2_{N}$を作れるだろうか．
   
$$ s^2_{N} = \frac{N-1}{N} s^2_{N-1} + \frac{1}{N} (x_{N}-\bar{x}_{N})^2$$
と考えたら大きな間違いである．
   
$$ s^2_{N} = \frac{1}{N}\sum_{i=1}^{N}\left(x_{i}-\bar{x}_{N}\right)^2 = \frac{1}{N}\left\{\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N})^2 + (x_{N}-\bar{x}_N)^2\right\} = \frac{1}{N}\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N})^2 + \frac{1}{N}(x_{N}-\bar{x}_N)^2$$
だが，$\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N})^2$は$(N-1)s^2_{N-1}$ではない．$(N-1)s^2_{N-1}=\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N-1})^2$なのだ．

そこで，もう一つの分散の計算方法で考えてみる．
$$ s^2_{N} = \bar{x^2}_{N}-\left(\bar{x}_{N}\right)^2 = \left\{\dfrac{N-1}{N}\bar{x^2}_{N-1} + \dfrac{1}{N} x^2_{N} \right\}-\left(\dfrac{N-1}{N} \bar{x}_{N-1} + \dfrac{1}{N} x_{N}\right)^2 $$
つまり，$\bar{x^2}_{N-1}$と$\bar{x}_{N-1}$と$x_{N}$があれば，$s^2_{N}$を求める関数ができる．`double var_online(double val, double ave, double square_ave)`

また，母集団の分散$u^$は標本の分散$s^2$と標本サイズ$N$から「推定」できる．所謂，不偏分散である．
$$u^2=\dfrac{1}{N-1}\sum_{i=1}^{N}\left(x_{i}-\bar{x}\right)^2=\dfrac{N}{N-1}s^2$$
一方，母集団の平均の推定値は，標本の平均$\bar{x}$が最良である．

標準誤差（standard error）は，$\sqrt{\dfrac{u^2}{n}}$で求めることができる．

したがって，今回の課題について，

|統計量|値|
|---|---|
|標本平均|$173.89$|
|標本分散|$25.36$|
|母集団平均|$173.89\pm 1.90$|
|母集団分散|$28.98$|

## ソースコードの説明
6.関数ave_onlineのプロトタイプ宣言
7.関数val_onlineのプロトタイプ宣言
14~16.引数の宣言
32.i（valの数）を＋１する
35.varにvar_onlineの値を代入する
35.aveにave_onlineの値を代入する
36.valをvalの二乗して、ave_onlineの値をsquare_aveに代入する
47var_hにvarをi/i-1をかけたものを代入する
48.aveを出力する
49.varを出力する
50.var_hを出力する
51aveを出力する
58.プロトタイプ宣言したave_onlineの内容を書き始める
60.ave_Onlineに(((i-1)*ave/i) + (val/i))を返す
63.プロトタイプ宣言したvar_onlineの内容を書き始める
65.var_onlineに(((i-1)*square_ave/i)+pow(val,2)/i)-pow((((i-1)*ave/i)+(val/i)),2)を返す

## 入出力結果

```
input the filename of sample:../sample/heights_male.csv
the filename of sample: ../sample/heights_male.csv
sample mean：1
sample variance：
population mean (estimated)：
population variance (estimated)：
```
ave=173.888750
var=25.361711
h_var=28.984813
h_ave=173.888750

## 修正履歴

説明は「かきくけこ」だ！
