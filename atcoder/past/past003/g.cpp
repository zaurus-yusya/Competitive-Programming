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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, x, y;
    cin >> n >> x >> y;
    x += 201; y += 201;

    vector<vector<ll>> block(404, vector<ll>(404));


    for(long long i = 0; i < n; i ++){
        ll tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        tmp_x += 201; tmp_y += 201;
        block[tmp_y][tmp_x] = 1;
    }

    vector<ll> move_y = {1, 1,  1, 0,  0, -1};
    vector<ll> move_x = {1, 0, -1, 1, -1,  0};

    vector<vector<ll>> dist(404, vector<ll>(404, -1));
    queue< pair<ll,ll> > que;
    //(201,201)マスからスタートとする
    dist[201][201] = 0;
    que.push(make_pair(201,201));

    while(!que.empty()){
        pair<ll,ll> now_pos = que.front();
        ll now_pos_y = now_pos.first;
        ll now_pos_x = now_pos.second;
        que.pop();

        //金いけるか
        rep(i,6){
            //次に行くマス
            ll next_pos_y = now_pos_y + move_y.at(i);
            ll next_pos_x = now_pos_x + move_x.at(i);

            //場外なら何もしない
            if(next_pos_x < 0 || next_pos_x >= 404 || next_pos_y < 0 || next_pos_y >= 404){
                continue;
            }
            //壁なら何もしない
            if(block[next_pos_y][next_pos_x] == 1){
                continue;
            }
            //既に訪問済みなら短くなるなら更新
            if(dist[next_pos_y][next_pos_x] != -1){
                if(dist[next_pos_y][next_pos_x] > dist[now_pos_y][now_pos_x] + 1){
                    dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
                    que.push(make_pair(next_pos_y,next_pos_x));
                }
                continue;
            }

            //now_posから訪問できるノードをqueに追加
            dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
            que.push(make_pair(next_pos_y,next_pos_x));
        }
    }

    /*
    rep(i, 10){
        rep(j, 10){
            cout << dist[201-5+i][201-5+j] << " ";
        }
        br;
    }
    */

    cout << dist[y][x] << endl;


    
    



}