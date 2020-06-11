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
    ll n, k; cin >> n >> k;

    if(k % 2 != 0){
        ll tmp = n / k;
        cout << tmp * tmp * tmp << endl;
    }

    if(k % 2 == 0){
        ll tmp = n / k;
        ll tmp2 = 0;
        if(n % k >= k / 2){
            tmp2 = tmp  + 1;
        }else{
            tmp2 = tmp;
        }
        cout << (tmp * tmp * tmp) + (tmp2 * tmp2 * tmp2) << endl;
    }

}