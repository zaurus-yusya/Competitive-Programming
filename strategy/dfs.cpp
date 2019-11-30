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

//深さ優先探索(グラフを用いたもの)

//通ったか通ってないかを判定する配列(mainでfalseに初期化)
vector<bool> seen;

void dfs(const Graph &G, ll v)
{
    seen[v] = true;

    for(ll next_node : G[v]){
        if(seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            dfs(G, next_node);
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

        //有向グラフ
        //G[a].push_back(b);

        //無向グラフ
        G[a].push_back(b); G[b].push_back(a);

    }

    /////////////////
    //出来上がった木を確認する
    for(ll i = 0; i < G.size(); i++){
        cout << "node " << i << " ";
        cout << "{";
        try{
            for(ll j = 0; j < G[i].size(); j++){
                if(j == G[i].size() - 1) cout << G[i].at(j);
                else cout << G[i].at(j) << ", ";
            }
            cout << "}" << endl;
        }catch (std::out_of_range)
        {
            cout << "}" << endl;
        }   
    }
    /////////////////

    seen.assign(n,false);
    dfs(G, 0);

}