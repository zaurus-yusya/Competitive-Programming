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
    ll m; cin >> m;
    vector<pll> star(m);
    rep(i, m){
        ll x, y; cin >> x >> y;
        star[i] = {x, y};

    }

    ll n; cin >> n;

    vector<pll> stars(n);
    map<pll, ll> mp;

    rep(i, n){
        ll x, y; cin >> x >> y;
        stars[i] = {x, y};
        mp[{x, y}]++;
    }

    for(ll i = 0; i < n; i++){
        ll ans_x = 0, ans_y = 0;
        for(ll j = 0; j < m; j++){
            
            if(j == 0){
                ans_x = stars[i].first - star[j].first;
                ans_y = stars[i].second - star[j].second;
            }

            bool flag = true;
            for(ll k = 0; k < m; k++){
                if(star[k].first + ans_x < 0 || star[k].first + ans_x > 1000000){
                    continue;
                }
                if(star[k].second + ans_y < 0 || star[k].second + ans_y > 1000000){
                    continue;
                }
                
                if(mp[{star[k].first + ans_x, star[k].second + ans_y}] >= 1){
                    continue;
                }else{
                    flag = false;
                    break;
                }

            }

            if(flag){
                cout << ans_x << " " << ans_y << endl;
                return 0;
            }

        }
    }
    



}