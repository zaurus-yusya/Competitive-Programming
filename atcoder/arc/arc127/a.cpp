#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

//i番目まで見て、未満かどうか、1が続いてるかどうか、最後の数値がlの総数、f(n)がmの個数
ll dp[20][2][2][10][20];


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    ll keta = get_digit(n);
    string s = to_string(n);

    ll ans = 0;
    for(ll x = 1; x <= keta; x++){
        if(x != keta){
            //絶対未満
            ll tmp = 1; bool f = true;
            for(ll j = x; j >= x; j--){
                ans += j * tmp;
                if(f){
                    tmp *= 9;
                }else{
                    tmp *= 10;
                }
            }
        }else{
            dp[0][0][1][1][0] = 1;
            for(ll i = 0; i < keta; i++){
                ll num = s[i] - '0'; //stringの数値を文字列型
                for(ll smaller = 0; smaller < 2; smaller++){ //smaller: 未満フラグ
                    for(ll k = 0; k < 2; k++){ //1が続いてるかどうか
                        for(ll j = 0; j <= (smaller ? 9 : num); j++){
                            for(ll l = 0; l <= 9; l++){
                                for(ll m = 0; m <= keta; m++){
                                    if(k == 1 && l == 1 && j == 1){
                                        dp[i+1][smaller || (j < num)][k && (j == 1)][j][m+1] += dp[i][smaller][k][l][m];
                                    }else{
                                        dp[i+1][smaller || (j < num)][k && (j == 1)][j][m] += dp[i][smaller][k][l][m];
                                    }
                                }
                            }
                        }
                    }
                }
            }
            // //未満考慮
            // dp[1][0][1][1] = 1;
            // //dp[1][1][1][1] = 1;
            // for(ll i = 1; i < keta; i++){
            //     ll num = s[i] - '0'; //stringの数値を文字列型
            //     for(ll smaller = 0; smaller < 2; smaller++){ //smaller: 未満フラグ
            //         for(ll j = 0; j <= (smaller ? 9 : num); j++){ //後の数字
            //             for(ll k = 0; k <= 9; k++){ //前の数字がk
            //                 for(ll l = 0; l <= keta; l++){ //f(n)の値
            //                     if(i == 1 && j == 0) continue;
            //                     if(j == 1 && k == 1){
            //                         dp[i+1][smaller || (j < num)][j][l+1] += dp[i][smaller || (j < num)][k][l];
            //                     }else{
            //                         dp[i+1][smaller || (j < num)][j][l] += dp[i][smaller || (j < num)][k][l];
            //                     }
            //                     //dp[i+1][smaller || (j < num)][k][l] += dp[i][smaller][k][l];
            //                 }
            //             }
            //         }
            //     }
            // }
        }
    }

    for(ll j = 0; j < 2; j++){
        for(ll k = 0; k < 2; k++){
            for(ll l = 0; l < 10; l++){
                for(ll m = 0; m <= keta; m++){
                    ans += dp[keta][j][k][l][m] * m;
                    cout << j << " " << k << " " << l << " " << m << " " << dp[keta][j][k][l][m] << endl;
                }
                
                
            }
        }
    }

    //i番目まで見て、未満かどうか、1が続いてるかどうか、最後の数値がlの総数、f(n)がmの個数
    cout << dp[1][0][1][1][1] << endl;
    cout << dp[2][0][0][2][1] << endl;

    cout << ans << endl;


    //hinagata
    //move to global
    //第3引数を適宜問題に応じて追加
    // ll dp[100010][2];
    // dp[0][0] = 1;
    
    // for(ll i = 0; i < keta; i++){
    //     ll num = s[i] - '0'; //stringの数値を文字列型
    //     for(ll smaller = 0; smaller < 2; smaller++){ //smaller: 未満フラグ
    //         for(ll j = 0; j <= (smaller ? 9 : num); j++){
    //             dp[i+1][smaller || (j < num)] += dp[i][smaller];
    //         }
    //     }
    // }


}