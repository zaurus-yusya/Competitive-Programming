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
const long long MOD = 1e9+7;
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
using F = long long;

//区間加算区間最小値取得
S op(S a, S b){ return min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

//宣言
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(n); //e()で初期化
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec); //vecの値で初期化
//seg.set(i, x); i番目の値をxに更新
//seg.get(i); i番目の要素を取得
//seg.prod(l, r); [l, r)の区間のopを計算
//seg.all_prod(); [0, n)の区間のopを計算
//seg.apply(l, r, f) [l, r)に対してmappingを実施
//単位元
//min: INF, max: -INF, 和: 0, 積: 1, xor: 0, gcd: 0, lcm: 1

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    
    vector<ll> vec(n+1);
    rep(i, n){
        if(s[i] == '('){
            vec[i+1] = vec[i] + 1;
        }else{
            vec[i+1] = vec[i] - 1;
        }
    }

    vecdbg(vec);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec); //vecの値で初期化

    rep(i, q){
        ll x, l, r; cin >> x >> l >> r;
        if(x == 1){
            char L = s[l-1], R = s[r-1];
            swap(s[l-1], s[r-1]);
            if(L == R) continue;
            if(L == '('){
                seg.apply(l, r, -2);
            }else{
                seg.apply(l, r, 2);
            }
        }else{
            //cout << seg.get(l) << " " << seg.get(r) << endl;
            if(s[l-1] == ')'){
                cout << "No" << '\n'; continue;
            }
            if(seg.get(l) - 1 == seg.get(r) && seg.get(r) == seg.prod(l,r+1)){
                cout << "Yes" << '\n'; continue;
            }else{
                cout << "No" << '\n'; continue;
            }
        }
    }
    
    

}