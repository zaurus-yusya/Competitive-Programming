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
using pld = pair<ld, ld>;
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
    vector<pld> circle(n + m);
    vector<ld> radius(n + m, INF);
    rep(i, n + m){
        if(i < n){
            ld x, y, r; cin >> x >> y >> r;
            circle[i] = {x, y};
            radius[i] = r;
        }else{
            ld x, y; cin >> x >> y;
            circle[i] = {x, y};
        }
    }

    for(ll i = 0; i < n + m; i++){
        for(ll j = i + 1; j < n + m; j++){
            if(i < n && j < n){
                continue;
            }else if(i < n && j >= n){
                ld distance = sqrt( (circle[i].first - circle[j].first)*(circle[i].first - circle[j].first) + (circle[i].second - circle[j].second)*(circle[i].second - circle[j].second) );
                radius[j] = min(radius[j], distance - radius[i]);
            }else{
                ld distance = sqrt( (circle[i].first - circle[j].first)*(circle[i].first - circle[j].first) + (circle[i].second - circle[j].second)*(circle[i].second - circle[j].second) );
                radius[i] = min(radius[i], distance / 2);
                radius[j] = min(radius[j], distance / 2);
            }
        }
    }

    ld ans = INF;
    rep(i, radius.size()){
        ans = min(ans, radius[i]);
    }
    cout << ans << endl;

}