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


vector<ll> seen(200010);
vector<ll> konkai;
map<ll, ll> heiro;
void dfs(vector<vector<ll>> &g, ll v, ll p){
    seen[v] = 1;
    konkai.push_back(v);
    
    for(auto next: g[v]){
        if(seen[next] == 1 && next != p){
            // 閉路発見
            bool f = false;
            for(ll i = 0; i < konkai.size(); i++){
                if(next == konkai[i]){
                    f = true;
                }

                if(f){
                    heiro[konkai[i]]++;
                    // heiro.push_back(konkai[i]);
                }
            }
        }
        if(seen[next] == 0){
            dfs(g, next, v);
        }

    }
    konkai.pop_back();
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

UnionFind uf(200010);
void dfs2(vector<vector<ll>> &g, ll v, ll heiro_node){
    seen[v] = 1;
    // cerr << "unite " << v << " " << heiro_node << endl;
    uf.unite(v, heiro_node);

    for(auto next: g[v]){
        if(seen[next] == 0 && heiro.count(next) == 0){
            dfs2(g, next, heiro_node);
        }
    }

}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    rep(i, n){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(g, 0, -1);

    seen.assign(200010, 0);
    

    for(auto& i: heiro){
        if(seen[i.first] == 0){
            dfs2(g, i.first, i.first);
        }
    }

    ll q; cin >> q;
    rep(i, q){
        ll x, y; cin >> x >> y; x--; y--;
        if(uf.root(x) == uf.root(y)){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }
    }






}