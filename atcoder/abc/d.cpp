#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;

    Graph G(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b); G[b].push_back(a);
    }

    vector<ll> dist(n, -1);
    dist[0] = 0;
    queue<ll> que;
    que.push(0);

    
    while(!que.empty()){
        ll now = que.front();
        que.pop();

        rep(i, G[now].size()){
            ll next = G[now][i];
            //cout << "next = " << next << endl;
            if(dist[next] == -1){
                //まだ行ってない
                que.push(next);
                //cout << "push " << next << endl;
                dist[next] = now;
            }else{
                //もういった
                continue;
            }
        }
    }
    rep(i,n){
        if(dist[i] == -1){
            cout << "No" << endl;
            return 0;
        }
    }

    rep(i,n){
        if(i == 0){
            cout << "Yes" << endl;
        }else{
            cout << dist[i] + 1 << endl;
        }
        
    }
    

}