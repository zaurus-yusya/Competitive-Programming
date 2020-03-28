#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
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
    ll n, k;
    cin >> n >> k;
    vector<ll> vec_s(n+1);
    rep(i,n){
        ll a;
        cin >> a;
        vec_s[i + 1] = vec_s[i] + a;
    }

    /*
    rep(i,n+1){
        cout << vec_s[i] << " ";
    }
    cout << endl;

    auto itr = upper_bound(all(vec_s), 6);
    ll tmp = 0;
    tmp += itr - vec_s.begin();
    cout << tmp << endl;
    */
    
    
    ll ans = 0;
    rep(i, n+1){
        if(vec_s[i] >= k){
            auto itr = upper_bound(all(vec_s), vec_s[i] - k);
            ans += itr - vec_s.begin();
        }
    }

    cout << ans << endl;
    
    
}