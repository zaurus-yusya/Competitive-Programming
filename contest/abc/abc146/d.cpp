#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
using Graph = vector<vector<ll>>;
ll INF = 1000000007;

// 0 false, 1 true

//通ったか通ってないかを判定する配列(mainでfalseに初期化)
vector<bool> seen;

Graph Hen(0);

void dfs(const Graph &G, int v)
{
    seen[v] = true;

    for(int next_node : G[v]){
        if(seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ll num = 1;
            while(true){
                
                Hen[a].pb(num);
                Hen[b].pb(num);

                cout << num << endl;
                
            }
            ///////
            dfs(G, next_node);
        }
    }

}


int main() {
    ll n;
    cin >> n;

    Graph G(n+1);
    Hen.resize(n+1);
    
    rep(i,n-1){
        ll a, b;
        cin >> a >> b;

        G[a].push_back(b); G[b].push_back(a);

        ll num = 1;
        while(true){
            Hen[a]


            break;
            num++;
        }

        Hen[a].push_back();

    }

    rep(i,n-1){
        Hen()
    }

    seen.assign(n,false);
    dfs(G, 1);


}
