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


//dijkstra
struct Edge
{
    ll to, cost, time;
    Edge(ll to = 0, ll cost = 0, ll time = 0) : to(to), cost(cost), time(time) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m){
        ll s, t, d, ti; cin >> s >> t >> d >> ti; s--; t--;
        g[s].emplace_back(t, d, ti);
        g[t].emplace_back(s, d, ti);
    }

    vector<vector<pair<ll, ll>>> dp((1<<n) + 10, vector<pair<ll, ll>>(n + 10, {INF, 1}));
    dp[0][0] = {0, 1}; // {cost, cnt}

    for(ll i = 0; i < (1<<n); i++){

        for(ll j = 0; j < n; j++){

            for(ll k = 0; k < g[j].size(); k++){
                if(i != 0 && (i & (1<<j)) == 0) continue;

                ll to = g[j][k].to;
                ll to_b = (1<<to);
                ll cost = g[j][k].cost;
                ll ti = g[j][k].time;

                if((i & to_b) == 0){
                    ll now_ti = dp[i][j].first;
                    if(now_ti + cost > ti) continue;

                    if(dp[i | to_b][to].first > dp[i][j].first + cost){
                        dp[i | to_b][to] = {dp[i][j].first + cost, dp[i][j].second};
                    }else if(dp[i | to_b][to].first == dp[i][j].first + cost){
                        dp[i | to_b][to].second += dp[i][j].second;
                    }
                }
            }
        }
    }

    if(dp[(1<<n) - 1][0].first == INF){
        cout << "IMPOSSIBLE" << endl; return 0;
    }
    cout << dp[(1<<n) - 1][0].first << " " << dp[(1<<n) - 1][0].second << endl;

}