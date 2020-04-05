#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
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
    ll t;
    cin >> t;
    rep(i,t){
        ll a, b;
        cin >> a >> b;
        ll tmp;
        if(a == b){
            cout << 0 << endl;
        }else if(a > b){
            tmp = a - b;
            if(tmp % 2 == 1){
                cout << 2 << endl;
            }else{
                cout << 1 << endl;
            }
        }else if(b > a){
            tmp = b - a;
            if(tmp % 2 == 1){
                cout << 1 << endl;
            }else{
                cout << 2 << endl;
            }
        }
    }
    

}