#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
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

struct Zahyo{
    ll y, x;
};

struct Zahyo2{
    ll l;
    ll r;
    ll cost;
    bool operator<(const Zahyo2& o) const {
        return cost < o.cost;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, h, w; cin >> n >> h >> w;
    UnionFind uf(n);

    vector<Zahyo> vec;
    rep(i, n){
        ll x, y; cin >> x >> y; x--; y--;
        vec.push_back({y, x});
    }
    
    vector<Zahyo2> res;
    
    for(ll i = 0; i < vec.size(); i++){
        for(ll j = i+1; j < vec.size(); j++){
            ll tmp_y = abs(vec[i].y - vec[j].y);
            ll tmp_x = abs(vec[i].x - vec[j].x);
            ll cost = min(tmp_y, h-tmp_y) + min(tmp_x, w - tmp_x);
            res.push_back({i, j, cost});
        }
    }
    

    sort(all(res));

    ll ans = 0;
    rep(i, res.size()){
        if(!uf.issame(res[i].l, res[i].r)){
            ans += res[i].cost;
            uf.unite(res[i].l, res[i].r);
        }
    }

    cout << ans << endl;



}