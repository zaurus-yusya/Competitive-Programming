#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;

    vector<ll> value(m);

    rep(i,m){
        cin >> value[i];
    }

    vector<vector<ll>> dp(m+1, vector<ll>(n+1, INF));
    dp[0][0] = 0;
    rep(i,m){
        for(ll j = 0; j <= n; j++){
            if(j - value[i] >= 0){
                dp[i+1][j] = min(dp[i][j], dp[i+1][j - value[i]] + 1);
            }else{
                dp[i+1][j] = dp[i][j];
            }
            
        }
    }

    cout << dp[m][n] << endl;


}