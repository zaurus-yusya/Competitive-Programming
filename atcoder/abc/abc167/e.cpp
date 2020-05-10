#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 998244353;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> dp(n+1, vector<ll>(k+1));

    if(n == 1){
        cout << m << endl;
        return 0;
    }

    if(m == 1){
        if(k <= n-1){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }

    
    dp[0][0] = m;
    dp[0][1] = 0;

    for(ll i = 1; i < n; i++){

        rep(j,k+1){
            if(j == 0){
                dp[i][j] = (dp[i-1][j] * (m - 1)) % MOD;
            }else{
                dp[i][j] = ( ((dp[i-1][j] * (m-1)) % MOD) + (dp[i-1][j-1]) ) % MOD;
            }
        }

    }

    ll ans = 0;
    rep(i,k+1){
        ans = (ans + dp[n-1][i]) % MOD;
    }

    cout << ans << endl;
    
    

}