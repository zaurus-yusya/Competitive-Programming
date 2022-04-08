#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}
// for(auto& i: mp) &&&&&&&&&&&&&

struct X {
    ll y;
    ll x;
    ll muki;
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    ll ay, ax; cin >> ay >> ax; ay--; ax--;
    ll by, bx; cin >> by >> bx; by--; bx--;
    vector<vector<char>> vec(n, vector<char>(n));
    rep(i, n){
        string s; cin >> s;
        rep(j, n){
            vec[i][j] = s[j];
        }
    }

    vector<ll> dy = {1, -1, 1, -1};
    vector<ll> dx = {1, -1, -1, 1};
    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(n, vector<ll>(4, INF)));
    deque<X> deq;
    
    rep(i, 4){
        dist[ay][ax][i] = 1;
        deq.push_front({ay, ax, i});
    }
    
    while(!deq.empty()){
        X now = deq.front();
        deq.pop_front();
        ll nowy = now.y, nowx = now.x, nowmuki = now.muki;

        rep(i, 4){
            if(nowmuki == i){
                ll nexty = nowy + dy[i];
                ll nextx = nowx + dx[i];
                ll nextmuki = nowmuki;
                //場外ならcontinue
                if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n){
                    continue;
                }
                //壁ならcontinue
                if(vec[nexty][nextx] == '#'){
                    continue;
                }
                //訪問済みならcontinue
                // if(dist[nexty][nextx][nextmuki] != INF){
                //     continue;
                // }

                if(dist[nexty][nextx][nextmuki] > dist[nowy][nowx][nowmuki]){
                    dist[nexty][nextx][nextmuki] = dist[nowy][nowx][nowmuki];
                    deq.push_front({nexty, nextx, nextmuki});
                }

                // dist[nexty][nextx][nextmuki] = dist[nowy][nowx][nowmuki];
                // deq.push_front({nexty, nextx, nextmuki});

            }else{
                ll nexty = nowy + dy[i];
                ll nextx = nowx + dx[i];
                ll nextmuki = i;
                //場外ならcontinue
                if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n){
                    continue;
                }
                //壁ならcontinue
                if(vec[nexty][nextx] == '#'){
                    continue;
                }
                //訪問済みならcontinue
                // if(dist[nexty][nextx][nextmuki] != INF){
                //     continue;
                // }

                if(dist[nexty][nextx][nextmuki] > dist[nowy][nowx][nowmuki] + 1){
                    dist[nexty][nextx][nextmuki] = dist[nowy][nowx][nowmuki] + 1;
                    deq.push_back({nexty, nextx, nextmuki});
                }

                // dist[nexty][nextx][nextmuki] = dist[nowy][nowx][nowmuki] + 1;
                // deq.push_back({nexty, nextx, nextmuki});

            }
        }
    }

    ll ans = INF;
    rep(i, 4){
        ans = min(ans, dist[by][bx][i]);
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    /*
    cout << "----" << endl;
    rep(i, n){
        rep(j, n){
            if(dist[i][j][0] == INF){
                cout << -1 << " "; continue;
            } 
            cout << dist[i][j][0] << " ";
        }br;
    }
    cout << "----" << endl;
    rep(i, n){
        rep(j, n){
            if(dist[i][j][1] == INF){
                cout << -1 << " "; continue;
            } 
            cout << dist[i][j][1] << " ";
        }br;
    }
    cout << "----" << endl;
    rep(i, n){
        rep(j, n){
            if(dist[i][j][2] == INF){
                cout << -1 << " "; continue;
            } 
            cout << dist[i][j][2] << " ";
        }br;
    }
    cout << "----" << endl;
    rep(i, n){
        rep(j, n){
            if(dist[i][j][3] == INF){
                cout << -1 << " "; continue;
            } 
            cout << dist[i][j][3] << " ";
        }br;
    }
    */
    
    
    /*
    while(!que.empty()){
        P now = que.front();
        que.pop();
        ll nowy = now.first, nowx = now.second;

        rep(i, 4){
            ll cnt = 1;
            while(true){
                // ll nexty = nowy + cnt * dy[i];
                // ll nextx = nowx + cnt * dx[i];

                // //場外ならbreak
                // if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n){
                //     break;
                // }
                // //壁ならbreak
                // if(vec[nexty][nextx] == '#'){
                //     break;
                // }

                // //訪問済みならbreak
                // if(dist[nexty][nextx] != INF){
                //     cnt += 1;
                //     continue;
                // }

                // dist[nexty][nextx] = dist[nowy][nowx] + 1;
                // que.push({nexty, nextx});

                // cnt += 1;
            }
        }
    }
    */

    // rep(i, n){
    //     rep(j, n){
    //         if(dist[i][j] == INF){
    //             cout << -1 << " ";
    //         }else{
    //             cout << dist[i][j] << " ";
    //         }
    //     }br;
    // }

    // if(dist[by][bx] == INF){
    //     cout << -1 << endl;
    // }else{
    //     cout << dist[by][bx] << endl;
    // }



}