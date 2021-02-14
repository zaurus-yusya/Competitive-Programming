#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll b, c; cin >> b >> c;
    
    if(c == 1){
        if(b == 0) cout << 1 << endl;
        else cout << 2 << endl;
        return 0;
    }
    
    if(b > 0){
        //0が重なるか
        if(c / 2 >= b){
            //重なる
            ll mi = (b * (-1)) - (c-1)/2; // *-1 ひたすら引く
            ll ma = ( (b * (-1)) - (c-2)/2 ) * (-1); // *-1 ひたすら引く *-1
            cout << ma - mi + 1 << endl;
        }else{
            //重ならない
            ll mi_n = (b * (-1)) - (c-1)/2; // *-1 ひたすら引く
            ll ma_n = (b - (c-1)/2 ) * (-1); //ひたすら引く *-1

            ll mi_p = b - c/2; //ひたすら引く
            ll ma_p = ((b * (-1)) - (c-2)/2 ) * (-1); // *-1 ひたすら引く *-1

            cout << ma_n - mi_n + 1 + ma_p - mi_p + 1 << endl;
        }
    }else{
        //0が重なるか
        if(x >= b*(-1)){
            //重なる
            ll mi = b - c/2; //ひたすら引く
            ll ma = (b - (c-1)/2) * (-1); // ひたすら引く *-1
            cout << ma - mi + 1 << endl;
        }else{
            //重ならない
            ll mi_n = b - c/2; //ひたすら引く
            ll ma_n = ( (b * (-1)) - (c-2) / 2 ) * (-1); // *-1 ひたすら引く *-1

            ll mi_p = (b*(-1)) - (c-1)/2; // *-1 ひたすら引く
            ll ma_p = (b - (c-1)/2) * (-1); // ひたすら引く *-1

            cout << ma_p - mi_p + 1 + ma_n - mi_n + 1 << endl;
        }
    }

}