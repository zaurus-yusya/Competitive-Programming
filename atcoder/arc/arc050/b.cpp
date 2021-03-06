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
    ll r, b; cin >> r >> b;
    ll x, y; cin >> x >> y;

    ll left = -1, right = 1e18;

    while(right - left > 1){
        
        ll mid = (left + right) / 2;
        ll tmp_x = r - mid;
        ll tmp_y = b - mid;
        if(tmp_x < 0 || tmp_y < 0){
            right = mid;
        }else if( (tmp_x / (x-1)) + (tmp_y / (y-1)) >= mid){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout << left << endl;
}