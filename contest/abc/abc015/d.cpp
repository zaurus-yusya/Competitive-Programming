#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)


int main() {
    ll w;
    ll n, k;
    cin >> w >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);

    rep(i,n){
        cin >> a.at(i) >> b.at(i);
    }

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(w+1, 0)));
    dp[0][0][0] = 0;

    rep(i_r, n){
        rep(k_r, k){
            rep(j_r, w + 1){
                if(j_r - a.at(i_r) >= 0){
                    chmax(dp[i_r + 1][k_r + 1][j_r], dp[i_r][k_r][j_r - a.at(i_r)] + b.at(i_r));
                }
                chmax(dp[i_r + 1][k_r][j_r], dp[i_r][k_r][j_r]);
                if(k_r == k-1){
                    chmax(dp[i_r + 1][k_r + 1][j_r], dp[i_r][k_r + 1][j_r]);
                }
            }
        }
    }
    
    cout << dp[n][k][w] << endl;
    
}
