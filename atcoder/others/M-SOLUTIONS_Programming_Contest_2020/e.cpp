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
// string number to int : -48
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
    ll n; cin >> n;
    vector<ll> x(n), y(n), p(n);

    rep(i, n){
        cin >> x[i] >> y[i] >> p[i];
    }

    vector<ll> now(n);
    rep(i, n){
        if(x[i] > y[i]){
            now[i] = y[i] * p[i];
        }else{
            now[i] = x[i] * p[i];
        }
    }
    rep(i, n){
        cout << now[i] << " ";
    }
    br;

    vector<ll> x_line(n);
    vector<ll> y_line(n);

    rep(i, n){
        ll new_x = x[i];
        ll sum = 0;
        rep(j, n){
            ll tmp = abs(x[j] - new_x) * p[i];
            sum += 
        }
        
    }

    /*
    //30通り
    COMinit();
    ll sum = 0;
    for(ll i = 1; i <= 15; i++){
        cout << COM(15, i) * pow(2, i)<< endl;
        sum += COM(15, i) * pow(2, i);
    }
    cout << sum << endl;
    */



}