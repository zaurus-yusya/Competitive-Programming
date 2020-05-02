#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
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
        ll X, Y;
        string s;
        cin >> X >> Y >> s;
        ll time = (ll)s.size();
        ll kyori = X + Y;

        ll ans = -1;
        rep(i,s.size()){
            if(s[i] == 'S'){
                if(Y <= 0){
                    kyori += 1;
                }else{
                    kyori -= 1;
                }
                Y -= 1;
                
            }
            if(s[i] == 'W'){
                if(X <= 0){
                    kyori += 1;
                }else{
                    kyori -= 1;
                }
                X -=1;
            }
            if(s[i] == 'N'){
                if(Y >= 0){
                    kyori += 1;
                }else{
                    kyori -= 1;
                }
                Y += 1;
            }
            if(s[i] == 'E'){
                if(X >= 0){
                    kyori += 1;
                }else{
                    kyori -= 1;
                }
                X += 1;
            }

            if(i+1 >= kyori){
                ans = i+1;
                break;
            }

        }

        if(ans == -1){
            cout << "Case #" << t+1 << ": " << "IMPOSSIBLE" << endl;
        }else{
            cout << "Case #" << t+1 << ": " << ans << endl;
        }
        

    }

}