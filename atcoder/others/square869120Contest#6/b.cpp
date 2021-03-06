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
    vector<pll> vec(n);
    rep(i, n){
        ll a, b; cin >> a >> b;
        vec[i] = {a, b};
    }

    ll ans = 1e15;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            ll iriguchi = vec[i].first;
            ll deguchi = vec[j].second;
            ll num = 0;
            for(ll k = 0; k < n; k++){
                num += abs(iriguchi - vec[k].first) + vec[k].second - vec[k].first + abs(vec[k].second - deguchi);
            }
            ans = min(ans, num);

        }
    }

    cout << ans << endl;

}