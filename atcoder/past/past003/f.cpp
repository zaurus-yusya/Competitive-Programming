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
    ll n;
    cin >> n;
    vector<vector<string>> vec(n, vector<string>(n));
    rep(i,n){
        string s; cin >> s;
        rep(j,n){
            vec[i][j] = s[j];
        }  
    }

    vector<string> ans;

    for(ll i = 0; i < n/2; i++){
        map<string, ll> mp1;
        map<string, ll> mp2;
        for(ll j = 0; j < n; j++){
            mp1[vec[i][j]]++;
            mp2[vec[n-1-i][j]]++;
        }
        
        ll flag = 0;
        for(auto i: mp1){
            if(mp2.count(i.first) >= 1){
                ans.push_back(i.first);
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i, n/2){
        cout << ans[i];
    }
    if(n % 2 == 1){
        cout << vec[n/2][0];
    }
    rep(i, n/2){
        cout << ans[(n/2) - 1 - i];
    }
    br;


}