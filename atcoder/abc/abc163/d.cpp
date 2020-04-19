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

//(a / b) % MOD : a * modinv(b, MOD) % MOD
long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n,k;
    cin >> n >> k;

    ll ans = 0;
    for(ll i = k; i <= n+1; i++){
        /*ll tmp = modinv((((0 + i - 1) % MOD) * i % MOD) , 2);
        ll tmp2 = modinv((((n + n - i + 1 ) % MOD) * i % MOD) , 2);*/
        ll tmp = (0 + i - 1) * i / 2;
        ll tmp2 = (n + n - i + 1) * i / 2;
        ans += (tmp2 - tmp + 1) % MOD;
    }

    cout << ans % MOD<< endl;

}