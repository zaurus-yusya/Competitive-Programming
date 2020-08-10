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
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

vector<ll> next_y = {-1,1,0,0};
vector<ll> next_x = {0,0,-1,1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll h, w; cin >> h >> w;
        vector<vector<string>> vec(h, vector<string>(w));
        rep(i, h){
            string s; cin >> s;
            rep(j, w){
                vec[i][j] = s[j];
            }
        }
        ll ans = 0;
        for(ll i = 0; i < w; i++){
            if(vec[h-1][i] == "D"){
                ans++;
            }
        }

        for(ll i = 0; i < h; i++){
            if(vec[i][w-1] == "R"){
                ans++;
            }
        }

        cout << ans << endl;



    }

}