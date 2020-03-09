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
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

const int M = 200010;
const int MLV = 18; 

vector<int> G[M];
int root;
int n,q;
int parent[M];
int depth[M];

void dfs(int v,int p,int d){
	parent[v] = p;
	depth[v] = d;
	for(int i = 0;i < G[v].size();i++){
		if(G[v][i] != p) dfs(G[v][i],v,d + 1);
	}
}

void init(){
	dfs(root,-1,0);
}

int lca(int u,int v){
	while(depth[u] > depth[v])u = parent[u];
	while(depth[v] > depth[u])v = parent[v];
	while(u != v){
		v = parent[v];
		u = parent[u];
	}
	return u;
}


int main() {
    ll n;
    cin >> n;
    rep(i,n-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    init();

    cout << "depth------" << endl;
    rep(i,n){
        cout << depth[i] << endl;
    }
    cout << "parent------" << endl;
    rep(i,n){
        cout << parent[i] << endl;
    }
    cout << "------" << endl;

    vector<pair<ll,ll>> pairs;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            ll tmp = lca(i, j);
            if(tmp == i || tmp == j){
                if(abs(depth[i] - depth[j]) == 3){
                    pairs.emplace_back(i, j);
                }
            }else{
                if(depth[i] + depth[j] - (2 * depth[tmp]) == 3){
                    pairs.emplace_back(i, j);
                }
            }
        }
    }

    rep(i,pairs.size()){
        cout << pairs[i].first << " " << pairs[i].second <<endl;
    }

    //cout << lca(4, 5) << endl;






}