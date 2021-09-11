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

//dijkstra
struct Edge
{
    ll to, cost;
    Edge(ll to = 0, ll cost = 0) : to(to), cost(cost) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
    bool operator<(const Edge& o) const {
        return to < o.to;
    }
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

void dijkstra(vector<set<ll>> &g, ll start){
    dist.assign(g.size(), INF);
    pre.assign(g.size(), -1);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[start] = 0;
    que.push({0, start});

    while(!que.empty()){
        auto[d, v] = que.top(); que.pop();
        if(dist[v] != d) continue;

        for (auto itr = g[v].begin(); itr != g[v].end(); ++itr) {
            ll next = d + 1;
            if(dist[*itr] <= next){
                continue;
            }else{
                dist[*itr] = next;
                que.push({next, *itr});
            }
        }
        /*
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
        */
    } 
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;

    vector<P> hen;
    vector<vector<Edge>> vec(n);
    vector<set<ll>> vec2(n);
    rep(i, m){
        ll s, t; cin >> s >> t; s--; t--;
        hen.push_back({s, t});
        vec[s].push_back({t, 1});
        vec2[s].insert(t);
    }
    
    rep(i, n){
        sort(all(vec[i]));
    }
    
    rep(q, m){
        //vector<vector<Edge>> vec(n);

        ll s = hen[q].first;
        ll t = hen[q].second;

        vec2[s].erase(t);
        dijkstra(vec2, 0);
        vec2[s].insert(t);

        if(dist[n-1] == INF){
            cout << -1 << endl;
        }else{
            cout << dist[n-1] << endl;
        }

        /*
        ll dis = lower_bound(vec[s].begin(), vec[s].end(), t) - vec[s].begin();

        vec[s].erase(vec[s].begin() + dis);

        dijkstra(vec, 0);

        if(dist[n-1] == INF){
            cout << -1 << endl;
        }else{
            cout << dist[n-1] << endl;
        }

        vec[s].push_back({t, 1});
        sort(all(vec[s]));
        */

    }

}