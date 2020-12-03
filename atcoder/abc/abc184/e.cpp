#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

vector<ll> dy = {1, -1, 0, 0};
vector<ll> dx = {0, 0, 1, -1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    vector<vector<char>> vec(h, vector<char>(w));
    pair<ll, ll> start, goal;
    vector<vector<pair<ll, ll>>> tele(26);
    vector<bool> teleflag(26, true);
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            vec[i][j] = s[j];
            if(vec[i][j] == 'S') start = {i, j};
            if(vec[i][j] == 'G') goal = {i, j};
            if(vec[i][j] >= 'a' && vec[i][j] <= 'z'){
                tele[(int)vec[i][j] - 97].push_back({i, j});
            }
        }
    }

    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    queue<pair<ll, ll>> que;
    que.push(start); dist[start.first][start.second] = 0;

    while(!que.empty()){
        ll now_y = que.front().first, now_x = que.front().second;
        que.pop();
        //アルファベットなら更新する
        if(vec[now_y][now_x] >= 'a' && vec[now_y][now_x] <= 'z'){
            if(teleflag[(int)vec[now_y][now_x]-97]){
                teleflag[(int)vec[now_y][now_x]-97] = false;
                for(ll i = 0; i < tele[(int)vec[now_y][now_x]-97].size(); i++){
                    ll x = (int)vec[now_y][now_x]-97;
                    if(dist[tele[x][i].first][tele[x][i].second] == -1){
                        dist[tele[x][i].first][tele[x][i].second] = dist[now_y][now_x] + 1;
                        que.push({tele[x][i].first, tele[x][i].second});
                    }
                    if(dist[tele[x][i].first][tele[x][i].second] > dist[now_y][now_x] + 1){
                        dist[tele[x][i].first][tele[x][i].second] = dist[now_y][now_x] + 1;
                        que.push({tele[x][i].first, tele[x][i].second});
                    }
                }
            }
        }

        for(ll i = 0; i < 4; i++){
            ll next_y = now_y + dy[i], next_x = now_x + dx[i];
            //場外ならcontinue
            if(next_y < 0 || next_y >= h) continue;
            if(next_x < 0 || next_x >= w) continue;
            //壁ならcontinue
            if(vec[next_y][next_x] == '#') continue;
            //訪問済みならcontinue
            if(dist[next_y][next_x] >= 0) continue;
            //.で更新できるならqueに入れる

            que.push({next_y, next_x});
            dist[next_y][next_x] = dist[now_y][now_x] + 1;
            
        }
    }

    //vecvecdbg(dist);

    cout << dist[goal.first][goal.second] << endl;



}