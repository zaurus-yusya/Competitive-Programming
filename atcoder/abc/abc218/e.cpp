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

struct Edge{
    ll from, to, cost;

    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};

struct Edge2{
    ll from, to, cost;

    bool operator<(const Edge2& o) const {
        return cost > o.cost;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;

    vector<Edge> vec;

    ll sum = 0;
    ll geta = 0;

    vector<ll> nega;

    rep(i, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        if(a == b){
            if(c < 0) continue;
            else geta += c;
        }else{
            vec.push_back({a, b, c});
            sum += c;
        }
    }

    sort(all(vec));

    UnionFind uf(n);
    ll res = 0;

    rep(i, vec.size()){
        if(!uf.issame(vec[i].from, vec[i].to)){
            uf.unite(vec[i].from, vec[i].to);
            //out << vec[i].from << " " << vec[i].to << " " << vec[i].cost << endl;
            res += vec[i].cost;
        }else if(vec[i].cost < 0){
            uf.unite(vec[i].from, vec[i].to);
            //out << vec[i].from << " " << vec[i].to << " " << vec[i].cost << endl;
            res += vec[i].cost;
        }
    }

    cout << sum - res + geta << endl;

}