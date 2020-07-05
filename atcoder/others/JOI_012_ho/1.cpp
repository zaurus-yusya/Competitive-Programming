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
    ll n; cin >> n;
    vector<ll> stone;
    ll count = 0;
    ll before;
    rep(i, n){
        ll num; cin >> num;
        if(i == 0){
            before = num;
            count++;
            continue;
        }

        if(before != num){
            count++;
            if(i == n - 1){
                stone.push_back(count);
            }
        }else{
            stone.push_back(count);
            count = 1;
            if(i == n - 1){
                stone.push_back(count);
            }
        }

        before = num;
    }

    /*
    rep(i, stone.size()){
        cout << stone[i] << " ";
    }
    br;
    */

    if(stone.size() <= 3){
        cout << n << endl;
    }else{
        ll ans = 0;
        for(ll i = 0; i < stone.size() - 2; i++){
            ans = max(ans, stone[i] + stone[i+1] + stone[i+2]);
        }
        cout << ans << endl;
    }
}