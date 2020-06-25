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
    for(long long i = 0; i < n; i ++){
        ll x, y; cin >> x >> y;
        vec[i] = {x, y};
    }

    ld ans = 0;
    for(ll i = 0; i < n; i++){
        
        ld num = 0;
        ll now_x = 0, now_y = 0;

        for(ll j = 0; j < n; j++){
            if(j == 0){
                now_x = vec[(i + j) % n].first;
                now_y = vec[(i + j) % n].second;
                num = sqrt((now_x) * (now_x) + (now_y) * (now_y));
                continue;
            }
            ll tmp_x = now_x + vec[(i + j) % n].first;
            ll tmp_y = now_y + vec[(i + j) % n].second;
            ll tmp_num = sqrt((tmp_x) * (tmp_x) + (tmp_y) * (tmp_y));

            if(tmp_num > num){
                now_x = tmp_x;
                now_y = tmp_y;
            }
        }

        ld res = sqrt((now_x) * (now_x) + (now_y) * (now_y));
        ans = max(ans, res);

    }

    cout << ans << endl;

}