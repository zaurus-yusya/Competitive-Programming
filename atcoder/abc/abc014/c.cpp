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
    ll n;
    cin >> n;
    vector<ll> vec(1000002);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        vec[a]++;
        vec[b+1]--;
    }

    ll tmp = 0;

    rep(i,1000001){
        if(i > 0){
            vec[i] += vec[i-1];
        }
    }

    ll ans = 0;
    rep(i,1000001){
        chmax(ans, vec[i]);
    }

    cout << ans <<endl;

}