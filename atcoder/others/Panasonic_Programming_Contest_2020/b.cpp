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
    ll h, w;
    cin >> h >> w;

    if(h == 1 || w == 1){
        cout << 1 << endl;
        return 0;
    }

    if(w % 2 == 0){
        cout << w / 2 * h << endl;
    }else{
        if(h % 2 == 0){
            cout << h / 2 * w << endl; 
        }else{
            cout << ((h / 2) * w ) + (w/2)+1 << endl;
        }
    }

    /*
    if(h == w){
        cout << h << endl;
    }else if(h % 2 != 0 && ){
        cout << (h*w / 2) << endl;
    }else{
        cout << ((h / 2) * (w / 2)) + 1 << endl;
    }
    ll a = 1000000000 * 1000000000;
    cout << a << endl;
    */
}