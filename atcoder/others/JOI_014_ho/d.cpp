#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<ll> d(n);
    vector<ll> c(m);
    rep(i, n){
        cin >> d[i];
    }
    rep(i, m){
        cin >> c[i];
    }
    
    ll dp[n+1][m+1]; //都市、日
    rep(i, n+1)rep(j, m+1) dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i, m){//日
        rep(j, n){//都市
            //移動する
            dp[j+1][i+1] = min(dp[j+1][i+1], dp[j][i] + d[j]*c[i]);
            //待機する
            dp[j][i+1] = min(dp[j][i], dp[j][i+1]);
        }
        
    }

    /*
    rep(i, n+1){
        rep(j, m+1){
            cout << dp[i][j] << " ";
        }
        br;
    }
    */

    ll ans = INF;
    rep(i, m+1){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;

}