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
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
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

void make_edge(vector<vector<pair<ll, ll>>> &g, vector<ll> &vec, ll h, ll w){
    rep(i, h*w){
        //上
        if(i - w >= 0){
            g[i].push_back({vec[i-w], i-w});
        }
        //下
        if(i + w < h*w){
            g[i].push_back({vec[i+w], i+w});
        }
        //左
        if((i - 1 + w) % w != (w-1)){
            g[i].push_back({vec[i-1], i-1});
        }
        //右
        if((i + 1) % w != 0){
            g[i].push_back({vec[i+1], i+1});
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    vector<ll> vec(h*w);
    rep(i, h*w) cin >> vec[i];

    vector<vector<pair<ll, ll>>> graph(h*w);

    make_edge(graph, vec, h, w);
    dijkstra(graph, h*w-w);
    vector<ll> ld = dis;
    dijkstra(graph, h*w-1);
    vector<ll> rd = dis;
    dijkstra(graph, w-1);
    vector<ll> ru = dis;
    ll ans = INF;
    rep(i, h*w){
        chmin(ans, ld[i]+rd[i]+ru[i]-2*vec[i]);
    }
    cout << ans << endl;

    route_restoration(pre, h*w-1);

    /*
    ////////////

    ll ans = 0;

    ll now = h*w-1;
    while(true){
        ans += vec[now];
        vec[now] = 0;
        if(pre[now] == -1) break;
        now = pre[now];
    }

    vector<vector<pair<ll, ll>>> graph2(h*w);
    make_edge(graph2, vec, h, w);
    dijkstra(graph2, h*w-1);

    now = w-1;
    while(true){
        ans += vec[now];
        vec[now] = 0;
        if(pre[now] == -1) break;
        now = pre[now];
    }

    cout << ans << endl;
    */
    
    



}