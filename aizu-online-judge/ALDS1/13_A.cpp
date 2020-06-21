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
    ll k; cin >> k;
    vector<vector<string>> chess(8, vector<string>(8, "-"));
    vector<ll> tate(8);
    vector<ll> yoko(8);
    rep(i, k){
        ll r, c; cin >> r >> c;
        chess[r][c] = "Q";
        tate[r] = 1; yoko[c] = 1;
    }

    vector<vector<string>> chess2(8, vector<string>(8, "-"));
    chess2 = chess;
    for(ll i = 0; i < 8; i++){
        if(tate[i] == 1){
            continue;
        }
        tate[i] = 1;
        for(ll j = 0; j < 8; j++){
            if(yoko[j] == 1){
                continue;
            }
            yoko[j] = 1;
            break;
        }
    }
    


}