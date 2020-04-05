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
// コンパイル　g++ -std=c++17 a.cpp

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

//a^n % mod
long long modpow(long long a, long long n, long long mod){
    ll res = 1;
    while(n > 0){
        if(n & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


ll modncr(ll n, ll r){
    ll bunshi = 1;
    ll bunbo = 1;
    for(ll i = 0; i < r; i++){
        bunshi = (bunshi * (n-i)) % MOD;
        bunbo = (bunbo * (i+1)) % MOD;
    }
    return (bunshi * modinv(bunbo, MOD)) % MOD;
}


int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll all = 0;
    all = modpow(2, n, MOD) - 1;
    
    
    all = all - modncr(n, a);
    if(all < 0) all += MOD;
    all = all - modncr(n, b);
    if(all < 0) all += MOD;

    if(n == 2){
        cout << 0 << endl;
    }else{
        cout << all << endl;
    }
    
}