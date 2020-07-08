#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w, k; cin >> h >> w >> k;

    vector<vector<ll>> vec(h, vector<ll>(w));
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            vec[i][j] = s[j] - 48;
        }
    }

    /*
    rep(i, h){
        rep(j, w){
            cout << vec[i][j] << " ";
        }
        br;
    }
    */

    ll ans = 0;
    for(ll x = 1; x < h; x++){
        rep(y, w){
            vector<vector<ll>> cell(h, vector<ll>(w));
            cell = vec;
            //消す
            cell[x][y] = 0;
            //降ろす
            rep(j, w){
                for(ll i = h-1; i >= 0; i--){
                    for(ll k = i-1; k >= 0; k--){
                        if(cell[i][j] == 0){
                            swap(cell[i][j], cell[k][j]);
                        }
                    }
                }
            }
            //初期処理終了
            //////////////

            ll score = 0;
            ll pre = 1;
            while(true){
                ll tmp = score;
                rep(i, h){
                    ll num = 0; ll num_s = -1;
                    rep(j, w){
                        if(j == 0){
                            num = cell[i][j]; num_s = 0; continue;
                        }

                        if(cell[i][j] == num){
                            if(j == w-1){
                                if(j - num_s >= k-1){
                                    for(ll k = num_s; k <= j; k++){
                                        score += pre * num; cell[i][k] = 0;
                                    }
                                }
                            }
                        }else{
                            if(j - 1 - num_s >= k-1){
                                for(ll k = num_s; k < j; k++){
                                    score += pre * num; cell[i][k] = 0;
                                }
                            }
                            num = cell[i][j]; num_s = j;
                        }
                    }
                }

                //降ろす
                rep(j, w){
                    for(ll i = h-1; i >= 0; i--){
                        for(ll k = i-1; k >= 0; k--){
                            if(cell[i][j] == 0){
                                swap(cell[i][j], cell[k][j]);
                            }
                        }
                    }
                }

                if(tmp == score){
                    break;
                }

                pre *= 2;
            }
            /*
            if(ans < score){
                cout << x << " " << y << endl;
                rep(i, h){
                    rep(j, w){
                        cout << cell[i][j] << " ";
                    }
                    br;
                }
            }
            */
            ans = max(ans, score);

        }
    }

    cout << ans << endl;

}