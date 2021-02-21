#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
using P = pair<ll, ll>;
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
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

// g:graph, start: start node // <cost, next_node>
/*
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &g, ll start){
    vector<ll> dis; //distance
    vector<ll> pre; //route restoration
    //vector<ll> distance(g.size(), INF);
    dis.assign(g.size(), INF);
    pre.assign(g.size(), -1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
    dis[start] = 0;
    que.push(make_pair(0, start));

    while(!que.empty()){
        pair<long ,long> now = que.top();
    long long now_pos = now.second;
        que.pop();
        if(dis[now_pos] < now.first){
            continue;
        }
        // cost next
        for(long long i = 0; i < g[now_pos].size(); i++){
            pair<long ,long> next = g[now_pos][i];
            long long next_cost = next.first;
            long long next_pos = next.second;
            if(dis[next_pos] > dis[now_pos] + next_cost){
                dis[next_pos] = dis[now_pos] + next_cost;
                pre[next_pos] = now_pos;
                que.push(make_pair(dis[next_pos], next_pos));
            }
        }
    }

    return dis;
}
void route_restoration(vector<ll> &pre, ll goal){
    ll now = goal;
    while(true){
        cout << now << endl;
        if(pre[now] == -1) break;
        now = pre[now];
    }
}
*/

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
            ll next = d + e.cost;
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
    vector<vector<Edge>> g(n);
    vector<ll> onazi(n, -1);


    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        g[a].emplace_back(b, c);
        if(a == b){
            if(onazi[a] != -1){
                onazi[a] = min(onazi[a], c);
            }else{
                onazi[a] = c;
            }
            
        }
    }

    vector<vector<ll>> kyori(n);
    rep(i, n){
        dijkstra(g, i);
        kyori[i] = dist;
        //dist.clear();
        //pre.clear();
    }


    //答え
    rep(i, n){
        ll ans = INF;
        if(onazi[i] != -1){
            ans = min(ans, onazi[i]);
        }
        rep(j, n){
            if(i == j) continue;
            ans = min(ans, kyori[i][j] + kyori[j][i]);
        }

        if(ans == INF){
            cout << -1 << "\n";
        }else{
            cout << ans << "\n";
        }

    }
    
}