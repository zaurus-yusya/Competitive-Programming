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
//kentyon
ld ans = 0;
void calc(ld a, ld b, ld c, ld sousa, ld kakuritu){
    if(a == 100 || b == 100 || c == 100){
        ans += (ld)sousa * kakuritu;
        //cout << sousa << " " << kakuritu << endl;
        //cout << ans << endl;
    }else{
        //a
        ld tmp = 0;
        tmp = a / (a+b+c);
        calc(a+1, b, c, sousa + 1, kakuritu * tmp);
        //b
        tmp = b / (a+b+c);
        calc(a, b+1, c, sousa + 1, kakuritu * tmp);
        //c
        tmp = c / (a+b+c);
        calc(a, b, c+1, sousa + 1, kakuritu * tmp);
    }
    
}

ld dp[105][105][105];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b, c; cin >> a >> b >> c;

    ll A = 100 - a;
    ll B = 100 - b;
    ll C = 100 - c;

    dp[a][b][c] = 1;

    for(ll i = 0; i <= 100; i++){
        for(ll j = 0; j <= 100; j++){
            for(ll k = 0; k <= 100; k++){
                if(i + j + k == 0){
                    continue;
                }
                if(dp[i][j][k] == 0){
                    continue;
                }
                ld tmpi = (ld)i / (ld)(i+j+k);
                ld tmpj = (ld)j / (ld)(i+j+k);
                ld tmpk = (ld)k / (ld)(i+j+k);
                
                dp[i+1][j][k] += dp[i][j][k] * tmpi;
                dp[i][j+1][k] += dp[i][j][k] * tmpj;
                dp[i][j][k+1] += dp[i][j][k] * tmpk;
                if(i == 99 && j == 99 && k == 99){
                    cout << "-" << endl;
                    cout << dp[i][j][k] << endl;
                    cout << tmpi << endl;
                    cout << dp[i+1][j][k] << endl;
                }
            }
        }
    }
    /*
    cout << dp[99][99][99] << endl;
    cout << dp[100][99][99] << endl;
    */


    ld ans2 = 0;
    rep(j, 100){
        rep(k, 100){
            if(dp[100][j][k] == 0) continue;
            ll sousa = (100-i) + (b-j) + (c-k);
            ans2 += max(sousa, (ll)0) * dp[100][j][k];
        }
    }
    cout << ans2 << endl;
    rep(i, 100){
        rep(k, 100){
            if(dp[i][100][k] == 0) continue;
            ll sousa = 100 - i - k;
            ans2 += max(sousa, (ll)0) * dp[i][100][k];
        }
    }
    cout << ans2 << endl;
    rep(i, 100){
        rep(j, 100){
            if(dp[i][j][100] == 0) continue;
            ll sousa = 100 - i - j;
            ans2 += max(sousa, (ll)0) * dp[i][j][100];
        }
    }
    cout << ans2 << endl;


    /*
    calc(a, b, c, (ll)0, (ld)1);
    cout << ans << endl;
    */

}