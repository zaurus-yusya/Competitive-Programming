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
    ll n; cin >> n;
    vector<vector<string>> s(5, vector<string>(n));
    rep(i, 5){
        string t; cin >> t;
        rep(j, n){
            s[i][j] = t[j];
        }
    }

    vector<vector<ll>> dp(3, vector<ll>(n+1, INF));
    rep(i, 3) dp[i][0] = 0;

    vector<string> color_masta = {"R", "B", "W"};
    rep(i, n){
        rep(j, 3){
            ll cnt = 0;
            rep(k, 5){
                if(s[k][i] != color_masta[j]){
                    //cout << s[k][i] << " " << color_masta[j] << endl;
                    cnt++;
                } 
            }
            //cout << cnt << endl;
            dp[j][i+1] = min(dp[(j+1) % 3][i], dp[(j+2) % 3][i]) + cnt;
        }
    }

    ll ans = INF;
    rep(i, 3){
        chmin(ans, dp[i][n]);
    }
    cout << ans << endl;

}