#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

struct UnionFind
{
    vector<long long> d;
    UnionFind(long long n = 0) : d(n, -1)
    {
    }

    //root : -size, not root: root
    long long root(long long x){
        if(d[x] < 0){
            return x; 
        }
        return d[x] = root(d[x]);
    }

    bool unite(long long x, long long y){
        x = root(x);
        y = root(y);
        if(x == y){
            return false;
        }
        if(d[x] > d[y]){
            swap(x, y);
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    long long size(long long x){
        return -d[root(x)];
    }

    bool issame(long long a, long long b){
        return root(a) == root(b);
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> r(n);

    rep(i, n){
        cin >> x[i] >> y[i] >> r[i];
    }

    UnionFind uf(n);

    /*
    外接する                      ⋯  d=r[i]+r[j]                     ⋯  d=r[i]+r[j]
    2点で交わる                 ⋯  |r[i]−r[j]|<d<r[i]+r[j]                ⋯  |r[i]−r[j]|<d<r[i]+r[j]
    内接する                       ⋯  d=|r[i]+r[j]|                      ⋯  d=|r[i]+r[j]|
    */

    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            // 2乗で誤差回避
            ll d2 = abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]);

            bool f = false;
            // 外接
            if(d2 == (r[i] + r[j]) * (r[i] + r[j])){
            // if(d2 == r[i]*r[i] + 2 * r[i] * r[j] * r[j]*r[j]){
                // cerr << "in1" << endl;
                f = true;
            }

            // 2点で交わる
            if(abs(r[i] - r[j]) * abs(r[i] - r[j]) < d2 && d2 < (r[i] + r[j]) * (r[i] + r[j])){
            // if(r[i]*r[i] - 2 * r[i] * r[j] * r[j]*r[j] < d2 && d2 < r[i]*r[i] + 2 * r[i] * r[j] * r[j]*r[j]){
                // cerr << "in2" << endl;
                f = true;
            }

            // 内接
            if(d2 == abs(r[i] - r[j]) * abs(r[i] - r[j])){
            // if(d2 == r[i]*r[i] + 2 * r[i] * r[j] * r[j]*r[j]){
                // cerr << "in3" << endl;
                f = true;
            }

            if(f){
                // cerr << d2 << endl;
                // cerr << "unite i = " << i << " j = " << j << endl; 
                uf.unite(i, j);
            }
        }
    }

    // sとtがどの円に属しているか
    // (x - a)^2 + (y - b)^2 = r^2
    // x*2 - 2*x*a + a*a + y*y - 2*y*b + b*b = r*r
    map<ll, ll> mps;
    map<ll, ll> mpt;
    rep(i, n){
        if((sx - x[i]) * (sx - x[i]) + (sy - y[i]) * (sy - y[i]) == r[i] * r[i]){
        // if(sx*sx - 2*sx*x[i] + x[i]*x[i] + sy*sy - 2*sy*y[i] + y[i]*y[i] == r[i]*r[i]){
            mps[i]++;
        }

        if((tx - x[i]) * (tx - x[i]) + (ty - y[i]) * (ty - y[i]) == r[i] * r[i]){
        // if(tx*tx - 2*tx*x[i] + x[i]*x[i] + ty*ty - 2*ty*y[i] + y[i]*y[i] == r[i]*r[i]){
            mpt[i]++;
        }
    }

    bool f = false;
    for(auto&i : mps){
        for(auto&j : mpt){
            if(uf.issame(i.first, j.first)){
                f = true;
            }
        }
    }

    if(f){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}