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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n;
    cin >> n;

    Graph G(n+1);
    for (ll i = 0; i < n-1; ++i) {
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

}