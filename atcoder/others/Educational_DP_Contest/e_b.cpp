#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const ll INF = 1e10;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)


int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> weight(n);
    vector<ll> value(n);
    rep(i,n){
        cin >> weight.at(i) >> value.at(i);
    }
    vector<vector<ll>> dp(n+1, vector<ll>((n * 1000) + 1, INF));
    dp[0][0] = 0;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= n * 1000; j++){
            if(j - value[i] >= 0){
                dp[i+1][j] = min(dp[i][j], dp[i][j - value[i]] + weight[i]);
            }else{
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
    }

    ll ans = 0;
    rep(i, n * 1000 + 1){
        if(dp[n][i] <= w){
            ans = i;
        }
    }
    cout << ans << endl;


}
