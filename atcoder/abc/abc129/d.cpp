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
    ll h, w;
    cin >> h >> w;
    vector<vector<string>> vec(h, vector<string>(w));

    string s;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec[i][j] = s[j];
        }
    }

    vector<vector<ll>> left(h, vector<ll>(w));
    vector<vector<ll>> right(h, vector<ll>(w));
    vector<vector<ll>> up(h, vector<ll>(w));
    vector<vector<ll>> down(h, vector<ll>(w));

    rep(i,h){
        rep(j,w){
            if(vec[i][j] == "#") continue;
            if(j == 0){
                left[i][j] = 1;
                continue;
            }else{
                left[i][j] = left[i][j-1] + 1;
            }
        }
    }

    for(long long i = 0; i < h; i++){
        for(long long j = w-1; j >= 0; j--){
            if(vec[i][j] == "#") continue;
            if(j == w-1){
                right[i][j] = 1;
                continue;
            }else{
                right[i][j] = right[i][j + 1] + 1;
            }
        }
    }

    for(long long j = 0; j < w; j++){
        for(long long i = 0; i < h; i++){
            if(vec[i][j] == "#") continue;
            if(i == 0){
                up[i][j] = 1;
                continue;
            }else{
                up[i][j] = up[i-1][j] + 1;
            }
        }
    }

    for(long long j = 0; j < w; j++){
        for(long long i = h-1; i >= 0; i--){
            if(vec[i][j] == "#") continue;
            if(i == h-1){
                down[i][j] = 1;
                continue;
            }else{
                down[i][j] = down[i+1][j] + 1;
            }
        }
    }

    ll ans = 0;
    rep(i,h){
        rep(j,w){
            chmax(ans, left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3);
        }
    }

    cout << ans << endl;


}