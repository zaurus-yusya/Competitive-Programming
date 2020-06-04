#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

// g:graph, start: start node  // <cost, next_node>
// resurt: all distance from start node
vector<long long> dijkstra(vector<vector<pair<ll, ll>>> g, ll start){
    vector<ll> distance(g.size(), INF);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
    distance[start] = 0;
    que.push(make_pair(0, start));

    while(!que.empty()){
        pair<long ,long> now = que.top();
        long long now_pos = now.second;
        que.pop();
        if(distance[now_pos] < now.first){
            continue;
        }
        // cost next
        for(long long i = 0; i < g[now_pos].size(); i++){
            pair<long ,long> next = g[now_pos][i];
            long long next_cost = next.first;
            long long next_pos = next.second;
            if(distance[next_pos] > distance[now_pos] + next_cost){
                distance[next_pos] = distance[now_pos] + next_cost;
                que.push(make_pair(distance[next_pos], next_pos));
            }
        }
    }

    // vector<long long>
    return distance;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m, t; cin >> n >> m >> t;
    vector<ll> A(n);
    rep(i, n){
        cin >> A[i];
    }

    vector<vector<pair<ll,ll>>> g(n);
    vector<vector<pair<ll,ll>>> g2(n);
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(c, b);
        g2[b].emplace_back(c, a);
    }

    vector<ll> distance = dijkstra(g, 0);
    vector<ll> distance2 = dijkstra(g2, 0);


    ll ans = 0;
    rep(i, n){
        ll time = t - distance[i] - distance2[i];
        ans = max(ans, A[i] * time);
    }
    cout << ans << endl;

}