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
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

// g:graph, start: start node // <cost, next_node>
vector<ll> dis; //distance
vector<ll> pre; //route restoration
void dijkstra(vector<vector<pair<ll, ll>>> &g, ll start){
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
    ll n; cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, n-1){
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    

    ll q, k; cin >> q >> k; k--;
    dijkstra(g, k);
    rep(i, q){
        ll x, y; cin >> x >> y; x--; y--;

        cout << dis[x] + dis[y] << "\n";

    }

}