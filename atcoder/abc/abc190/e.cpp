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
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<vector<ll>> vec(n);
    rep(i, m){
        ll a, b; cin >> a >> b; a--; b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    ll k; cin >> k;
    vector<ll> c(k);
    rep(i, k){
        cin >> c[i]; c[i]--;
    }

    vector<vector<ll>> dist(k, vector<ll>(k));

    
    //BFS
    vector<ll> d(n, -1);
    for(ll i = 0; i < k; i++){
        d.assign(n, -1);
        queue<ll> que;
        que.push(c[i]);
        d[c[i]] = 0;

        while(!que.empty()){
            ll now = que.front(); que.pop();
            ll now_d = d[now];
            for(auto next : vec[now]){
                if(d[next] != -1) continue;
                d[next] = now_d + 1;
                que.push(next);
            }
        }

        for(ll j = 0; j < k; j ++){
            if(d[c[j]] == -1) d[c[j]] = INF;
            dist[i][j] = d[c[j]];
        }

    }
    /*
    rep(i, k){
        rep(j, k){
            cout << dist[i][j] << " ";
        }br;
    }
    */

    //bitDP
    vector<vector<ll>> dp((1<<k) + 10, vector<ll>(k, INF));
    for(ll i = 0; i < k; i++){
        dp[(1 << i)][i] = 1;
    }
    for(ll i = 0; i < (1 << k); i++){
        for(ll from = 0; from < k; from++){
            for(ll to = 0; to < k; to++){
                if(from == to) continue;
                if(i != 0 && !(i & (1<<from))) continue;
                if((i & (1 << to)) == 1) continue;
                dp[i | (1 << to)][to] = min(dp[i | (1 << to)][to], dp[i][from] + dist[from][to]);
            }
        }
    }
    ll ans = INF;
    rep(i, k){
        ans = min(ans, dp[(1<<k) - 1][i]);
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;

}