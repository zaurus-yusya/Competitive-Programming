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
    ll x; cin >> x;
    if(400 <= x && x <= 599){
        cout << 8 << endl;
    }
    if(600 <= x && x <= 799){
        cout << 7 << endl;
    }
    if(800 <= x && x <= 999){
        cout << 6 << endl;
    }
    if(1000 <= x && x <= 1199){
        cout << 5 << endl;
    }
    if(1200 <= x && x <= 1399){
        cout << 4 << endl;
    }
    if(1400 <= x && x <= 1599){
        cout << 3 << endl;
    }
    if(1600 <= x && x <= 1799){
        cout << 2 << endl;
    }
    if(1800 <= x && x <= 1999){
        cout << 1 << endl;
    }

}

