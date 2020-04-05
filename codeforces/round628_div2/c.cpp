#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
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

vector<vector<pair<ll, ll>>> to;
vector<ll> ans;


vector<bool> seen;
ll x = 0;
ll before = 0;
ll after = 0;

void dfs(ll v)
{
    seen[v] = true;

    for(ll i = 0; i < to[v].size(); i++){
        ll next_node = to[v][i].first;
        ll edge_id = to[v][i].second;

        if(seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            if(x % 2 == 0){
                ans[edge_id] = before;
                before++;
            }else{
                ans[edge_id] = after;
                after--;
            }
            x++;
            dfs(next_node);
        }
    }

}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n;
    cin >> n;
    to.resize(n);
    ans.resize(n);

    rep(i,n-1){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        to[v].pb(make_pair(u, i));
        to[u].pb(make_pair(v, i));
    }

    seen.assign(n,false);
    after = n-2;
    dfs(0);

    rep(i,ans.size() - 1){
        cout << ans[i] << endl;
    }
    cout << endl;
    
    //cout << x << endl;




}