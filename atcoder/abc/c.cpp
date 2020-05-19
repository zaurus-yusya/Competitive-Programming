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
ld pi = 3.141592653589793;;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ld a, b, h ,m;
    cin >> a >> b >> h >> m;

    //時
    ld a_x = a * cos((pi*h / 6) + (pi*m / 360));
    ld a_y = a * sin((pi*h / 6) + (pi*m / 360));

    //分
    ld b_x = b * cos(pi*m/30);
    ld b_y = b * sin(pi*m/30);
    /*
    cout << a_x << endl;
    cout << a_y << endl;
    cout << b_x << endl;
    cout << b_y << endl;
    */
    ld ans = 0;

    ld tmp = (a_x - b_x) * (a_x - b_x);
    ld tmp2 = (a_y - b_y) * (a_y - b_y);
    /*
    cout << tmp << endl;
    cout << tmp2 << endl;
    */
    cout << sqrt(tmp + tmp2) << endl;
 



}