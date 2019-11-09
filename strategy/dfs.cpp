#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;

//深さ優先探索(グラフを用いたもの)

//通ったか通ってないかを判定する配列(mainでfalseに初期化)
vector<bool> seen;

void dfs(const Graph &G, int v)
{
    seen[v] = true;

    for(int next_node : G[v]){
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
    int n, m;
    cin >> n >> m;

    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        //有向グラフ
        //G[a].push_back(b);

        //無向グラフ
        G[a].push_back(b); G[b].push_back(a);

        seen.assign(n,false);
        dfs(G, 0);

    }

}