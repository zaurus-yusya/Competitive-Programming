#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
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
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(6);
    ll T;
    cin >> T;
    rep(t, T){
        ll r, c;
        cin >> r >> c;
        vector<vector<ld>> vec(r, vector<ld>(c));
        vector<ld> yoko_sum(r);
        vector<ld> tate_sum(c);
        vector<ld> yoko_num(r, r);
        vector<ld> tate_num(c, c);
        for(long long i = 0; i < r; i++){
            for(long long j = 0; j < c; j++){
                cin >> vec[i][j];
                yoko_sum[i] += vec[i][j];
                tate_sum[j] += vec[i][j];
            }
        }

        /*
        rep(i,r){
            cout << yoko_sum[i] << endl;
        }

        rep(i,c){
            cout << tate_sum[i] << endl;
        }

        rep(i,r){
            cout << yoko_num[i] << endl;
        }

        rep(i,c){
            cout << tate_num[i] << endl;
        }
        */

        /*
       rep(i,r){
           rep(j,c){
               cout << yoko_num[i] + tate_num[j] - 1<< " ";
           }
           cout << endl;
       }
        

        cout << endl;
        rep(i,r){
            rep(j,c){
                cout << yoko_sum[i] + tate_sum[j] - vec[i][j]<< " ";
            }
            cout << endl;
        }
        */

        ll ans = 0;
        vector<vector<ld>> res(r, vector<ld>(c));
        while(true){
            
            bool flag = false;
            rep(i,r){
                rep(j,c){
                    if(res[i][j] == 0){
                        long double tmp = (double)yoko_sum[i] + tate_sum[j] - vec[i][j];
                        long double tmp2 = (double)yoko_num[i] + tate_num[j] - 1;
                        long double me = tmp / tmp2;
                        //cout << tmp / tmp2 << " ";
                        ans += vec[i][j];
                        if(vec[i][j] < me){
                            res[i][j] = 1;
                            flag = true;
                        }
                    }
                }
            }

            if(flag == true){
                rep(i,r){
                    rep(j,c){
                        if(res[i][j] == 1){
                            res[i][j] == 2;
                            yoko_num[i]--;
                            tate_num[j]--;
                            yoko_sum[i]-= vec[i][j];
                            tate_sum[j]-= vec[i][j];
                        }
                    }
                }
            }else{
                break;
            }
            
        }


        
        cout << "Case #" << t+1 <<": ";
        cout << ans << endl;
        


    }

}