#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);

    ll h, w; cin >> h >> w;
    vector<vector<ll>> vec(h, vector<ll>(w));
    rep(i, h){
        rep(j, w){
            cin >> vec[i][j];
        }
    }

    vector<vector<ll>> sum(h+1, vector<ll>(w+1));
    rep(i, h){
        rep(j, w){
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + vec[i][j];
        }
    }

    ll q; cin >> q;
    // sum of [x1, y1) ~ [x2, y2)
    rep(i, q){
        //ll x1, x2, y1, y2;
        ll x1, y1, x2, y2;
        //cin >> x1 >> x2 >> y1 >> y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1] << endl;
    }

}