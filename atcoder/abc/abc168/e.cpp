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

//kentyon
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
//nHk = n+k-1Ck
//nCk
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


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
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);

    map<pair<ll,ll>,ll> mp_plus;
    map<pair<ll,ll>,ll> mp_mainasu;
    map<ll,ll> mp_all_zero;
    map<ll,ll> mp_a_zero;
    map<ll,ll> mp_b_zero;
    
    
    rep(i,n){
        cin >> a[i] >> b[i];
        ll g = gcd(a[i], b[i]);
        if(a[i] == 0 && b[i] == 0){
            mp_all_zero[0]++;
        }else if(a[i] == 0){
            mp_a_zero[0]++;
        }else if(b[i] == 0){
            mp_b_zero[0]++;
        }else{
            if((a[i] < 0 && b[i] < 0) || (a[i] > 0 && b[i] > 0)){
                if(a[i] < 0 && b[i] < 0){
                    a[i] *= -1;
                    b[i] *= -1;
                }
                mp_plus[make_pair(a[i]/g, b[i]/g)]++;
            }else{
                if(a[i] < 0){
                    a[i] *= -1;
                }
                if(b[i] < 0){
                    b[i] *= -1;
                }

                mp_mainasu[make_pair(a[i]/g, b[i]/g)]++;
            }
        }   

    }

    COMinit();

    ll ans = 0;

    ll all_zero_size = mp_all_zero.size();
    ll a_zero_size = mp_a_zero.size();
    ll b_zero_size = mp_b_zero.size();
    ll plus_size = mp_plus.size();
    ll mainasu_size = mp_mainasu.size();

    //all_zero関係
    ll tmp = 0;
    tmp = (tmp + a_zero_size) % MOD;
    tmp = (tmp + b_zero_size) % MOD;
    tmp = (tmp + plus_size) % MOD;
    tmp = (tmp + mainasu_size) % MOD;

    ans = (ans + (tmp*all_zero_size%MOD)) % MOD;

    //a_zero b_zero関係
    ans = (ans + (a_zero_size * b_zero_size % MOD)) % MOD;

    for(auto i: mp_plus){
        ll one = i.first.first;
        ll two = i.first.second;
        ll num = i.second;
        ll num2 = mp_mainasu[make_pair(two, one)];
        ans = (ans + (num * num2 % MOD)) % MOD;
    }

    cout << ans << endl;

    ll res = 0;
    res = modpow(2, n, MOD);
    res = res - 1;

}