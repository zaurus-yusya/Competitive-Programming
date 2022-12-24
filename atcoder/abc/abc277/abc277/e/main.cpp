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
    ll n, m, k; cin >> n >> m >> k;

    vector<vector<Edge>> g(2*n);
    rep(i, m){
        ll u, v, a; cin >> u >> v >> a;
        u--; v--;

        if(a == 1){
            g[u].emplace_back(v, 1);
            g[v].emplace_back(u, 1);
        }else{
            g[u + n].emplace_back(v + n, 1);
            g[v + n].emplace_back(u + n, 1);
        }
    }

    rep(i, k){
        ll s; cin >> s;
        s--;
        g[s].emplace_back(s + n, 0);
        g[s + n].emplace_back(s, 0);
    }

    dijkstra(g, 0);

    if(min(dist[n - 1], dist[2*n - 1]) == INF){
        cout << -1 << endl;
    }else{
        cout << min(dist[n - 1], dist[2*n - 1]) << endl;
    }
    return 0;



    vector<vector<ll>> g1(n);
    vector<vector<ll>> g0(n);
    rep(i, m){
        ll u, v, a; cin >> u >> v >> a;
        u--; v--;

        if(a == 1){
            g1[u].push_back(v);
            g1[v].push_back(u);
        }else{
            g0[u].push_back(v);
            g0[v].push_back(u);
        }
    }

    map<ll, ll> mp;
    rep(i, k){
        ll s; cin >> s; s--;
        mp[s]++;
    }

    vector<ll> dist1(n, -1); // はじめ通れる
    vector<ll> dist0(n, -1); // はじめ通れない

    // queue<pair<ll, ll>> que;
    deque<pair<ll, ll>> que;
    que.push_back({0, 1});
    dist1[0] = 0;

    while(!que.empty()){
        P now_ = que.front();
        ll now = now_.first;
        ll now_world = now_.second;
        que.pop_front();

        if(now_world == 1){

            for(ll i = 0; i < g1[now].size(); i++){
                ll next = g1[now][i];
                if(dist1[next] == -1){
                    dist1[next] = dist1[now] + 1;
                    // que.push({next, 1});
                    que.push_back({next, 1});
                }
            }

            // スイッチを押せるなら押す
            if(mp.count(now) > 0){
                if(dist0[now] == -1){
                    dist0[now] = dist1[now];
                    // que.push({now, 0});
                    que.push_front({now, 0});
                }
            }
        }else{
            for(ll i = 0; i < g0[now].size(); i++){
                ll next = g0[now][i];
                if(dist0[next] == -1){
                    dist0[next] = dist0[now] + 1;
                    // que.push({next, 0});
                    que.push_back({next, 0});
                }
            }

            // スイッチを押せるなら押す
            if(mp.count(now) > 0){
                if(dist1[now] == -1){
                    dist1[now] = dist0[now];
                    // que.push({now, 1});
                    que.push_front({now, 1});
                }
            }
        }
    }

    if(dist1[n-1] == -1 && dist0[n-1] == -1){
        cout << -1 << endl;
    }else if(dist1[n-1] == -1){
        cout << dist0[n-1] << endl;
    }else if(dist0[n-1] == -1){
        cout << dist1[n-1] << endl;
    }else{
        cout << min(dist1[n-1], dist0[n-1]) << endl;
    }

}