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

vector<ll> topo_sort(vector<vector<ll>> &g){
    vector<ll> res;
    ll n = g.size();
    vector<ll> ind(n);
    rep(i, n){
        for(auto next: g[i]){
            ind[next]++;
        }
    }
    queue<ll> que;
    rep(i, n){
        if(ind[i] == 0) que.push(i);
    }
    while(!que.empty()){
        ll now = que.front();
        res.push_back(now);
        que.pop();
        for(auto next: g[now]){
            ind[next]--;
            if(ind[next] == 0){
                que.push(next);
            }
        }
    }
    return res;
    //res.size()がnだったらトポジカルソートできた(DAG)、nじゃなかったらDAGじゃない(閉路あり)
}

vector<ll> dy = {1, -1, 0, 0};
vector<ll> dx = {0, 0, 1, -1};
vector<ll> dy8 = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<ll> dx8 = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll r, c; cin >> r >> c;
        ll tree_num = 0;
        vector<vector<char>> vec(r, vector<char>(c));
        rep(i, r){
            rep(j, c){
                cin >> vec[i][j];
                if(vec[i][j] == '^'){
                    tree_num++;
                }else if(vec[i][j] == '.'){
                    vec[i][j] = '^';
                }
            }
        }

        if(tree_num == 0){
            cout << "Case #" << T+1 << ": " << "Possible" << '\n';
            rep(i, r){
                rep(j, c){
                    if(vec[i][j] == '^'){
                        cout << '.';
                    }else{
                        cout << '#';
                    }
                }br;
            }
            continue;
        }

        vector<vector<ll>> ind(r, vector<ll>(c));
        queue<pair<ll, ll>> que;

        rep(i, r){
            rep(j, c){
                if(vec[i][j] == '#') continue;

                ll cnt = 0;
                rep(k, 4){
                    ll nexty = i + dy[k];
                    ll nextx = j + dx[k];
                    if(nexty < 0 || nexty >= r || nextx < 0 || nextx >= c){
                        continue;
                    }
                    if(vec[nexty][nextx] == '^'){
                        cnt++;
                    }
                }
                ind[i][j] = cnt;
                if(cnt == 1){
                    que.push({i, j});
                }
            }
        }

        while(!que.empty()){
            pair<ll, ll> now = que.front();
            que.pop();
            ll nowy = now.first;
            ll nowx = now.second;

            vec[nowy][nowx] = '.';

            rep(k, 4){
                ll nexty = nowy + dy[k];
                ll nextx = nowx + dx[k];
                if(nexty < 0 || nexty >= r || nextx < 0 || nextx >= c){
                    continue;
                }
                if(vec[nexty][nextx] == '^'){
                    ind[nexty][nextx]--;
                    if(ind[nexty][nextx] == 1){
                        que.push({nexty, nextx});
                    }
                }
            }
        }

        bool f = false;
        rep(i, r){
            rep(j, c){
                if(vec[i][j] == '^'){
                    f = true; break;
                }
            }
            if(f) break;
        }

        if(f){
            cout << "Case #" << T+1 << ": " << "Possible" << '\n';
            rep(i, r){
                rep(j, c){
                    cout << vec[i][j];
                }br;
            }
        }else{
            cout << "Case #" << T+1 << ": " << "Impossible" << '\n';
        }




        /*
        if((r == 1 || c == 1) && tree_num != 0){
            cout << "Case #" << T+1 << ": " << "Impossible" << '\n';
            continue;
        }

        cout << "Case #" << T+1 << ": " << "Possible" << '\n';
        rep(i, r){
            rep(j, c){
                cout << '^';
            }br;
        }
        */


    }

}