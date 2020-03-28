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
vector<bool> seen;


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;

    Graph G(n);

    rep(i,n-1){
        G[i].push_back(i+1); G[i+1].push_back(i);
    }

    G[x].push_back(y); G[y].push_back(x);


    seen.assign(n,false);

    vector<ll> dist(n, -1);
    map<ll,ll> ans;


    rep(i,n){

        dist.assign(n,-1);
        rep(j,n){
            if(dist[j] != -1){
                cout << "ng" << endl;
            }
        }
        queue<ll> que;
        dist[i] = 0;
        que.push(i);

        while(!que.empty()){
            ll now_pos = que.front();
            que.pop();

            for(ll next_node : G[now_pos]){
                //既に訪問済みなら何もしない
                if(dist[next_node] != -1){
                    continue;
                }
                //now_posから訪問できるノードをqueに追加
                dist[next_node] = dist[now_pos] + 1;
                ans[dist[next_node]]++;
                que.push(next_node);
            }

        }

    }

    ll count = 0;
    for(auto i: ans){
        count++;
        cout << i.second / 2 << endl;
    }
    for(ll i = count; i < n-1; i++){
        cout << 0 << endl;
    }
    
}
