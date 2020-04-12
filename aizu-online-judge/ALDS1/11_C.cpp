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
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    rep(i, n){
        ll num;
        cin >> num;
        num--;
        ll edgenum;
        cin >> edgenum;
        rep(j,edgenum){
            ll next;
            cin >> next;
            next--;
            g[num].push_back(next);
        }
    }

    queue<ll> que;
    que.push(0);
    vector<ll> ans(n, -1);
    ans[0] = 0;
    while(!que.empty()){
        ll now = que.front();
        ll dist = ans[now];
        que.pop();
        for(ll i = 0; i < g[now].size(); i++){
            if(ans[g[now][i]] != -1){
                continue;
            }

            ans[g[now][i]] = ans[now] + 1;
            que.push(g[now][i]);

        }
    }

    rep(i,g.size()){
        cout << i+1 << " " << ans[i] << endl;
    }



}