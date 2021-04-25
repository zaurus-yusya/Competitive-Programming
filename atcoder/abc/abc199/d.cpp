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

// need graph and root node 
struct LCA
{
    vector<vector<ll>> parent; // parent[k][u] : distance from u to parent is 2^k
    vector<ll> depth; // depth from root
    LCA(const vector<vector<ll>> &g, ll root){
        init(g, root);
    }

    void init(const vector<vector<ll>> &g, ll root){
        ll V = g.size(); // node num
        ll K = 1;
        while((1 << K) < V) K++;
        parent.assign(K, vector<ll> (V, -1));
        depth.assign(V, -1);

        dfs(g, root, -1, 0);
        
        for(ll k = 0; k+1 < K; k++){
            for(ll v = 0; v < V; v++){
                if(parent[k][v] < 0){
                    parent[k+1][v] = -1;
                }else{
                    parent[k+1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<ll>> &g, ll v, ll p, ll d){ // p:parent node, d:depth value
        parent[0][v] = p;
        depth[v] = d;
        for(ll i = 0; i < g[v].size(); i++){
            if(g[v][i] != p) dfs(g, g[v][i], v, d+1);
        }
    }

    ll lca(ll u, ll v){
        if(depth[u] < depth[v]) swap(u, v); // u is more deep
        ll K = parent.size();
        // u and v are same depth from lca
        for(ll k = 0; k < K; k++){
            if((depth[u] - depth[v]) >> k & 1){
                u = parent[k][u];
            }
        }

        if(u == v) return u;
        for(ll k = K-1; k >= 0; k--){
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    ll get_distance(ll u, ll v){ // distance from u to v
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool is_on_path(ll u, ll v, ll x){ // is x is on path from u to v?
        return get_distance(u, x) + get_distance(v, x) == get_distance(u, v);
    }
};

vector<bool> seen;
ll ans = 1;
void dfs(const Graph &G, ll v, ll p)
{   

    if(seen[v] == true){
        cerr << v << " sin " << endl;
        return;
    }

    bool f = true;
    if(p == -1){
        cerr << v << " in " << endl;
        ans *= 3;
        cerr << "ans = " << ans << endl;
        f = false;
    }

    


    ll tmp = 2;
    seen[v] = true;
    ll cnt = 0;
    for(ll next_node : G[v]){
        if(seen[next_node]){
            if(next_node != p){
                tmp -= 1;
            }
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            dfs(G, next_node, v); // v = 親ノード
        }
    }
    if(f){
        if(tmp < 0){
            cout << 0 << endl;
            exit(0);
        }
        ans *= tmp;
    } 
}


void calc(const Graph &G, ll v, ll p)
{
    if(seen[v] == true){
        cerr << v << " sin " << endl;
        return;
    }

}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i, m){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    LCA lca(g, 0);

    if(n == 1){
        cout << 3 << endl; return 0;
    }

    vector<P> zisu(n);
    rep(i, n){
        zisu[i] = {g[i].size(), i};
    }
    sort(all(zisu));
    reverse(all(zisu));

    rep(i, n){
        cerr << zisu[i].first << " " << zisu[i].second << endl;
    }

    seen.assign(n,false);

    rep(i, n){
        dfs(g, zisu[i].second, -1);
    }
    

    cout << ans << endl;
    




}