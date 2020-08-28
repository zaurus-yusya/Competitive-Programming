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

vector<pll> direction_odd = {{-1, 0}, {0, -1}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
vector<pll> direction_even = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 1}, {1, 0}};
ll w, h;
//vector<vector<ll>> vec(h+2, vector<ll>(w+2));
//vector<vector<bool>> seen(h+2, vector<bool>(w+2));
vector<vector<ll>> vec;
vector<vector<bool>> seen;
vector<pll> tmp;
ll ans = 0;


void calc(ll y, ll x){
    seen[y][x] = true;

    if(y % 2 == 0){
        for(ll next = 0; next < 6; next++){
            ll next_y = y + direction_even[next].first;
            ll next_x = x + direction_even[next].second;
            if(next_y < 0 || next_y >= h+2){
                continue;
            }
            if(next_x < 0 || next_x >= w+2){
                continue;
            }
            if(vec[next_y][next_x] == 1){
                ans++;
                continue;
            }

            if(seen[next_y][next_x] == false && vec[next_y][next_x] == 0){
                calc(next_y, next_x);
            }
        }
    }else{
        for(ll next = 0; next < 6; next++){
            ll next_y = y + direction_odd[next].first;
            ll next_x = x + direction_odd[next].second;
            if(next_y < 0 || next_y >= h+2){
                continue;
            }
            if(next_x < 0 || next_x >= w+2){
                continue;
            }
            if(vec[next_y][next_x] == 1){
                ans++;
                continue;
            }

            if(seen[next_y][next_x] == false && vec[next_y][next_x] == 0){
                calc(next_y, next_x);
            }
        }
    }

}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> w >> h;
    vec.resize(h+2, vector<ll>(w+2));
    seen.resize(h+2, vector<bool>(w+2));
    rep(i, h+2){
        rep(j, w+2){
            if(i == 0 || i == h+1){
                continue;
            }
            if(j == 0 || j == w+1){
                continue;
            }
            cin >> vec[i][j];
        }
    }

    calc(0, 0);

    /*
    rep(i, h+2){
        rep(j, w+2){
            cout << seen[i][j] << " ";
        }
        br;
    }
    */
    
    cout << ans << endl;
}