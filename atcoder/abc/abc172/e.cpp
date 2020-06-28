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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    if(n > m){
        cout << 0 << endl;
        return 0;
    }

    if(n == m){
        // n-1 * n!
        ll ans = n-1;
        for(ll i = 1; i <= n; i++){
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
        return 0;
    }

    COMinit();

    ll ans = 0;
    //ll mcn = COM(m, n);
    ll mcn = 1;
    for(ll i = 0; i < n; i++){
        mcn = mcn * (m-i) % MOD;
    }

    //cout << "mcn = " << mcn << endl;

    for(ll i = 1; i < n; i++){
        //cout << i << " " << COM(n, i) << " " << COM(m-n, i) << endl;
        
        ans =  (ans +  (mcn * ((COM(n, i) * COM(m-n, i) + 1) % MOD) ) % MOD ) % MOD;

        //cout << ans << endl;
    }
    
    if(n * 2 <= m){
        ll tmp = 1;
        for(ll i = 0; i < n; i++){
            tmp = tmp * (m-n-i) % MOD;
            tmp = (tmp * tmp) % MOD;
            //cout << "tmp = " << tmp << endl;
        }
        //cout << "tmp_res = " << tmp << endl;
        ans = (ans + tmp) % MOD;
        //cout << "in" << endl;
    }

    //cout << "ans = " << ans << endl;
    cout << ans << endl;
}