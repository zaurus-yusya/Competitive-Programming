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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s, t;
    cin >> s >> t;
    vector<string> ans = {"same", "case-insensitive", "different"};
    ll res = 0;
    rep(i,3){
        if(s[i] == t[i]){
            continue;
        }else if(abs(s[i] - t[i]) == 32){
            res = 1;
        }else{
            res = 2;
            break;
        }
    }

    cout << ans[res] << endl;

}