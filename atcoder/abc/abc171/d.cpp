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
    ll n; cin >> n;
    map<ll, ll> mp;
    ll ans = 0;
    for(long long i = 0; i < n; i ++){
        ll tmp;
        cin >> tmp;
        mp[tmp]++;
        ans += tmp;
    }
    ll Q; cin >> Q;

    rep(q, Q){
        ll b, c; cin >> b >> c;
        if(mp.count(b) == 0){
            cout << ans << endl;
            continue;
        }else{
            ll tmp = c - b;
            ans += ((c - b) * mp[b]);
            mp[c] += mp[b];
            mp[b] = 0;          
        }
        cout << ans << endl;
    }

}