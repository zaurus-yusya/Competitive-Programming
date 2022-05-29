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


//区間加算区間最小値取得
struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

//宣言
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(n); //e()で初期化
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec); //vecの値で初期化
//seg.set(i, x); //i番目の値をxに更新
//seg.get(i); //i番目の要素を取得
//seg.prod(l, r); //[l, r)の区間のopを計算
//seg.all_prod(); //[0, n)の区間のopを計算
//seg.apply(l, r, f) //[l, r)に対してmappingを実施
//単位元 e()
//min: INF, max: -INF, 和: 0, 積: 1, xor: 0, gcd: 0, lcm: 1

struct Q{
    ll ind;
    ll num;
    vector<ll> vec;
};


struct QQ{
    ll col;
    ll ind;
    ll sub;
};


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m, q; cin >> n >> m >> q;
    vector<S> vec(m+10, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec);

    vector<Q> query(q);

    rep(qq, q){
        ll t; cin >> t;
        if(t == 1){
            ll l, r, x; cin >> l >> r >> x; l--;
            query[qq].ind = qq;
            query[qq].num = 1;
            query[qq].vec = {l, r, x};
        }
        if(t == 2){
            ll i, x; cin >> i >> x; i--;
            query[qq].ind = qq;
            query[qq].num = 2;
            query[qq].vec = {i, x};

        }
        if(t == 3){
            ll i, j; cin >> i >> j; i--; j--;
            query[qq].ind = qq;
            query[qq].num = 3;
            query[qq].vec = {i, j};

        }
    }

    vector<vector<QQ>> node(n+10);

    vector<pair<ll, ll>> ans;

    for(ll qq = q-1; qq >= 0; qq--){
        ll t = query[qq].num;
        if(t == 1){
            ll l = query[qq].vec[0];
            ll r = query[qq].vec[1];
            ll x = query[qq].vec[2];

            seg.apply(l, r, x);
        }
        if(t == 2){
            ll i = query[qq].vec[0];
            ll x = query[qq].vec[1];

            for(ll k = 0; k < node[i].size(); k++){
                ll col = node[i][k].col;
                ll ind = node[i][k].ind;
                ll sub = node[i][k].sub;

                ll res = seg.prod(col, col+1).value;

                ans.push_back({ind, res + x - sub}); 
            }

            node[i].clear();
        }
        if(t == 3){
            ll i = query[qq].vec[0];
            ll j = query[qq].vec[1];

            QQ tmp; tmp.col = j; tmp.ind = qq; tmp.sub = seg.prod(j, j+1).value;
            node[i].push_back(tmp);
        }
    }

    for(ll i = 0; i < n; i++){
        ll x = 0;
        for(ll k = 0; k < node[i].size(); k++){
            ll col = node[i][k].col;
            ll ind = node[i][k].ind;
            ll sub = node[i][k].sub;

            ll res = seg.prod(col, col+1).value;

            ans.push_back({ind, res + x - sub});
        }
    }

    sort(all(ans));
    rep(i, ans.size()){
        cout << ans[i].second << '\n';
    }

}
