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

//a^n % mod
long long modpow(long long a, long long n, long long mod){
    long long res = 1;
    while(n > 0){
        if(n & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ll tmp = modpow(i, 10, MOD); ll tmp2 = modpow(i-1, 10, MOD);
        ll p = tmp - tmp2;
        if(p < 0) p += MOD;
        p = p % MOD;
        ll tmp3 = modpow(n/i, 10, MOD);
        ans = (ans + (p * tmp3) % MOD) % MOD;
    }
    cout << ans << endl;

    cout << modpow(10, 10, MOD) << endl;
    cout << pow(10, 10) << endl;

}