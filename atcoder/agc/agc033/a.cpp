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

    //全マスを未訪問(-1)に初期化
    vector<vector<ll>> dist(h, vector<ll>(w, -1));

    //グリッドの読み込み
    string s;
    queue< pair<ll,ll> > black;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec.at(i).at(j) = s[j];
            if(vec.at(i).at(j) == "#"){
                black.push(make_pair(i,j));
                dist[i][j] = 0;
            }
        }
    }

    while(!black.empty()){

        pair<ll,ll> black_pos = black.front();
        ll black_y = black_pos.first;
        ll black_x = black_pos.second;
        black.pop();

        rep(i,4){
            //次に行くマス
            ll next_pos_y = black_y + next_y.at(i);
            ll next_pos_x = black_x + next_x.at(i);
            
            //場外なら何もしない
            if(next_pos_x < 0 || next_pos_x >= w || next_pos_y < 0 || next_pos_y >= h){
                continue;
            }
            
            //既に訪問済みなら小さい方にする
            if(dist[next_pos_y][next_pos_x] != -1){
                continue;
            }

            //壁なら何もしない
            if(vec[next_pos_y][next_pos_x] == "#"){
                continue;
            }

            //訪問できるノードの距離を記録し、queに格納
            dist[next_pos_y][next_pos_x] = dist[black_y][black_x] + 1;
            black.push(make_pair(next_pos_y,next_pos_x));
            
        }
        
    }

    ll ans = 0;

    rep(i,h){
        rep(j,w){
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << endl;

}
