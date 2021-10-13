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

//dijkstra
struct Edge
{
    ll to, cost;
    Edge(ll to = 0, ll cost = 0) : to(to), cost(cost) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};
vector<ll> dist; //distance
vector<ll> pre; //route restoration
void dijkstra(vector<vector<Edge>> &g, ll start){
    dist.assign(g.size(), INF);
    pre.assign(g.size(), -1);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[start] = 0;
    que.push({0, start});

    while(!que.empty()){
        auto[d, v] = que.top(); que.pop();
        if(dist[v] != d) continue;
        for(Edge& e : g[v]){
            ll next = d + e.cost; // next cost
            if(dist[e.to] <= next){
                continue;
            }else{
                dist[e.to] = next;
                que.push({next, e.to});
                pre[e.to] = v;
            }
        }
    } 
}
vector<ll> route_restoration(vector<ll> &pre, ll goal){
    ll now = goal;
    vector<ll> res;
    
    while(true){
        //cout << now << endl;
        res.push_back(now);
        if(pre[now] == -1) break;
        now = pre[now];
    }
    return res;
}

vector<ll> ans;
vector<bool> seen;
ll root = -1;
void dfs(vector<vector<Edge>> &g, ll node, ll p){
    //cout << node << endl;
    seen[node] = 1;
    
    for(auto next: g[node]){
        if(!seen[next.to]){
            dfs(g, next.to, node);
        }
    }

    if(p != -1) ans[p] = max(ans[p], ans[node] + 1);
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, k; cin >> n >> k;
        vector<vector<Edge>> g(n);
        rep(i, n-1){
            ll u, v; cin >> u >> v; u--; v--;
            g[u].push_back({v, 1}); g[v].push_back({u, 1});
        }

        dijkstra(g, 0);
        ll cost = -1;
        ll u = -1;
        rep(i, n){
            if(cost < dist[i]){
                cost = dist[i];
                u = i;
            }
        }

        ll v = -1;
        dijkstra(g, u); //uからスタート
        cost = -1;
        rep(i, n){
            if(cost < dist[i]){
                cost = dist[i];
                v = i;
            }
        }

        vector<ll> pass = route_restoration(pre, v);

        //vecdbg(pass);

        root = pass[pass.size() / 2];
        //cout << "root = " << root << endl;
        ans.assign(n, 1);
        seen.assign(n, 0);
        dfs(g, root, -1);

        //vecdbg(ans);

        if(pass.size() % 2 == 0){
            ans[root]--;
        }
        map<ll, ll> mp;
        rep(i, n){
            mp[ans[i]]++;
        }

        vector<ll> res;
        res.push_back(n);
        ll cnt = 1;
        while(true){
            if(mp[cnt] == 0) break;
            res.push_back(res[cnt-1] - mp[cnt]);
            cnt++;
        }

        //vecdbg(res);

        if(k >= res.size()){
            cout << 0 << endl;
        }else{
            cout << res[k] << endl;
        }



    }



}