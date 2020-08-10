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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    vector<vector<ll>> vec(h, vector<ll>(w));
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            char c = s[j] - 48;
            vec[i][j] = c;
        }
    }

    if(h >= 4 && w >= 4){
        cout << -1 << endl; return 0;
    } 
    if(h == 1 || w == 1){
        cout << 0 << endl; return 0;
    } 

    ll ans = 0;
    if(h == 2){
        for(ll i = 0; i+1 < w; i++){
            if((vec[0][i] + vec[0][i+1] + vec[1][i] + vec[1][i+1]) % 2 == 0) ans++;
        }
        cout << ans << endl;
        return 0;
    }
    if(w == 2){
        for(ll i = 0; i+1 < w; i++){
            if((vec[i][0] + vec[i+1][0] + vec[i][1] + vec[i+1][1]) % 2 == 0) ans++;
        }
        cout << ans << endl;
        return 0;
    }
    if(h == 3){
        for(ll i = 1; i < w;)

        for(ll i = 0; i+1 < w; i++){
            bool flag = false;
            if((vec[0][i] + vec[0][i+1] + vec[1][i] + vec[1][i+1]) % 2 == 0) flag = true;
            if((vec[1][i] + vec[1][i+1] + vec[2][i] + vec[2][i+1]) % 2 == 0) flag = true;
            if(flag) ans++;
        }
        cout << ans << endl;
        return 0;
    }
    if(w == 3){
        for(ll i = 0; i+1 < w; i++){
            bool flag = false;
            if((vec[i][0] + vec[i+1][0] + vec[i][1] + vec[i+1][1]) % 2 == 0){
                //ans++;
                flag = true;
            }
            if((vec[i][1] + vec[i+1][1] + vec[i][2] + vec[i+1][2]) % 2 == 0){
                //ans++;
                flag = true;
            } 
            if(flag) ans++;
        }
        cout << ans << endl;
        return 0;
    }
    cout << ans << endl;

}