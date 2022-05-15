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

using S = long long;
ll op(ll a, ll b) {
    return min(a, b);
}

ll e() {
    return INF;
}


ll op2(ll a, ll b) {
    return max(a, b);
}

ll e2() {
    return -INF;
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
    ll n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<ll> ar = a;
    reverse(all(ar));
    // cerr << ar.size() << endl;
    vector<long long> b(n);


    for(long long i = 0; i < n; i ++){
        cin >> b[i];
    }
    segtree<S, op, e> segmi(b);
    segtree<S, op2, e2> segma(b);

    ll ans = INF;

    for(ll i = 0; i < n; i++){
        ll x = a[i];
        ll rind = n-1 - i;
        // cerr << "rind = " << rind << endl;
        ll l = upper_bound(ar.begin() + rind, ar.end(), x) - ar.begin();
        // cerr << "l = " << l << endl;
        if(l == n){
            l = rind;
            l = n-1 - l;
        }else{
            if(ar[l] > x){
                l--;
            }
            l = n-1 - l;
        }
        // ll l = upper_bound(a.begin(), a.begin() + i, x) - a.begin();
        ll r = upper_bound(a.begin() + i, a.end(), x) - a.begin();
        
        // cerr << "i = " << i << " a[i] = " << x << " l = " << l << " r = " << r  << endl;
        if(x > 0){
            if(l >= r) continue;
            ll y = segmi.prod(l, r);
            // cerr << "y = " << y << endl;
            if(y == INF) continue;
            ans = min(ans, x*y);
        }else{
            if(l >= r) continue;
            ll y = segma.prod(l, r);
            // cerr << "y = " << y << endl;
            if(y == -INF) continue;
            ans = min(ans, x*y);
        }
    }
    // 0 1 2 3 4 5
    // 6 4 6 3 7 8

    // 0 1 2 3 4 5
    // 8 7 3 6 4 6
    cout << ans << endl;


}