#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 10000;
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
    ll n, k; cin >> n >> k;
    vector<ll> vec(n, -1);
    rep(i, k){
        ll a, b; cin >> a >> b;
        a--; b--;
        vec[a] = b;
    }

    ll dp[n+1][3][3];
    rep(i, n+1){
        rep(j, 3){
            rep(k, 3){
                dp[i][j][k] = 0;
            }
        }
    }

    if(vec[0] == -1){
        dp[0][0][0] = 1;
        dp[0][1][0] = 1;
        dp[0][2][0] = 1;
    }else{
        dp[0][vec[0]][0] = 1;
    }

    for(ll i = 0; i < n-1; i++){
        if(vec[i+1] == -1){
            for(ll j = 0; j < 3; j++){
                for(ll k = 0; k < 2; k++){

                    for(ll l = 0; l < 3; l++){
                        if(l == j){
                            dp[i+1][l][k+1] += (dp[i][j][k] % MOD);
                        }else{
                            dp[i+1][l][0] += (dp[i][j][k] % MOD);
                        }
                    }

                }
            }
        }else{
            for(ll j = 0; j < 3; j++){
                for(ll k = 0; k < 2; k++){

                    if(j == vec[i+1]){
                        dp[i+1][j][k+1] += (dp[i][j][k] % MOD);
                    }else{
                        dp[i+1][vec[i+1]][0] += (dp[i][j][k] % MOD);
                    }
                }
            }
        }
        
    }

    ll ans = 0;
    rep(j, 3){
        rep(k, 2){
            ans = (ans + dp[n-1][j][k]) % MOD;
        }
    }
    cout << ans << endl;

}