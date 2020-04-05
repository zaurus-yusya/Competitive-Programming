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

int main() {
    ll n;
    cin >> n;
    vector<ll> vec_a(n);
    rep(i, n) cin >> vec_a.at(i);
    vector<ll> vec_b(n);
    rep(i, n) cin >> vec_b.at(i);
    vector<ll> vec_c(n);
    rep(i, n) cin >> vec_c.at(i);
    vector<ll> vec_d(n);
    rep(i, n) cin >> vec_d.at(i);

    ll dp[n+10][4];
    dp[0][0] = vec_a.at(0);
    
    for(ll i = 1; i < n; i++){
        if(i == 0){
            dp[0][0] = vec_a.at(i);
        }
        if(i == 1){
            dp[i][0] = dp[i-1][0] + vec_a.at(i);
            dp[i][1] = dp[i-1][0] + vec_b.at(i);
        }
        if(i == 2){
            dp[i][0] = dp[i-1][0] + vec_a.at(i);
            dp[i][1] = max(dp[i-1][1] + vec_b.at(i), dp[i-1][0] + vec_b.at(i));
            dp[i][2] = dp[i-1][1] + vec_c.at(i);
        }
        if(i == 3){
            dp[i][0] = dp[i-1][0] + vec_a.at(i);
            dp[i][1] = max(dp[i-1][1] + vec_b.at(i), dp[i-1][0] + vec_b.at(i));
            dp[i][2] = max(dp[i-1][2] + vec_c.at(i), dp[i-1][1] + vec_c.at(i));
            dp[i][3] = dp[i-1][2] + vec_d.at(i);
        }
        if(i >= 4){
            dp[i][0] = dp[i-1][0] + vec_a.at(i);
            dp[i][1] = max(dp[i-1][1] + vec_b.at(i), dp[i-1][0] + vec_b.at(i));
            dp[i][2] = max(dp[i-1][2] + vec_c.at(i), dp[i-1][1] + vec_c.at(i));
            dp[i][3] = max(dp[i-1][3] + vec_d.at(i), dp[i-1][2] + vec_d.at(i));
        }

    }
    
    cout << dp[n-1][3] << endl;

}