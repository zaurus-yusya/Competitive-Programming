#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e5;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;
    vector<long long> vec(n-1);
    vector<long long> sum(n-1 + 1);
    rep(i, n-1){
        cin >> vec[i];
        sum[i+1] = vec[i] + sum[i];
    }

    vector<long long> move(m);
    for(long long i = 0; i < m; i ++){
        cin >> move[i];
    }

    ll ans = 0;
    ll now = 1;
    rep(i,m){
        ll next = now + move[i];
        ans = (ans + abs(sum[next-1] - sum[now-1]) ) % MOD;
        //cout << i << " now = " << now << " next = " << next << " ans = " << ans << endl;
        now = next;
    }

    cout << ans << endl;

}