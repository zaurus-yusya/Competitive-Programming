#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
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
// If the result in local and judge is different, USE CODETEST!!


ld dp[105][105][105];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b, c; cin >> a >> b >> c;
    bool af = a, bf = b, cf = c;

    

    for(ll i = 99; i >= 0; i--){
        for(ll j = 99; j >= 0; j--){
            for(ll k = 99; k >= 0; k--){
                dp[i][j][k] = (dp[i+1][j][k] + 1) * (ld)i/(ld)(i+j+k)
                            + (dp[i][j+1][k] + 1) * (ld)j/(ld)(i+j+k)
                            + (dp[i][j][k+1] + 1) * (ld)k/(ld)(i+j+k);
            }
        }
    }

    cout << dp[a][b][c] << endl;

    /*
    dp[a][b][c] = 1;
    for(ll i = 0; i <= 100; i++){
        for(ll j = 0; j <= 100; j++){
            for(ll k = 0; k <= 100; k++){
                if(i+j+k-1 == 0) continue;
                if(af){//aを選ぶ
                    if(i-1 >= 0 && j != 100 && k != 100){
                        dp[i][j][k] += dp[i-1][j][k] * (ld)(i-1) / (ld)(i+j+k-1);
                    }
                }
                if(bf){//bを選ぶ
                    if(j-1 >= 0 && i != 100 && k != 100){
                        dp[i][j][k] += dp[i][j-1][k] * (ld)(j-1) / (ld)(i+j+k-1);
                    }
                }
                if(cf){//cを選ぶ
                    if(k-1 >= 0 && i != 100 && j != 100){
                        dp[i][j][k] += dp[i][j][k-1] * (ld)(k-1) / (ld)(i+j+k-1);
                    }
                }
            }
        }
    }

    ld ans = 0;
    for(ll j = 0; j <= 99; j++){
        for(ll k = 0; k <= 99; k++){
            ans +=  (ld)(100+j+k - a - b - c) * dp[100][j][k];
        }
    }
    for(ll i = 0; i <= 99; i++){
        for(ll k = 0; k <= 99; k++){
            ans += (ld)(i+100+k - a - b - c) * dp[i][100][k];
        }
    }
    for(ll i = 0; i <= 99; i++){
        for(ll j = 0; j <= 99; j++){
            ans += (ld)(i+j+100 - a - b - c) * dp[i][j][100];
        }
    }
    cout << ans << endl;
    */

}