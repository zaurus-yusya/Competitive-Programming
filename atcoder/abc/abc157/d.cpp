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
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)
// コンパイル　g++ -std=c++17 a.cpp

vector<ll> unit_label;
vector<ll> union_size;
ll current_size;
void dfs(const Graph &G, ll v, const ll &label){
    unit_label[v] = label;
    current_size++;
    for(ll next_node : G[v]){
        if(unit_label[next_node] != -1){
            continue;
        }else{
            dfs(G, next_node, label);
        }
    }

}

//dfs
int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> friend_num(n, 0);
    Graph G(n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        //無向グラフ
        G[a].push_back(b); G[b].push_back(a);
        friend_num.at(a)++;
        friend_num.at(b)++;
    }

    unit_label.assign(n,-1);
    ll label = 0;
    rep(i,n){
        if(unit_label[i] == -1){
            current_size = 0;
            dfs(G, i, label);
            union_size.push_back(current_size);
            label++;
        } 
    }

    vector<ll> block_num(n, 0);
    for (ll i = 0; i < k; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(unit_label.at(a) == unit_label.at(b)){
            block_num.at(a)++;
            block_num.at(b)++;
        }
    }

    rep(i,n){
        cout << union_size.at(unit_label.at(i)) - 1 - friend_num.at(i) - block_num.at(i) << " ";
    }
    cout << endl;


}