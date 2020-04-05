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
    ll n, w;
    cin >> n >> w;
    vector<ll> weight(n);
    vector<ll> value(n);
    rep(i,n){
        cin >> weight.at(i) >> value.at(i);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(w+1));

    
    rep(i,n){
        for(ll j = 0; j <= w; j++){
            if(j - weight.at(i) >= 0){
                chmax(dp[i+1][j], dp[i][j - weight.at(i)] + value.at(i));
            }  
            chmax(dp[i+1][j], dp[i][j]);
        }    
    }
    

    cout << dp[n][w] << endl;
}
