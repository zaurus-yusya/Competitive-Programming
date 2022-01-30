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
// for(auto& i: mp) &&&&&&&&&&&&&


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
void route_restoration(vector<ll> &pre, ll goal){
    ll now = goal;
    while(true){
        cout << now << endl;
        if(pre[now] == -1) break;
        now = pre[now];
    }
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<long long> h(n);
    for(long long i = 0; i < n; i ++){
        cin >> h[i];
    }

    vector<vector<pair<ll, ll>>> g(n);
    vector<vector<Edge>> g2(n);
    ll mi = INF;
    rep(i, m){
        ll u, v; cin >> u >> v; u--; v--;
        if(h[u] >= h[v]){
            g[u].push_back({-1 * (h[u] - h[v]), v});
            g[v].push_back({2 * (h[u] - h[v]), u});
            g2[u].emplace_back(v, -1 * (h[u] - h[v]));
            g2[v].emplace_back(u, 2 * (h[u] - h[v]));
        }else{
            g[u].push_back({2 * (h[v] - h[u]), v});
            g[v].push_back({-1 * (h[v] - h[u]), u});
            g2[u].emplace_back(v, 2 * (h[v] - h[u]));
            g2[v].emplace_back(u, -1 * (h[v] - h[u]));
        }
    }

    dijkstra(g2, 0);
    ll ans = 0;
    rep(i, n){
        ans = min(ans, dist[i]);
    }
    cout << -1 * ans << endl;

    /*
    vector<ll> res = bellman_ford(g, 0);
    ll ans = 0;
    rep(i, n){
        //cout << res[i] << " ";
        ans = min(ans, res[i]);
    }//br;
    cout << -1 * ans << endl;
    */


}