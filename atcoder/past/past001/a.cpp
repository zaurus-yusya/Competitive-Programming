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
    string s;
    cin >> s;
    ll ans = 0;
    if(s[0] >= '0' && s[0] <= '9'){
        ans += ((ll)s[0] - 48) * 100 * 2;
    }else{
        cout << "error" << endl;
        return 0;
    }

    if(s[1] >= '0' && s[1] <= '9'){
        ans += ((ll)s[1] - 48) * 10 * 2;
    }else{
        cout << "error" << endl;
        return 0;
    }

    if(s[2] >= '0' && s[2] <= '9'){
        ans += ((ll)s[2] - 48) * 1 * 2;
    }else{
        cout << "error" << endl;
        return 0;
    }

    cout << ans << endl;

}