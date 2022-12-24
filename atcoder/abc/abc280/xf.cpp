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

//dijkstra
struct Edge
{
    ll to, cost;
    Edge(ll to = 0, ll cost = 0) : to(to), cost(cost) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

//O(VE) first: cost, second: to
bool negative_circle_flag = false;
vector<long long> bellman_ford(vector<vector<pair<ll, ll>>> g, long long start){
    vector<ll> distance(g.size(), INF);
    distance[start] = 0;
    ll count = 0;
    while(true){
        bool update = false;
        for(ll i = 0; i < g.size(); i++){
            for(ll j = 0; j < g[i].size(); j++){
                if(distance[i] != INF && distance[g[i][j].second] > distance[i] + g[i][j].first){
                    distance[g[i][j].second] = distance[i] + g[i][j].first;
                    update = true;
                }
            }
        }
        if(!update) break;
        count++;
        if(count == g.size()){
            negative_circle_flag = true;
            return distance;
        }
    }
    return distance;
}

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
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<Edge>> g(n);
    UnionFind uf(n);

    rep(i, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, -1 * c);

        uf.unite(a, b);
    }

    rep(i, q){
        ll x, y; cin >> x >> y;
        x--; y--;

        if(uf.issame(x, y)){
            cout << 0 << endl;

        }else{
            cout << "nan" << endl;
        }
    }


}