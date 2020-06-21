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

ll w, h; 
vector<pll> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//vector<vector<ll>> vec(h, vector<ll>(w));
//vector<vector<bool>> seen(h, vector<bool>(w));

void dfs(vector<vector<ll>> &vec, vector<vector<bool>> &seen, ll y, ll x){
    seen[y][x] = true;

    /*
    cout << "---" << endl;
    rep(i, h){
        rep(j, w){
            cout << vec[i][j] << " ";
        }
        br;
    }
    cout << "---" << endl;
    */

    if(vec[y][x] == 1){
        for(ll i = 0; i < direction.size(); i++){
            ll next_y = y + direction[i].first;
            ll next_x = x + direction[i].second;

            //場外なら終わり
            if(next_y < 0 || next_y >= h){
                continue;
            }
            if(next_x < 0 || next_x >= w){
                continue;
            }

            if(seen[next_y][next_x] == false && vec[next_y][next_x] == 1){
                dfs(vec, seen, next_y, next_x);
            }
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);

    vector<ll> res;

    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        vector<vector<ll>> vec(h, vector<ll>(w));
        vector<vector<bool>> seen(h, vector<bool>(w));
        vec.resize(h, vector<ll>(w, 0));
        seen.resize(h, vector<bool>(w, false));
        
        rep(i, h){
            rep(j, w){
                cin >> vec[i][j];
            }
        }

        ll ans = 0;
        rep(i, h){
            rep(j, w){
                if(vec[i][j] == 1 && seen[i][j] == false){
                    ans++;
                    dfs(vec, seen, i, j);
                }
            }
        }
        res.push_back(ans);

    }

    rep(i, res.size()){
        cout << res[i] << endl;
    }

}