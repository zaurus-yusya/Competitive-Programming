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

ll n, m;

//通ったか通ってないかを判定する配列(mainでfalseに初期化)
vector<bool> seen;
vector<bool> in_seen;

ll ans = 0;

void dfs(const Graph &G, ll v, vector<bool> in_seen)
{
    in_seen[v] = true;

    bool all_visit_flag = true;
    for(int i = 0; i < n; i++){
        if(in_seen[i] == false){
            all_visit_flag = false;
        }
    }

    if(all_visit_flag){
        ans++;
    }

    for(ll next_node : G[v]){
        if(in_seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            dfs(G, next_node, in_seen);
        }
    }

}


int main() {
    //n:頂点の数, m:辺の数

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
    in_seen.assign(n,false);
    dfs(G, 0, in_seen);

    cout << ans << endl;


}
