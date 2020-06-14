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
    ll x, n; cin >> x >> n;

    if(n == 0){
        cout << x << endl;
        return 0;
    }

    map<ll,ll> mp;
    for(long long i = 0; i < n; i ++){
        ll p; cin >> p;
        mp[p]++;
    }
    ll ans = INF;
    ll res = 0;
    for(ll i = -110; i <= 210; i++){
        if(mp.count(i) == 0){
            if(abs(x-i) < ans){
                ans = abs(x-i);
                res = i;
            }
        }
    }

    cout << res << endl;


}