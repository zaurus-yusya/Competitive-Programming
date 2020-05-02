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
    ll T, A, B;
    cin >> T >> A >> B;
    rep(t,T){

        //test set 1
        if(A == 1e9-5){
            string s;
            bool flag = false;
            for(ll i = -5; i <= 5; i++){
                for(ll j = -5; j <= 5; j++){
                    cout << i << " " << j << endl;
                    cout.flush();
                    cin >> s;
                    if(s == "CENTER"){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
        }

        //test set 2
        if(A == 1e9-50){
            exit(0);

        }

        //test set 3
        if(A == 1e9/2){
            exit(0);

        }
        

    }

}