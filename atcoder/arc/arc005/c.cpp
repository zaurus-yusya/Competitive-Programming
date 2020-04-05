#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する

vector<int> next_y = {-1,1,0,0};
vector<int> next_x = {0,0,-1,1};

//h : 行 w : 列
ll h, w;
vector<vector<string>> vec(h, vector<string>(w));


int main() {
    cin >> h >> w;
    vec.resize(h, vector<string>(w));

    //グリッドの読み込み
    string s;
    //スタート位置とゴール位置を特定
    ll sx, sy;
    ll gx, gy;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec.at(i).at(j) = s[j];
            if(vec.at(i).at(j) == "s"){
                sx = j;
                sy = i;
            }
            if(vec.at(i).at(j) == "g"){
                gx = j;
                gy = i;
            }
        }
    }

    //BFSの準備
    //全マスを未訪問(-1)に初期化
    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    //queはpairで作る
    deque< pair<ll,ll> > que;

    //スタートマスからスタートとする
    dist[sy][sx] = 0;
    que.push_back(make_pair(sy,sx));

    //ここからBFS開始
    while(!que.empty()){
        pair<ll,ll> now_pos = que.front();
        ll now_pos_y = now_pos.first;
        ll now_pos_x = now_pos.second;
        que.pop_front();

        //上下左右いけるか
        rep(i,4){
            //次に行くマス
            ll next_pos_y = now_pos_y + next_y.at(i);
            ll next_pos_x = now_pos_x + next_x.at(i);
            
            //場外なら何もしない
            if(next_pos_x < 0 || next_pos_x >= w || next_pos_y < 0 || next_pos_y >= h){
                continue;
            }
            
            //既に訪問済みなら何もしない
            if(dist[next_pos_y][next_pos_x] != -1){
                continue;
            }


            //now_posから訪問できるノードをqueに追加　壁なら+1
            if(vec[next_pos_y][next_pos_x] == "#"){
                dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
                que.push_back(make_pair(next_pos_y,next_pos_x));
            }else{
                dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x];
                que.push_front(make_pair(next_pos_y,next_pos_x));
            }
            
            

        }
    }


    //gのマスが2以下だったらyes
    if(dist[gy][gx] <= 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
}
