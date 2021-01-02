#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

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

vector<ll> seen;
vector<ll> ans;
vector<ll> score;
void dfs(const vector<vector<ll>> &g, ll v, ll num){
    seen[v] = true;
    ans[v] = num;
    for(ll next_node : g[v]){
        if(seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            dfs(g, next_node, num + score[next_node]);
        }
    }

}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    vector<pair<ll, ll>> e(n);
    rep(i, n-1){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
        e[i]= {a, b};
    }

    LCA l(g, 0);
    
    seen.resize(n);
    ans.resize(n);
    score.resize(n);

    /////
    ll Q; cin >> Q;
    rep(q, Q){
        ll T, E, X; cin >> T >> E >> X; E--;
        if(T == 1){
            ll a = e[E].first, b = e[E].second;
            if(l.depth[a] < l.depth[b]){
                score[0] += X;
                score[b] -= X;
            }else{
                score[a] += X;
            }
        }else{
            ll a = e[E].first, b = e[E].second;
            if(l.depth[b] < l.depth[a]){
                score[0] += X;
                score[a] -= X;
            }else{
                score[b] += X;
            }
        }
    }

    dfs(g, 0, score[0]);

    rep(i, n){
        cout << ans[i] << endl;
    }

}