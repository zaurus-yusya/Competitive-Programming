#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

bool negative_circle_flag = false;
vector<long long> bellman_ford(vector<vector<pair<ll, ll>>> g, long long start){
    vector<ll> distance(g.size(), INF);
    distance[start] = 0;
    ll count = 0;
    while(true){
        bool update = false;
        for(ll i = 0; i < g.size(); i++){
            for(ll j = 0; j < g[i].size(); j++){
                if(distance[i] != INF && distance[g[i][j].second] > distance[i] + g[i][j].first){
                    distance[g[i][j].second] = distance[i] + g[i][j].first;
                    update = true;
                }
            }
        }
        if(!update) break;
        count++;
        if(count == g.size()){
            negative_circle_flag = true;
            return distance;
        }
    }
    return distance;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    vector<vector<ll>> c(10, vector<ll>(10));
    for(long long i = 0; i < 10; i++){
        for(long long j = 0; j < 10; j++){
            cin >> c[i][j];
        }
    }
    vector<vector<ll>> vec(h, vector<ll>(w));
    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> vec[i][j];
        }
    }

    vector<vector<pair<ll,ll>>> g(10);
    rep(i, 10){
        rep(j, 10){
            g[i].emplace_back(c[i][j], j);
        }
    }

    vector<ll> res(10);
    rep(i, 10){
        vector<ll> dis = bellman_ford(g, i);
        res[i] = dis[1];
    }

    ll ans = 0;
    rep(i, h){
        rep(j, w){
            if(vec[i][j] == -1){
                continue;
            }
            ans += res[vec[i][j]];
        }
    }

    cout << ans << endl;




}