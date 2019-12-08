#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

//マス目の分だけfalseで初期化。分からないならmainでresize
bool seen[100][100];

vector<int> next_y = {-1,1,0,0};
vector<int> next_x = {0,0,-1,1};

int h, w;
vector<vector<string>> vec(h, vector<string>(w));

void dfs(ll x, ll y)
{
    seen[x][y] = true;

    rep(i,4){
        ll new_x = x + next_x.at(i);
        ll new_y = y + next_y.at(i);

        //場外なら終了
        if(new_x < 0 || new_x >= 10 || new_y < 0 || new_y >= 10){
            continue;
        }

        if(seen[new_y][new_x] == true){
            continue;
        }

        ////////////
        //今見てるノードに対する処理
        ////////////

        dfs(new_y, new_x);
    }

}

int main() {

    // h: 縦 , w: 横
    cin >> h >> w;

    vec.resize(h, vector<string>(w));

    int sh = 0, sw = 0;
    int gh = 0, gw = 0;

    //グリッドの読み込み(sをスタート,gをゴールとしている)
    string s;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec[i][j] = s[j];
            if(s[j] == 's'){
                sh = i;
                sw = j;
            }
            if(s[j] == 'g'){
                gh = i;
                gw = j;        
            }
        }
    }


    ll x, y;

    x = 0;
    y = 0;

    //x,yマスからスタート
    //dfs(y,x);
        
    
}
