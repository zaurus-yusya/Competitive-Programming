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
    ll h, w, k; cin >> h >> w >> k;
    vector<vector<string>> vec(h, vector<string>(w));
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            vec[i][j] = s[j];
        }
    }

    ll ans = 0;
    for(ll row = 0; row < (1 << h); row++){
        for(ll col = 0; col < (1 << w); col++){
            ll count = 0;
            for(ll i = 0; i < h; i ++){
                for(ll j = 0; j < w; j++){
                    if(row >> i & 1){
                        continue;
                    }
                    if(col >> j & 1){
                        continue;
                    }
                    if(vec[i][j] == "#"){
                        count++;
                    }
                }
            }
            if(count == k){
                ans++;
            }
        }
    }

    cout << ans << endl;

}