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

vector<ll> node;

void dfs(vector<vector<ll>> &g, ll v, ll iro){
    node[v] = iro;

    for(auto& next: g[v]){
        if(node[next] != 0) continue;
        dfs(g, next, iro);
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    rep(i, n-1){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 0からn-1までのパスを求める
    queue<ll> que;
    que.push(0);
    vector<ll> dist(n, INF);
    vector<ll> pre(n);
    dist[0] = 0;

    while(!que.empty()){
        
        ll now = que.front();
        que.pop();

        for(auto& next: g[now]){
            if(dist[next] != INF) continue;
            dist[next] = dist[now] + 1;
            pre[next] = now;
            que.push(next);
        }

    }

    vector<ll> path;
    ll now = n-1;
    while(now != 0){
        path.push_back(now);
        now = pre[now];
    }
    path.push_back(now);

    reverse(all(path));
    // vecdbg(path);

    node.assign(n, 0);

    rep(i, path.size()){
        if(i < ceilll(path.size() , 2)){
            node[path[i]] = 1;
        }else{
            node[path[i]] = 2;
        }
    }

    // vecdbg(node);

    for(ll i = 0; i < n; i++){
        if(node[i] != 0){
            dfs(g, i, node[i]);
        }
    }
    
    // vecdbg(node);
    ll ff = 0, ss = 0;
    rep(i, n){
        if(node[i] == 1){
            ff += 1;
        }else{
            ss += 1;
        }
    }

    if(ff > ss){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }



    

}