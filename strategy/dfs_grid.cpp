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

        if(seen[new_x][new_y] == true){
            continue;
        }

        ////////////
        //今見てるノードに対する処理
        ////////////

        dfs(new_x, new_y);
    }

}

int main() {


    ll x, y;

    x = 0;
    y = 0;

    //x,yマスからスタート
    //dfs(x,y);
        
    
}
