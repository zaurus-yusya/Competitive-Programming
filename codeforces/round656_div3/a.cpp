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
    ll t; cin >> t;
    rep(i, t){
        ll x, y, z; cin >> x >> y >> z;
        if(x == y && y == z){
            cout << "YES" << endl;
            cout << x << " " << x << " " << x << endl;
        }else if(x == y){
            if(x > z){
                cout << "YES" << endl;
                cout << x << " " << z << " " << z << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(x == z){
            if(x > y){
                cout << "YES" << endl;
                cout << y << " " << x << " " << y << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(y == z){
            if(y > x){
                cout << "YES" << endl;
                cout << x << " " << x << " " << y << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }

}