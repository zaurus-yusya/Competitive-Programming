#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
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

vector<ll> dy = {-1,1,0,0};
vector<ll> dx = {0,0,-1,1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    vector<vector<ll>> vec(4, vector<ll>(4));
    rep(i, 4){
        rep(j, 4){
            cin >> vec[i][j];
        }
    }

    map<ll, P> mp;
    ll cnt = 0;
    rep(i, 4){
        rep(j, 4){
            mp[cnt] = {i, j};
            cnt++;
        }
    }
    /*
    rep(i, 16){
        cout << i << " " << mp[i].first << " " << mp[i].second << endl;
    }
    */

    ll ans = 0;
    
    for(ll bit = 0; bit < (1<<16); bit++){
        
        vector<vector<ll>> masu(4, vector<ll>(4));
        //囲む予定のマス
        rep(i, 16){
            ll y = mp[i].first, x = mp[i].second;
            if((bit >> i) & 1){
                masu[y][x] = 1;
            }else{
                masu[y][x] = 0;
            }
        }

        //家囲めてるか
        bool f = true;
        rep(i, 4){
            rep(j, 4){
                if(vec[i][j] == 1 && masu[i][j] == 0){
                    f = false;
                }
            }
        }
        if(!f){
            continue;
        }
        ///

        //訪問管理
        vector<vector<ll>> visited(4, vector<ll>(4, 0));

        ll cnt2 = 0; //1回のbfsで全部回る
        rep(i, 4){
            rep(j, 4){
                //訪問済みならcontinue
                if(visited[i][j] == 1) continue;
                //囲わないマスならcontinue
                if(masu[i][j] == 0) continue;

                //囲う予定のマスなのでBFS開始
                queue< pair<ll,ll> > que;
                visited[i][j] = 1;
                que.push({i, j});

                while(!que.empty()){
                    pair<ll,ll> now = que.front();
                    ll now_y = now.first, now_x = now.second;
                    que.pop();
                    rep(k, 4){
                        ll next_y = now_y + dy[k]; ll next_x = now_x + dx[k];
                        //場外ならcontinue
                        if(next_y < 0 || next_y >= 4 || next_x < 0 || next_x >= 4) continue;
                        //既に訪問済みならcontinue
                        if(visited[next_y][next_x] == 1) continue;
                        //囲む予定のマスじゃないならcontinue
                        if(masu[next_y][next_x] == 0) continue;
                        
                        visited[next_y][next_x] = 1;
                        que.push({next_y, next_x});
                    }
                }
                cnt2++;
            }
        }
        
        if(cnt2 == 1){
            bool f2 = true;
            rep(i, 4){
                rep(j, 4){
                    if(visited[i][j] == 0 && vec[i][j] == 1) f2 = false;
                }
            }
            if(f2) ans++;
            //cout << ans<< endl;
            /*
            if(ans < 5){
                rep(i, 4){
                    rep(j, 4){
                        cout << visited[i][j] << ' ';
                    }br;
                }
                cout << "----" << '\n';
            }
            */
        }

    }

    cout << ans << endl;



}