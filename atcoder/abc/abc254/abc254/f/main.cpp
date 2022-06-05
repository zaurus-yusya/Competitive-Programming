#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

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
// for(auto& i: mp) &&&&&&&&&&&&&

using S = long long;
ll op(ll a, ll b) {
    return gcd(a, b);
}

ll e() {
    return 0;
}

//宣言
//segtree<S, op, e> seg(n); //e()で初期化
//segtree<S, op, e> seg(vec); //vecの値で初期化
//seg.set(i, x); //i番目の値をxに更新
//seg.get(i); //i番目の要素を取得
//seg.prod(l, r); //[l, r)の区間のopを計算
//seg.all_prod(); //[0, n)の区間のopを計算
//seg.max_right<f>(l); //未履修
//seg.min_left<f>(r); //未履修
//単位元 e()
//min: INF, max: -INF, 和: 0, 積: 1, xor: 0, gcd: 0, lcm: 1

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<long long> b(n);
    for(long long i = 0; i < n; i ++){
        cin >> b[i];
    }

    segtree<S, op, e> seg_a(n);
    segtree<S, op, e> seg_b(n);
    rep(i, n-1){
        seg_a.set(i, a[i+1] - a[i]);
        seg_b.set(i, b[i+1] - b[i]);
    }
    
    // aとbの公約数はa-bとbの公約数でもある。
    rep(Q, q){
        ll h1, h2, w1, w2; cin >> h1 >> h2 >> w1 >> w2; h1--; h2--; w1--; w2--;
        ll x = a[h1] + b[w1];
        ll y = seg_b.prod(w1, w2);
        ll z = seg_a.prod(h1, h2);
        ll ans = gcd(x, gcd(y, z));
        cout << ans << '\n';
    }

}