#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define INF 1e+9
#define MAX_V 1000000

struct Edge {
    ll to;     // 辺の行き先
    ll weight; // 辺の重み
    Edge(ll t, ll w) : to(t), weight(w) { }
};

using Graph = vector<vector<Edge>>;
Graph G(MAX_V);

using P = pair<ll, ll>;
ll d[MAX_V];

void dijkstra(ll s, ll n) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;

        for (ll i=0; i<G[v].size(); ++i) {
            Edge e = G[v][i];
            if (d[e.to] > d[v] + e.weight) {
                d[e.to] = d[v] + e.weight;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


int main() {
    ll n, m;
    cin >> n >> m;
    
    //Graph G(n);
    rep(i,m){
        ll l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;

        for(ll j = l; j < r; j++){
            for(ll k = j + 1; k <= r; k++){
                ll from = j;
                ll to = k;

                G[from].pb(Edge(to,c));
                G[to].pb(Edge(from, c));
            }
        }
    }

    dijkstra(0,n);

    if(d[n-1] == 0 || d[n-1] == INF){
        cout << -1 << endl;
    }else{
        cout << d[n-1] << endl;
    }


}
