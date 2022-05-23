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
    ll to, cost, num;
    Edge(ll to = 0, ll cost = 0, ll num = 0) : to(to), cost(cost), num(num) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};
vector<ll> dist; //distance
vector<ll> pre; //route restoration

vector<ll> ans;
map<ll, ll> mp;

struct TMP
{
    ll to, cost, num;
    TMP(ll to = 0, ll cost = 0, ll num = 0) : to(to), cost(cost), num(num) {}
};

void dijkstra(vector<vector<Edge>> &g, ll start){
    dist.assign(g.size(), INF);
    pre.assign(g.size(), -1);
    // priority_queue<P, vector<P>, greater<P>> que;
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> que2;
    dist[start] = 0;
    // que.push({0, start});
    que2.push({0, {start, 0}});

    while(!que2.empty()){ // 
        // auto[d, v] = que.top(); que.pop();
        pair<ll, pair<ll, ll>> x = que2.top(); que2.pop();
        ll d = x.first;
        ll v = x.second.first;
        ll y = x.second.second;
        if(dist[v] != d){
            // cerr << "in" << endl;
            mp[y]--;
            if(mp[y] == 0){
                mp.erase(y);
            }
            continue;
        }
        for(Edge& e : g[v]){
            ll next = d + e.cost; // next cost
            if(dist[e.to] <= next){
                continue;
            }else{
                dist[e.to] = next;
                // que.push({next, e.to});
                que2.push({next, {e.to, e.num}});
                mp[e.num]++;
                // ans.push_back(e.num);
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
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        g[a].emplace_back(b, c, i+1);
        g[b].emplace_back(a, c, i+1);
    }

    dijkstra(g, 0);

    for(auto&i: mp){
        cout << i.first << " ";
    }br;

    /*
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }br;
    */
    /*
    // BFS
    vector<ll> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[0] = 0;
    que.push({0, 0});


    while(!que.empty()){
        auto[d, v] = que.top(); que.pop();
        if(dist[v] != d) continue;
        for(Edge& e : g[v]){

        }
    }
    */





}