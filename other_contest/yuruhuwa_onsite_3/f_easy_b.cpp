#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;
const int MOD = 1e9+7;


ll ans = 0;

using Graph = vector<vector<pair<ll,ll>>>;

vector<bool> seen;
void dfs(const Graph &G, ll v, ll p, ll c)
{
    seen[v] = true;
    if(v == p){
        ans = c;
    }

    for(ll j = 0; j < G[v].size(); j++){
        ll next_node = G[v].at(j).first;
        
        if(seen[next_node]){
            continue;
        }else{
            dfs(G, next_node, p, (c*G[v].at(j).second)%MOD);
        }
        
    }

}

int main() {
    ll n;
    cin >> n;

    Graph G(n);
    rep(i,n-1){
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].push_back(make_pair(v,c));
        G[v].push_back(make_pair(u,c));
    }


    ll q;
    cin >> q;

    rep(i,q){
        ll m, p, x; 
        cin >> m >> p >> x;
        m--;
        p--;

        seen.assign(n,false);
        dfs(G, m, p, x);

        cout << ans << endl;
    }
}