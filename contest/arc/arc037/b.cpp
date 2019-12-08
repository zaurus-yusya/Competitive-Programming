#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
vector<bool> seen;

ll ans = 0;
ll heiro_flag = true;


void dfs(const Graph &G, ll v, ll before_node)
{
    if(seen[v] == true){
        heiro_flag = false;
        return;
    }
    seen[v] = true;

    for(ll next_node : G[v]){
        if(seen[next_node]){
            if(next_node != before_node && before_node != -1){
                heiro_flag = false;
            }
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            dfs(G, next_node, v);
        }
    }

}


int main() {
    //n:頂点の数, m:辺の数
    ll n, m;
    cin >> n >> m;

    Graph G(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        //有向グラフ
        //G[a].push_back(b);

        //無向グラフ
        G[a].push_back(b); G[b].push_back(a);

    }


    seen.assign(n,false);

    for(ll i = 0; i < n; i++){
        if(seen[i] == false){
            dfs(G, i, -1);

            if(heiro_flag == true){
                ans++;
            }
            heiro_flag = true;
        }  
    }

    cout << ans << endl;



}
