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

template <typename T>
struct Compress {

    //元の座標のリスト 座圧前の座標群をsortして重複を削除する
    vector<T> zahyo_list; 

    //元の配列が座圧されたものに書き換わる O(n logn)
    Compress(vector<T> &vec){
        zahyo_list = vec;
        sort(zahyo_list.begin(), zahyo_list.end());
        zahyo_list.erase(unique(zahyo_list.begin(), zahyo_list.end()), zahyo_list.end());
        for(ll i = 0; i < vec.size(); i++){
            vec[i] = lower_bound(zahyo_list.begin(), zahyo_list.end(), vec[i]) - zahyo_list.begin();
        }
    }

    //座圧後の配列の値の元の値を返す O(1)
    T moto_value(ll i){
        return zahyo_list[i];
    }
};

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
    vector<ll> a(m);
    vector<ll> b(m);
    vector<ll> c(m);
    vector<ll> p;
    p.push_back(0); p.push_back(n-1);
    rep(i, m){
        ll aa, bb, cc; cin >> aa >> bb >> cc; aa--; bb--;
        c[i] = cc;
        p.push_back(aa); p.push_back(bb);
    }

    Compress<ll> pp(p);

    // vecdbg(p);
    
    // cout << pp.moto_value(0) << endl;
    // cout << pp.moto_value(4) << endl;
    // cout << pp.moto_value(1) << endl;
    // cout << pp.moto_value(3) << endl;

    vector<vector<Edge>> g(p[1] + 1);
    // cout << pp.moto_value(p[1]) + 1 << endl;

    for(ll i = 0; i < p.size(); i+=2){
        ll u = p[i], v = p[i+1];
        ll cost;
        if(i == 0){
            cost = pp.moto_value(p[i+1]) - pp.moto_value(p[i]);
        }else{
            // cerr << "in = " << (i/2) - 1 << endl;
            cost = c[(i/2) - 1];
        }
        // cout << "i = " << i << " u = " << u << " v = " << v << endl;
        // cout << "i = " << i << " cost = " << cost << endl;

        g[u].emplace_back(v, cost);
        g[v].emplace_back(u, cost);
    }
    for(ll i = 1; i < pp.zahyo_list.size(); i++){
        ll x = pp.moto_value(i-1);
        ll y = pp.moto_value(i);
        g[i-1].emplace_back(i, y - x);
        g[i].emplace_back(i-1, y - x);
    }

    dijkstra(g, 0);
    cout << dist[p[1]] << endl;


}