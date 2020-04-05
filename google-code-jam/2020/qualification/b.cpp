#include <bits/stdc++.h>
typedef long long ll;
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
    std::cout << std::fixed << std::setprecision(15);
    ll T;
    cin >> T;

    rep(t,T){
        string s;
        cin >> s;

        cout << "Case #" << t+1 << ": ";

        if(s.size() == 1){
            ll now = s[0] - '0';
            rep(j, now){
                cout << "(" ;
            }
            cout << now;
            rep(j, now){
                cout << ")" ;
            }
        }else{
            rep(i,s.size()){
                if(i == 0){
                    ll now = s[i] - '0';
                    ll next = s[i+1] - '0';

                    rep(j, now){
                        cout << "(" ;
                    }

                    cout << now ;

                    rep(j, now - next){
                        cout << ")" ;
                    }
                }else if(i == s.size() - 1){
                    ll before = s[i-1] - '0';
                    ll now = s[i] - '0';

                    rep(j, now - before){
                        cout << "(" ;
                    }

                    cout << now;

                    rep(j, now){
                        cout << ")" ;
                    }
                }else{
                    ll before = s[i-1] - '0';
                    ll now = s[i] - '0';
                    ll next = s[i+1] - '0';

                    rep(j, now - before){
                        cout << "(" ;
                    }

                    cout << now;

                    rep(j, now - next){
                        cout << ")" ;
                    }
                }
            }
        }
        cout << endl;
    }

}