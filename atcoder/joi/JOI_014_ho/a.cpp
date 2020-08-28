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
    ll n, m; cin >> n >> m;
    vector<ll> plan(m);
    rep(i, m){
        cin >> plan[i];
        plan[i]--;
    }

    vector<ll> paper(n-1);
    vector<ll> ic(n-1);
    vector<ll> ic_fee(n-1);

    rep(i, n-1){
        cin >> paper[i] >> ic[i] >> ic_fee[i];
    }

    vector<ll> imos(n);
    rep(i, m-1){
        ll l = plan[i];
        ll r = plan[i+1];
        if(l > r){
            swap(l, r);
        }
        imos[l]++;
        imos[r]--;
    }
    
    rep(i, n+1){
        if(i > 0){
            imos[i] += imos[i-1];
        }
    }

    ll ans = 0;
    rep(i, imos.size()){
        ans += min(imos[i] * paper[i], imos[i] * ic[i] + ic_fee[i]);
    }
    cout << ans << endl;

}