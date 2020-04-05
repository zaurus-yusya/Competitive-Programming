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

ll r, c;
vector<vector<string>> vec(r, vector<string>(c));

int main() {
    cin >> r >> c;

    vec.resize(r, vector<string>(c));

    ll sx, sy;
    ll gx, gy;
    cin >> sy >> sx;
    cin >> gy >> gx;

    sx--; sy--;
    gx--; gy--;

    string s;
    rep(i,r){
        cin >> s;
        rep(j,c){
            vec.at(i).at(j) = s[j];
        }
    }

    //全マスを未訪問(-1)に初期化
    vector<vector<ll>> dist(r, vector<ll>(c, -1));
    //queはpairで作る
    queue< pair<ll,ll> > que;

    dist[sy][sx] = 0;
    que.push(make_pair(sy,sx));

    /////////////////////////////////
    //ここからBFS開始
    while(!que.empty()){
        pair<ll,ll> now_pos = que.front();
        ll now_pos_y = now_pos.first;
        ll now_pos_x = now_pos.second;
        que.pop();

        //上下左右いけるか
        rep(i,4){
            //次に行くマス
            ll next_pos_y = now_pos_y + next_y.at(i);
            ll next_pos_x = now_pos_x + next_x.at(i);
            
            //場外なら何もしない
            if(next_pos_x < 0 || next_pos_x >= c || next_pos_y < 0 || next_pos_y >= r){
                continue;
            }
            
            //既に訪問済みなら何もしない
            if(dist[next_pos_y][next_pos_x] != -1){
                continue;
            }

            //壁なら何もしない
            if(vec[next_pos_y][next_pos_x] == "#"){
                continue;
            }
            
            dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
            que.push(make_pair(next_pos_y,next_pos_x));
            

        }
        
    }

    /*
    rep(i,r){
        rep(j,c){
            if(i == sy && j == sx){
                cout << "s";
            }else if(i == gy && j == gx){
                cout << "g";
            }else{
                cout << vec[i][j];
            }
            
        }
        cout << "" << endl;
    }

    rep(i,r){
        rep(j,c){
            cout << dist[i][j];
        }
        cout << "" << endl;
    }
    */

    cout << dist[gy][gx] << endl;


}
