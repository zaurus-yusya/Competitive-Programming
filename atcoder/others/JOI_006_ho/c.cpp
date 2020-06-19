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

    vector<vector<bool>> tmp(5001, vector<bool>(5001));

    rep(i, n){
        ll x, y; cin >> x >> y;
        vec[i] = {x, y};
        tmp[x][y] = true;
    }
    sort(all(vec));

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            ll area = (vec[i].first - vec[j].first) * (vec[i].first - vec[j].first) + (vec[i].second - vec[j].second) * (vec[i].second - vec[j].second);

            bool flag1 = true;
            ll x1 = vec[i].first + (vec[j].second - vec[i].second);
            ll y1 = vec[i].second - (vec[j].first - vec[i].first);
            ll x2 = vec[j].first + (vec[j].second - vec[i].second);
            ll y2 = vec[j].second - (vec[j].first - vec[i].first);
            if(x1 < 0 || x1 > 5000){
                flag1 = false;
            }
            if(y1 < 0 || y1 > 5000){
                flag1 = false;
            }
            if(x2 < 0 || x2 > 5000){
                flag1 = false;
            }
            if(y2 < 0 || y2 > 5000){
                flag1 = false;
            }

            bool flag2 = true;
            ll x3 = vec[i].first - (vec[j].second - vec[i].second);
            ll y3 = vec[i].second + (vec[j].first - vec[i].first);
            ll x4 = vec[j].first - (vec[j].second - vec[i].second);
            ll y4 = vec[j].second + (vec[j].first - vec[i].first);
            if(x3 < 0 || x3 > 5000){
                flag2 = false;
            }
            if(y3 < 0 || y3 > 5000){
                flag2 = false;
            }
            if(x4 < 0 || x4 > 5000){
                flag2 = false;
            }
            if(y4 < 0 || y4 > 5000){
                flag2 = false;
            }

            if(flag1 && tmp[x1][y1] && tmp[x2][y2]){
                ans = max(ans, area);
            }
            if(flag2 && tmp[x3][y3] && tmp[x4][y4]){
                ans = max(ans, area);
            }

        }
    }

    cout << ans << endl;



}