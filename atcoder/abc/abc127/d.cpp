#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
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
    vector<long long> vec(n);
    for(long long i = 0; i < n; i++){
        cin >> vec[i];
    }
    sort(all(vec));

    vector<pair<ll,ll>> card(m);
    rep(i, m){
        ll b, c; cin >> b >> c;
        card[i] = make_pair(c, b);
    }
    sort(all(card));
    
    ll now = m-1;
    for(ll i = 0; i < n; i++){
        if(card[now].second <= 0){
            now -= 1;
        }
        if(vec[i] < card[now].first){
            vec[i] = card[now].first;
            card[now].second--;
        }
    }

    ll ans = 0;
    rep(i, n){
        ans += vec[i];
    }
    cout << ans << endl;
    
}