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
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    vector<ll> c(q);
    rep(i, n){
        cin >> a[i];
    }
    rep(i, q){
        cin >> c[i];
        c[i]--;
    }

    vector<ll> distance(n-1);
    rep(i, n-1){
        distance[i] = modpow(a[i], a[i+1], MOD);
    }
    vector<ll> sum(n);
    rep(i, n-1){
        sum[i+1] = (sum[i] + distance[i]) % MOD;
    }

    /*
    rep(i, n){
        cout << sum[i] << " ";
    }
    br;
    */

    ll now = 0;
    ll ans = 0;
    rep(i, q){
        ll x = c[i], y = now;
        if(x < y){
            swap(x, y);
        }
        if(sum[x] - sum[y]){
            ans += (sum[x] - sum[y] + MOD);
        }else{
            ans += sum[x] - sum[y];
        }
        ans = ans % MOD;
        

        //cout << abs(sum[c[i]] - sum[now]) << endl;
        //ans = (ans + (abs(sum[c[i]] - sum[now]) % MOD)) % MOD;
        now = c[i];
    }
    ll x = now, y = 0;
    if(sum[x] - sum[y]){
        ans += (sum[x] - sum[y] + MOD);
    }else{
        ans += sum[x] - sum[y];
    }
    ans = ans % MOD;
    
    cout << ans << endl;

}