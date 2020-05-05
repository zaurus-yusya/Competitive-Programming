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
    ll n;
    cin >> n;
    vector<vector<string>> vec(n, vector<string>(2*n-1));
    rep(i,n){
        string s;
        cin >> s;
        rep(j,2*n-1){
            vec[i][j] = s[j];
        }
    }

    for(ll i = n-2; i >= 0; i--){
        for(ll j = 0; j < 2*n-1; j++){
            if(vec[i][j] == ".") continue;
            if(vec[i+1][j-1] == "X" || vec[i+1][j] == "X" || vec[i+1][j+1] == "X"){
                vec[i][j] = "X";
            }
        }
    }

    rep(i,n){
        rep(j,2*n-1){
            cout << vec[i][j];
        }
        cout << endl;
    }

}