#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
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
    ll n, k;
    cin >> n >> k;

    if(k == 0){
        cout << n * n << endl;
        return 0;
    }

    ll ans = 0;
    for(ll i = k+1; i <= n; i++){
        ll tmp = i - k;
        ans += (n / i) * (i-k);

        if((n % i) - (k-1) > 0){
            ans += ((n % i) - (k-1));
        }
    }

    cout << ans << endl;
    return 0;
}