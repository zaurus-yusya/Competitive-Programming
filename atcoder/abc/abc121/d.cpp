#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b; cin >> a >> b;
    if(a != 0) a--;

    ll tmp = a % 4;
    ll tmp2 = b % 4;
    ll x, y;
    if(tmp == 0){
        x = a;
    }else if(tmp == 1){
        x = 1;
    }else if(tmp == 2){
        x = a + 1;
    }else{
        x = 0;
    }

    if(tmp2 == 0){
        y = b;
    }else if(tmp2 == 1){
        y = 1;
    }else if(tmp2 == 2){
        y = b + 1;
    }else{
        y = 0;
    }

    cout << (x ^ y) << endl;
    
}