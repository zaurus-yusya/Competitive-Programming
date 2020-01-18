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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

    rep(i,n){
        cin >> a.at(i);
        cin >> b.at(i);
        cin >> c.at(i);
    }
    
    vector<vector<ll>> dp(n, vector<ll>(3));

    rep(i,n){
        if(i == 0){
            dp[0][0] = a.at(0);
            dp[0][1] = b.at(0);
            dp[0][2] = c.at(0);
            continue;
        }

        //aを選ぶ
        chmax(dp[i][0], dp[i-1][1] + a.at(i));
        chmax(dp[i][0], dp[i-1][2] + a.at(i));
        //bを選ぶ
        chmax(dp[i][1], dp[i-1][0] + b.at(i));
        chmax(dp[i][1], dp[i-1][2] + b.at(i));
        //cを選ぶ
        chmax(dp[i][2], dp[i-1][0] + c.at(i));
        chmax(dp[i][2], dp[i-1][1] + c.at(i));
    }

    
    ll ans = 0;
    rep(i,3){
        if(ans < dp[n-1][i]){
            ans = dp[n-1][i];
        }
    }
    cout << ans << endl;
    
}
