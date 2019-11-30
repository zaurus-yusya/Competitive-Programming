#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

bool seen[10][10];
vector<vector<char>> vec(10, vector<char>(10));
vector<int> next_y = {-1,1,0,0};
vector<int> next_x = {0,0,-1,1};

void dfs(ll x, ll y)
{
    seen[x][y] = true;

    rep(i,4){
        ll new_x = x + next_x.at(i);
        ll new_y = y + next_y.at(i);

        if(new_x < 0 || new_x >= 10 || new_y < 0 || new_y >= 10){
            continue;
        }

        if(vec.at(new_x).at(new_y) == 'x' || seen[new_x][new_y] == true){
            continue;
        }

        dfs(new_x, new_y);
    }

}

int main() {
    string s;

    for(ll i=0;i<10;i++){
        cin >> s;
        for(ll j=0;j<10;j++){
            vec.at(i).at(j) = s.at(j);
            if(vec.at(i).at(j) == 'o');
        }
    }

    string flag;
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            //seenを初期化
            rep(x,10){
                rep(y,10){
                    seen[x][y] = false;
                }
            }

            dfs(i,j);
        
            flag = "YES";
            rep(x,10){
                rep(y,10){
                    if(vec.at(x).at(y) == 'o'){
                        if(seen[x][y] == false){
                            flag = "NO";
                        }
                    }
                }
            }
            if(flag == "YES"){
                cout << "YES" << endl;
                return 0;
            }

        }
    }

    cout << "NO" << endl;
    
}
