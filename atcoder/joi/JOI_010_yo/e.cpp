#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
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


ll h, w, n;
vector<vector<string>> vec(h, vector<string>(w));

vector<ll> next_y_c{-1,1,0,0};
vector<ll> next_x_c{0,0,-1,1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    
    cin >> h >> w >> n;
    vec.resize(h, vector<string>(w));
    vector<pair<ll,ll>> target(n+1);
    
    string s;
    
    for(long long i = 0; i < h; i++){
        cin >> s;
        for(long long j = 0; j < w; j++){
            vec[i][j] = s[j];
            
            if(vec[i][j] == "S") target[0] = make_pair(i, j);
            rep(k, n){
                if(vec[i][j][0] - '0' == k+1){
                    target[k+1] = make_pair(i, j);
                }
            }
        }
    }
    
    /*
    rep(i,n+1){
        cout << target[i].first << " " << target[i].second << endl;
    }
    */

    ll ans = 0;

    rep(i,n){
        vector<vector<ll>> dist(h, vector<ll>(w, -1));
        queue< pair<ll,ll> > que;
        dist[target[i].first][target[i].second] = 0;
        que.push(make_pair(target[i].first, target[i].second));

        while(!que.empty()){
            pair<ll,ll> now_pos = que.front();
            ll now_y = now_pos.first;
            ll now_x = now_pos.second;
            que.pop();
            rep(j, 4){
                ll next_y = now_y + next_y_c[j];
                ll next_x = now_x + next_x_c[j];

                if(next_y < 0 || next_y >= h || next_x < 0 || next_x >= w){
                    continue;
                }

                if(vec[next_y][next_x] == "X"){
                    continue;
                }

                if(dist[next_y][next_x] != -1){
                    continue;
                }

                dist[next_y][next_x] = dist[now_y][now_x] + 1;
                que.push(make_pair(next_y, next_x));

            }
        }

        ans += dist[target[i+1].first][target[i+1].second];
    }

    cout << ans << endl;





    
    
    


}