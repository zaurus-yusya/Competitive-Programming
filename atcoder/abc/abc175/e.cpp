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

ll dp[3010][3010][4];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll r, c, k; cin >> r >> c >> k;
    vector<vector<ll>> vec(r, vector<ll>(c));
    rep(i, k){
        ll x, y, z; cin >> x >> y >> z;
        x--; y--;
        vec[x][y] = z;
    }

    rep(i, r){
        rep(j, c){
            rep(k, 4){
                //拾う場合
                if(k != 3){
                    dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + vec[i][j]); //横
                    dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k] + vec[i][j]); //縦
                }
                //拾わない場合
                dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]); //横
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]); //縦
            }
        }
    }

    ll ans = 0;
    rep(i, 4){
        ans = max(ans, dp[r-1][c][0]);
    }
    rep(i, 4){
        ans = max(ans, dp[r][c-1][0]);
    }
    cout << ans << endl;

}