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

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(21));

    for(ll i = 0; i < n; i++){
        if(i == 0){
            dp[i][vec[i]] = 1;
            continue;
        }
        for(ll j = 0; j < 21; j++){
            if(dp[i-1][j] > 0){
                if(j + vec[i] <= 20){
                    dp[i][j+vec[i]] += dp[i-1][j];
                }
                
                if(j - vec[i] >= 0){
                    dp[i][j-vec[i]] += dp[i-1][j];
                }
            }
        }
    }

    cout << dp[n-2][vec[n-1]] << endl;

}