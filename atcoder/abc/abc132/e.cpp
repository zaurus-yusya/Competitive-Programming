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
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i, m){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
    }
    ll s, t; cin >> s >> t; s--; t--;

    vector<ll> dist(n, -1);
    vector<vector<ll>> amari(n, vector<ll>(3));

    queue<pair<ll, ll>> que;
    que.push({s, 0});
    dist[s] = 0;
    amari[s][0] = 1;

    bool flag = false;
    while(!que.empty()){
        ll now = que.front().first;
        ll now_dist = que.front().second;

        if(now == t && now_dist % 3 == 0){
            cout << now_dist / 3 << endl;
            return 0;
        }
        que.pop();

        for(auto next: g[now]){
            if(dist[next] == -1){
                dist[next] = now_dist + 1;
                amari[next][(now_dist + 1) % 3] = 1;
                que.push({next, now_dist + 1});
            }else{
                if(amari[next][(now_dist + 1) % 3] == 1) continue;
                dist[next] = now_dist + 1;
                amari[next][(now_dist + 1) % 3] = 1;
                que.push({next, now_dist + 1});
            }
        }

    }

    cout << -1 << endl;

}