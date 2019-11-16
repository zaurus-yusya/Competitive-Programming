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
int h, w;
vector<vector<string>> vec(h, vector<string>(w));

vector<int> next_y = {-1,1,0,0};
vector<int> next_x = {0,0,-1,1};


void dfs(int height, int width)
{
    seen[height][width] = true;

    rep(i,4){
        int next_height = height + next_y.at(i);
        int next_width = width + next_x.at(i);

        if(next_height < 0 || next_height >= h || next_width < 0 || next_width >= w){
            continue;
        }
        if(seen[next_height][next_width] == true){
            continue;
        }
        if(vec[next_height][next_width] != "#"){
            dfs(next_height, next_width);
        }
    }
}



int main() {
    cin >> h >> w;

    vec.resize(h, vector<string>(w));

    int sh = 0, sw = 0;
    int gh = 0, gw = 0;

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


    dfs(sh,sw);


    if(seen[gh][gw]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



}
