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
    ll d; cin >> d;
    ll n; cin >> n;
    ll m; cin >> m;
    vector<ll> store(n-1);
    rep(i, n-1){
        cin >> store[i];
    }
    store.push_back(0);
    store.push_back(d);
    sort(all(store));
    vector<ll> order(m);
    rep(i, m){
        cin >> order[i];
    }
    
    ll ans = 0;
    
    rep(i, m){
        ll tmp = lower_bound(store.begin(), store.end(), order[i]) - store.begin();
        ans += min(abs(order[i] - store[tmp]), abs(order[i] - store[tmp-1]));
    }
    cout << ans << endl;


}