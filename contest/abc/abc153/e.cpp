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
    
    ll h, n;
    cin >> h >> n;

    vector<pair<ll,ll>> vec(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        vec.at(i) = make_pair(a,b);
    }

    vector<ll> dp(h+1, INF);
    dp[0] = 0;

    
    rep(i,n){
        rep(j,h){
            ll tmp = min(j+vec.at(i).first, h);
            dp[tmp] = min(dp[tmp], dp[j] + vec.at(i).second);
        }
    }

    cout << dp[h] << endl;


    

}
