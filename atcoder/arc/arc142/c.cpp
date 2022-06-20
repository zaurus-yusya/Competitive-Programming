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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    map<ll, ll> mp;
    vector<ll> depth(200);
    ll ma_dep = -1;

    for(ll i = 3; i <= n; i++){
        cout << "? " << 1 << " " << i << endl;
        flush(std::cout);
        ll dis; cin >> dis;
        if(dis == -1){
            return 0;
        }
        depth[i] = dis;
        mp[depth[i]]++;
        ma_dep = max(ma_dep, dis);
    }

    ll cnt = 0;
    vector<ll> vec;
    vector<ll> ind;
    map<ll, ll> mpp;
    for(ll i = 3; i <= n; i++){
        cout << "? " << 2 << " " << i << endl;
        flush(std::cout);
        ll dis; cin >> dis;
        if(dis == -1){
            return 0;
        }
        if(dis == 1){
            vec.push_back(depth[i]);
            ind.push_back(i);
            mpp[depth[i]]++;
            // cout << "! " << depth[i] + 1 << endl; return 0;
        }
    }

    if(vec.size() == 0){
        cout << "! " << 1 << endl;
    }
    else if(vec.size() == 1){

        cout << "? " << 1 << " " << ind[0] << endl;
        flush(std::cout);

        ll dis_1; cin >> dis_1;

        cout << "? " << 2 << " " << ind[0] << endl;
        flush(std::cout);

        ll dis_2; cin >> dis_2;

        cerr << dis_1 << " " << dis_2 << endl;

        if(dis_1 > dis_2){
            cout << "! " << vec[0] - 1 << endl;
        }else{
            cout << "! " << vec[0] + 1 << endl;
        }
        
    }else{
        if(mpp.size() >= 2){
            ll mi = 1000, ma = -1000;
            rep(i, vec.size()){
                mi = min(mi, vec[i]);
                ma = max(ma, vec[i]);
            }
            cout << "! " << mi + 1 << endl;
        }else{
            cout << "! " << 1 << endl;
            // for(auto&i : mpp){
            //     cout << "! " << i.first - 1 << endl;
            // }
        }

    }

}