#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll m, n;
    cin >> m >> n;
    ll k;
    cin >> k;
    vector<string> vec(m);
    vector<vector<ll>> j_sum(m, vector<ll>(n));
    vector<vector<ll>> _sum(m, vector<ll>(n));
　
    for(ll i = 0; i < m; i ++){
        cin >> vec[i];
    }
    vector<pair<ll,ll>> northwest(k);
    vector<pair<ll,ll>> southeast(k);
    rep(i,k){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        northwest[i] = make_pair(a, b);
        southeast[i] = make_pair(c, d);
    }



}