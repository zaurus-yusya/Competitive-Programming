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

struct Edge
{
    ll to, cost;
    Edge(ll to = 0, ll cost = 0) : to(to), cost(cost) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

// ノード数 n, 辺数 nの時動作する Cyclesの配列を返す。 {from, to, cost}
struct GraphCycleDetection
{

    GraphCycleDetection(const vector<vector<Edge>> &g){
        init(g);
    }

    vector<bool> seen;
    vector<ll> tuuka;
    vector<ll> cost;
    map<ll, ll> konkai;
    map<ll, ll> konkaiind;
    void init(const vector<vector<Edge>> &g){
        seen.assign(g.size(), 0);
        for(ll i = 0; i < g.size(); i++){
            if(!seen[i]) dfs(g, i);
            
        }
    }

    struct Cycle{
        ll from, to, cost;
        Cycle(ll from = 0, ll to = 0, ll cost = 0) : from(from), to(to), cost(cost) {}
    };
    vector<vector<Cycle>> cycles;

    void dfs(const vector<vector<Edge>> &g, ll v){
        seen[v] = true;
        tuuka.push_back(v);
        konkai[v]++;
        konkaiind[v] = tuuka.size() - 1;

        for(ll i = 0; i < g[v].size(); i++){
            ll next = g[v][i].to;

            if(seen[next] == 1){
                if(konkai.count(next) > 0){
                    // 閉路検出
                    ll ind = konkaiind[next];
                    cost.push_back(g[v][i].cost);

                    vector<Cycle> now_cycle;
                    for(ll j = ind; j < cost.size(); j++){
                        ll from_node, to_node;
                        if(j == cost.size() - 1){
                            from_node = tuuka[j];
                            to_node = tuuka[ind];
                        }else{
                            from_node = tuuka[j];
                            to_node = tuuka[j+1];
                        }

                        now_cycle.emplace_back(from_node, to_node, cost[j]);
                    }

                    cycles.push_back(now_cycle);
                    cost.pop_back();

                }
            }else{
                cost.push_back(g[v][i].cost);
                dfs(g, next);
                cost.pop_back();
            }
        }
        konkai.erase(v);
        tuuka.pop_back();
    }
};


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;

    vector<vector<Edge>> g(n);
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        g[a].emplace_back(b, c);
    }
    

    GraphCycleDetection gg(g);

    for(ll i = 0; i < gg.cycles.size(); i++){
        cerr << "--" << endl;
        for(ll j = 0; j < gg.cycles[i].size(); j++){
            cerr << gg.cycles[i][j].from << " " << gg.cycles[i][j].to << " " << gg.cycles[i][j].cost << endl;
        }
        
    }

}