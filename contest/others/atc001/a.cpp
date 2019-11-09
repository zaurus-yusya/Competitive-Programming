#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;

//途中

bool seen[600][600];

void dfs(const &s, int h, int w)
{

}


int main() {
    int h, w;
    cin >> h >> w;
    //vector<vector<string>> vec[h][w];
    vector<vector<string>> vec(h, vector<string>(w));
    vector<vector<string>> vec2(h, vector<string>(w));
    int up = 0, down = 0, left = 0, right = 0;
    int sh = 0, sw = 0;
    int gh = 0, gw = 0;

    string s;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec[i][j] = s[j];
            if(s[j] == "s"){
                sh = i;
                sw = w;
            }
            if(s[j] == "g"){
                gh = i;
                gw = w;        
            }
        }
    }

    dfs(s,sh,sw);

    //のちにコメントアウト
    rep(i,h){
        rep(j,w){
            cout << vec[i][j];
        }
        cout << "" << endl;
    }

/*
    rep(i,h){
        rep(j,w){
            //up判定
            if(i != 0){
                if(vec[i-1][j] != "#"){
                    up = 1;
                    vec2[i][j].pb(1);
                }        
            }else{
                up = 0;
                vec2[i][j].pb(0);
            }
            //down判定
            if(i != h-1){
                if(vec[i+1][j] != "#"){
                    down = 1;
                    vec2[i][j].pb(1);
                }
            }else{
                down = 0;
                vec2[i][j].pb(0);
            }
            //left判定
            if(j != 0){
                if(vec[i][j-1] != "#"){
                    left = 1;
                    vec2[i][j].pb(1);
                }
            }else{
                left = 0;
                vec2[i][j].pb(0);
            }
            //right判定
            if(j != w-1){
                if(vec[i][j+1] != "#"){
                    right = 1;
                    vec2[i][j].pb(1);
                }
                right = 0;
                vec2[i][j].pb(0);
            }
        }
    }
*/


}
