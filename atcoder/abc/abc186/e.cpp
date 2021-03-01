#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

// aが負のとき対策
ll modnega(ll a, ll m){
    return (a%m + m) % m;
}

// ax + by = gcd(a, b) を満たすx, yを求め、代入する。返り値dはgcd(a, b)
// a, bは定数。x, yは変数(決めておかなくていい)
ll extgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0) { x = 1; y = 0; return a;}
    ll d = extgcd(b, a % b, y, x);
    y -= a/b * x;
    return d;
}

// x ≡ b1 (mod m1), x ≡ b2 (mod m2), x ≡ b3 (mod m3),,,,となるxを求める。
// (r, m)を返すとき解は x ≡ r (mod m), 解なしの場合(0, -1)を返す
pair<ll, ll> chineserem(vector<ll> &b, vector<ll> &m){
    ll r = 0, M = 1;
    for(ll i = 0; i < b.size(); i++){
        ll p, q;
        ll d = extgcd(M, m[i], p, q);
        if((b[i] - r) % d != 0) return {0, -1};
        ll tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return {modnega(r, M), M};
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, s, k; cin >> n >> s >> k;
        vector<ll> x = {0, -s};
        vector<ll> y = {k, n};
        pair<ll, ll> res = chineserem(x, y);
        if(res.second == -1){
            cout << -1 << endl;
        }else{
            cout << res.first / k << endl;
        }
    }

}