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

ll d[300010];
ll dp[300010][2]; // 0: 親ノードからそのノードに繋いで良い 1: 親からそのノードに繋いじゃダメ
map<pair<ll, ll>, ll> hen;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first != b.first){
        return a.first > b.first;
    }else{
        return b.second > b.second;
    }
}

vector<ll> seen;
void dfs(vector<vector<ll>> &g, ll v, ll p){
    seen[v] = 1;

    vector<ll> node_list;
    for(auto next : g[v]){
        if(seen[next] == 0){
            dfs(g, next, v);
            node_list.push_back(next);
        }
    }

    /*
    postorder
    */

    if(d[v] == 0){
        ll tmp = 0;
        for(ll i = 0; i < node_list.size(); i++){
            tmp += max(dp[node_list[i]][0], dp[node_list[i]][1]);
        }
        dp[v][0] = -INF;
        dp[v][1] = tmp;
    }else{
        ll tmp0 = 0, d0 = d[v]; d0--;
        ll tmp1 = 0, d1 = d[v];
        vector<pair<ll, ll>> sa; // first: 差分, second: node_num
        for(ll i = 0; i < node_list.size(); i++){
            tmp0 += dp[node_list[i]][1];
            tmp1 += dp[node_list[i]][1];
            
            ll cost = hen[{v, node_list[i]}];
            // cerr << "cost = " << cost << endl;
            // if(cost <= 0) continue;

            sa.push_back({cost + (dp[node_list[i]][0] - dp[node_list[i]][1]), node_list[i]});
        }
        sort(all(sa), cmp);

        for(ll i = 0; i < sa.size(); i++){
            if(sa[i].first <= 0) continue;
            if(d0 > 0){
                tmp0 += sa[i].first;
                d0--;
            }
            if(d1 > 0){
                tmp1 += sa[i].first;
                d1--;
            }
        }
        dp[v][0] = tmp0;
        dp[v][1] = tmp1;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    rep(i, n){
        cin >> d[i];
    }
    vector<vector<ll>> g(n);
    rep(i, n-1){
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
        hen[{u, v}] = w; hen[{v, u}] = w;
    }

    seen.assign(n, 0);
    dfs(g, 0, -1);

    cout << max(dp[0][0], dp[0][1]) << endl;


}