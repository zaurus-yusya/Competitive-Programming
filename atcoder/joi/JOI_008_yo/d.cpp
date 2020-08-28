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

vector<pll> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll m, n;
vector<vector<ll>> vec(n, vector<ll>(m));
ll ans = 0;


ll dfs(ll y, ll x, ll count, vector<vector<bool>> seen){
    seen[y][x] = true;
    ll res = count+1;

    for(ll next = 0; next < 4; next++){
        ll next_y = y + direction[next].first;
        ll next_x = x + direction[next].second;
        if(next_y < 0 || next_y >= n){
            continue;
        }
        if(next_x < 0 || next_x >= m){
            continue;
        }

        if(seen[next_y][next_x] == false && vec[next_y][next_x] == 1){
            res = max(res, dfs(next_y, next_x, count+1, seen));
        }
    }
    
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> m >> n;
    vec.resize(n, vector<ll>(m));


    rep(i, n){
        rep(j, m){
            cin >> vec[i][j];
        }
    }

    rep(i, n){
        
        rep(j, m){
            if(vec[i][j] == 1){
                vector<vector<bool>> seen(n, vector<bool>(m, false));
                //cout << "----------" << endl;
                ans = max(ans, dfs(i, j, 0, seen));
                //cout << tmp << endl;
                //cout << "----------" << endl;
                //ans = max(ans, tmp);
            }
        }
    }

    cout << ans << endl;
    

}