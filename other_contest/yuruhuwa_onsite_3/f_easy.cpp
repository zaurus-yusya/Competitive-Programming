#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
//using Graph = vector<vector<ll>>;
using Graph = vector<vector<pair<ll,ll>>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

vector<bool> seen;
ll ans = 0;

void dfs(const Graph &G, ll v, ll g, ll c)
{
    seen[v] = true;

    //for(ll next_node : G[v]){
    for(ll j = 0; j < G[v].size(); j++){
        ll next_node = G[v].at(j).first;
        
        if(seen[next_node]){
            continue;
        }else{
            ///////
            //cout << "next_node = " << next_node << endl;
            if(next_node == g){
                //cout << "c = " << c << endl;
                //cout << "second = " << G[v].at(j).second << endl;
                ans = (c*G[v].at(j).second)%MOD;
            }else{
                //cout << "second = " << G[v].at(j).second << endl;
                //c = c*G[v].at(j).second;
                dfs(G, next_node, g, (c*G[v].at(j).second)%MOD);
                //c = c/G[v].at(j).second;
            }
            ///////
            
        }
        
    }

}

int main() {
    ll n;
    cin >> n;
    Graph G(n);
    Graph G_score(n);
    rep(i,n-1){
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].push_back(make_pair(v,c)); G[v].push_back(make_pair(u,c));

    }

    /*
    for(ll i = 0; i < G.size(); i++){
        cout << "node " << i << " ";
        cout << "{";
        try{
            for(ll j = 0; j < G[i].size(); j++){
                if(j == G[i].size() - 1) cout << G[i].at(j).first << "[" << G[i].at(j).second << "]";
                else cout << G[i].at(j).first << "[" << G[i].at(j).second << "]" << ", ";
            }
            cout << "}" << endl;
        }catch (std::out_of_range)
        {
            cout << "}" << endl;
        }   
    }
    */

    ll q;
    //ll ans = 0;
    cin >> q;
    rep(i,q){
        ll m, p, x; 
        cin >> m >> p >> x;
        m--;
        p--;
        ans = 0;
        seen.assign(n,false);
        dfs(G, m, p, x);
        cout << ans << endl;

    }

    
    

}