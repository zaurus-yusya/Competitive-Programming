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

const ll M = 200010;
const ll MLV = 18; 

vector<ll> G[M];
ll root;
ll n,q;
ll parent[MLV][M];
ll depth[M];

void dfs(int v,int p,int d){
	parent[0][v] = p;
	depth[v] = d;
	for(int i = 0;i < G[v].size();i++){
		if(G[v][i] != p) dfs(G[v][i],v,d + 1);
	}
}

void init(ll V){
	dfs(root,-1,0);
	for(ll k = 0;k+1 < MLV;k++){
		for(ll v = 1;v <= V;v++){
			if(parent[k][v] < 0) parent[k+1][v] = -1;
			else parent[k+1][v] = parent[k][parent[k][v]];
		}
	}
}

ll lca(ll u, ll v){
	if(depth[u] > depth[v]) swap(u,v);
	for(ll k = 0;k < MLV;k++){
		if((depth[v] - depth[u]) >> k & 1){
			v = parent[k][v];
		}
	}
	if(u == v)return u;
	for(ll k = MLV-1;k >= 0;k--){
		if(parent[k][u] != parent[k][v]){
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}


int main() {
    
    cin >> n;
    rep(i,n-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    init(n);

    cout << "depth------" << endl;
    rep(i,n){
        cout << depth[i] << endl;
    }
    cout << "parent------" << endl;
    rep(i,n){
        cout << parent[0][i]  << " " << parent[1][i] << endl;
    }
    cout << "------" << endl;

    
    vector<pair<ll,ll>> pairs;
    for(ll i = 0; i < n-1; i++){
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



    //答え
    ll one, two, three;
    if(n % 3 == 0){
        one = n / 3;
        two = n / 3;
        three = n / 3;
    }else if(n % 3 == 1){
        one = n / 3 + 1;
        two = n / 3;
        three = n / 3;
    }else if(n % 3 == 2){
        one = n / 3 + 1;
        two = n / 3 + 1;
        three = n / 3;
    }

    vector<ll> one_vec(one);
    vector<ll> two_vec(two);
    vector<ll> three_vec(three);

    //cout << lca(4, 5) << endl;

}