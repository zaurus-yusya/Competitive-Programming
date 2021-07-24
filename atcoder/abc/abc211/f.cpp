#include <bits/stdc++.h>
#include <atcoder/all>
// using namespace atcoder;
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
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    std::vector<S> v(100010, {0, 1});

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg_x(v);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg_y(v);
    

    rep(i, n){
        ll x; cin >> x;
        ll f_x = -1, f_y = -1;
        ll prev_x = -1, prev_y = -1;

        rep(j, x){
            ll now_x, now_y; cin >> now_x >> now_y;
            if(j == 0){
                f_x = now_x; f_y = now_y;
            }else{
                if(now_x == prev_x){
                    if(now_x > prev_x){
                        seg_x.apply(prev_x, now_x, composition(1, 1));
                    }else{
                        seg_x.apply(now_x, prev_x, composition(1, 1));
                    }
                }
                if(now_y == prev_y){
                    if(now_y > prev_y){
                        seg_y.apply(prev_y, now_y, composition(1, 1));
                    }else{
                        seg_y.apply(now_y, prev_y, composition(1, 1));
                    }
                }
            }
            prev_x = now_x; prev_y = now_y;

            if(j == x-1){
                if(now_x == f_x){
                    if(now_x > f_x){
                        seg_x.apply(f_x, now_x, composition(1, 1));
                    }else{
                        seg_x.apply(now_x, f_x, composition(1, 1));
                    }
                }
                if(now_y == f_y){
                    if(now_y > f_y){
                        seg_y.apply(f_y, now_y, composition(1, 1));
                    }else{
                        seg_y.apply(now_y, f_y, composition(1, 1));
                    }
                }

            }
        }

    }


    ll q; cin >> q;
    rep(i, q){
        
        ll X, Y; cin >> X >> Y;
        ll xx = seg_x.prod(0, X).value;
        ll yy = seg_y.prod(0, Y).value;
        cout << xx + yy << endl;
        
    }

}