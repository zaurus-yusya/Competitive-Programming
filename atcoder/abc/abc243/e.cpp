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
const long long INF = 1e18;
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



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    
    vector<vector<ll>> dist(n, vector<ll>(n));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i == j){
                dist[i][j] = 0;
            }else{
                dist[i][j] = INF;
            }
        }
    }

    map<P, ll> hen;

    vector<vector<Edge>> g(n);
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        g[a].push_back({b, c}); g[b].push_back({a, c});
        dist[a][b] = c;
        dist[b][a] = c;

        hen[{a, b}] = c;
    }

    for(ll k = 0; k < n; k++){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    map<P, ll> flag;

    ll cnt = 0;

    for(auto& i: hen){
        ll a = i.first.first;
        ll b = i.first.second;
        ll c = i.second;

        ll tmp = 0;
        for(ll j = 0; j < n; j++){
            if(j == a || j == b) continue;
            if(dist[a][j] + dist[j][b] <= c){
                tmp = 1;
            }
        }
        if(tmp){
            cnt++;
        }
    }

    cout << cnt << endl;

}