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

//dijkstra
struct Edge
{
    ll to, cost, cost2;
    Edge(ll to = 0, ll cost = 0, ll cost2 = 0) : to(to), cost(cost), cost2(cost){}
    //g[a].emplace_back(x, y) : x = to, y = cost
};
vector<ll> dist; //distance
vector<ll> pre; //route restoration
void dijkstra(vector<vector<Edge>> &g, ll start, ll xxx){
    dist.assign(g.size(), INF);
    pre.assign(g.size(), -1);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[start] = xxx;
    que.push({xxx, start});

    while(!que.empty()){
        auto[d, v] = que.top(); que.pop();
        if(dist[v] != d) continue;
        for(Edge& e : g[v]){
            //ll next = d + e.cost; // next cost
            ll cnt = 0;
            ll cost = d + (e.cost + e.cost2/(d+1));
            ll now = cost;
            //cout << "v = " << v << " " << cost << " " << e.cost2 << endl;
            while(true){
                ll cost2 = d + cnt+1 + (e.cost + e.cost2/(d+1+cnt+1));
                //cout << d+cnt+1 << " " << cost2 << endl;
                if(cost2 >= now){
                    break;
                }else{
                    now = cost2;
                    cnt++;
                }
            }
            ll next2 = d + cnt + (e.cost + e.cost2/(d+1+cnt)); // next cost
            ll next = next2;
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
    rep(i, m){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--;
        Edge e; e.to=b; e.cost=c; e.cost2=d;
        g[a].emplace_back(e);
    }

    dijkstra(g, 0, 0);
    if(dist[n-1] == INF){
        cout << -1 << endl; return 0;
    }
    cout << dist[n-1] << endl;
    /*
    ll res = dist[n-1];
    rep(i, n){
        cout << dist[i] << " ";
    }br;
    dijkstra(g, 0, 1);
    rep(i, n){
        cout << dist[i] << " ";
    }br;
    ll res2 = dist[n-1];

    ll ans = min(res, res2);
    if(ans == INF){
        cout << -1 << endl; return 0;
    }
    

    cout << min(res, res2) << endl;
    */

}