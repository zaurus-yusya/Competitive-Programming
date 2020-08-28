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
    ll d, n; cin >> d >> n;
    vector<long long> temperature(d);
    for(long long i = 0; i < d; i ++){
        cin >> temperature[i];
    }

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    rep(i, n){
        ll A, B, C; cin >> A >> B >> C;
        a[i] = A; b[i] = B; c[i] = C;
    }

    vector<vector<ll>> dp(d, vector<ll>(n, -1));

    for(ll i = 0; i < d; i++){
        if(i == 0){
            for(ll j = 0; j < n; j++){
                if(a[j] <= temperature[i] && temperature[i] <= b[j]){
                    dp[i][j] = 0;
                }
            }
            continue;
        }
        for(ll j = 0; j < n; j++){
            if(a[j] <= temperature[i] && temperature[i] <= b[j]){
                for(ll k = 0; k < n; k++){
                    if(dp[i-1][k] != -1){
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(c[j] - c[k]));
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    rep(i, n){
        ans = max(ans, dp[d-1][i]);
    }
    cout << ans << endl;

}