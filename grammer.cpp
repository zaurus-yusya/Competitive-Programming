//include関係 (最初に記述するとライブラリとか全部入る)

#include <bits/stdc++.h>
using namespace std;

int main() {

}

//vscodeでターミナル起動
//ctrl shift '

//c++ 17 コンパイルコマンド
//g++ -std=c++1z test.cpp


//print文
cout << "Hello, world!" << endl;  //改行あり
cout << "Hello, world!" ;  //改行なし
cout << "c" << "d";  //こういう書き方もできる
cout << "c" << 100 << "d";  //こういう書き方もできる
printf("%.10f\n", ans) //小数10ケタ


//標準入力　スペースか改行で区切ってくれる
int a, b, c;
cin >> a >> b >> c;

string text;
double d;
cin >> text;
cin >> d;

//行を受け取る
string s, t;
getline(cin, s); //1行目を受け取る
getline(cin, t); //2行目を受け取る

cin >> vec.at(0) >> vec.at(1) >> vec.at(2);    //配列で入力を受けることもできる

for (int i = 0; i < 100; i++) {                //for文と配列で入力を受けることもできる
    cin >> vec.at(i);
}


//if文
if(){

}else if(){

}else{

}


//演算子
x == y	//xとyは等しい
x != y	//xとyは等しくない
x > y	  //xはyより大きい
x < y	  //xはyより小さい
x >= y	//xはy以上
x <= y	//xはy以下

!( )         //条件式の結果の反転 条件式が偽
( ) && ( )   //and演算子
( ) || ( )	 //or演算子

// ( 条件式 ? 真 : 偽)


//変数のスコープ
//変数は{}の中でしか有効ではない


//while文
while(){

}


//for文
for (int i = 0; i < N; i++) {
  
}
//範囲for文
for (int x : a) {
    cout << x << endl;
}
//範囲for文は型省略できる(elemはbの型になる)
for (auto elem : b) {
  cout << elem << endl;
}



//文字列関係
//string型 ： ""
//char型 : ''
str.size()  //文字列の長さ
"Hello"s.size()  //変数じゃ無い場合はこのように末尾にsをつける
str.at(i)   //i文字目にアクセス

//文字列の一部を書き換えるときはchar型を使う
str = "Hello"
str.at(0) = 'M';

//string型、char型は全角文字はうまく使えない
//stringとcharは==とかで比較できない
//　でも+とかで文字列を結合することはできる


//配列
vector<int> vec;          //配列の宣言
vec = { 25, 100, 64 };    //配列への代入
vec.size()                //配列の要素数
vec.at(i)                 //配列のi番目にアクセス

vector<int> vec(3);   //要素数3の配列{0,0,0}を宣言
vector<string> vec(3);   //要素数3の配列{"","",""}を宣言
vector<int> vec(3, 5);   //{5,5,5}で初期化された配列を宣言
vector<vector<string>> vec(h, vector<string>(w));  //二次元配列の宣言例
vector<vector<ll>> vec(h, vector<ll>(w));
vector<vector<vector<char>>> data(N, vector<vector<char>>(3, vector<char>(3))); //3次元配列

ll dp[n+1][w+1] = {}; //ただの配列0初期化

vec.push_back(10);   //末尾に追加(この場合10)
vec.pop_back();      //末尾の要素を削除

vector<vector<要素の型>> 変数名(縦の要素数, vector<要素の型>(横の要素数));
//例 vector<vector<string>> vec(h, vector<string>(w));

vec.resize(n)             //配列の要素数変更
vec.resize(h, vector<string>(w));　　　　//二次元配列の要素数変更

vec.assign(3,1)   //vecの内容は{1,1,1}

sort(配列変数.begin(), 配列変数.end()); //小さい順にソート

bool cmp(ll a, ll b){
  return a < b;
}
sort(配列変数.begin(), 配列変数.end(), cmp); //自作関数でソート(自作関数はbool)
sort(all(vec),greater<ll>());  //sort 降順


//参照
int a = 3;
int &b = a;  // bは変数aの参照

int a = 123;
int& b = a;  // 変数aへの参照
int& c = b;  // 変数aへの参照

int g(int& x) {
  x = x * 2;  // xを2倍 (参照によって"呼び出す側の変数"が変更される)
  return x;
} 
int main() {
  int a = 3;  // 関数を呼び出す側の変数
  int b = g(a);  // xの参照先がaになる
  cout << "a: " << a << endl;       // 6
  cout << "b: " << b << endl;       // 6
}

//関数で複数の値を返したいときとかに使えるらしい
// a,b,cの最大値、最小値をそれぞれminimumの参照先、maximumの参照先に代入する
void min_and_max(int a, int b, int c, int &minimum, int &maximum) {
  minimum = min(a, min(b, c));  // 最小値をminimumの参照先に代入
  maximum = max(a, max(b, c));  // 最大値をmaximumの参照先に代入
}
int main() {
  int minimum, maximum;
  min_and_max(3, 1, 5, minimum, maximum);  // minimum, maximumを参照渡し
  cout << "minimum: " <<  minimum << endl;  // 最小値
  cout << "maximum: " <<  maximum << endl;  // 最大値
}

//配列を複数回渡す時、普通のやり方だとコピーが発生して時間がかかる

vector<int> a = {1, 3, 2, 5};
for (int &x : a) {
  x = x * 2;
}
// aは{2, 6, 4, 10}となる


//再帰
int sum(int n) {
  // ベースケース
  if (n == 0) {
    return 0;
  }

  // 再帰ステップ
  int s = sum(n - 1);
  return s + n;
}


//️数値型
int -2147483648 ~ 2147483647
int64_t -9223372036854775808 ~ 9223372036854775807

//double型を出力するとき
cout << 3.14159265358979 << endl;
cout << fixed << setprecision(桁数);

//キャスト
(double)a
(int)b
to_string(number)  //int->string
stoi(s)            //string->int
stoi(s)            //string->double


//️型
//pair<値1の型, 値2の型> 変数名;
//変数名.firstで1番目の値、変数名.secondで2番目の値
make_pair(値1, 値2)でpairを生成
tie(変数1, 変数2) = pair型の値;
//tuple  // 複数個

pair<string, int> p("abc", 3);
p = make_pair("*", 1);
string s;
int a;
tie(s, a) = p;

//型エイリアス
using pii = pair<int, int>;

//map
//map<Keyの型, Valueの型> 変数名;
//変数名[key] = value;
//変数名.erase(key);	
//変数名.at(key)
//変数名.count(key)
//変数名.size()
//mapの要素の出力
for(auto i: mp){
    cout << i.first << endl;  //key
    cout << i.second << endl; //value
}


//キュー
//宣言
queue<int> que;
que.push(0); //queの一番後ろに値(この場合0を追加)
que.front(); //queの先頭の値を取り出す(削除はされない)
que.pop(); //queの先頭を削除

//priority_que
priority_queue<int> que; //降順
priority_queue<int, vector<int>, greater<int>> que;
