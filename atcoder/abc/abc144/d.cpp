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
const long double PI = (acos(-1));

int main() {
    std::cout << std::fixed << std::setprecision(15);
    double a, b, x;
    cin >> a >> b >> x;
    double theta;

    if(a * a * b / 2 == x){
        cout << 45 << endl;
        return 0;
    }

    if(x < (a * a * b / 2)){
        theta = atan(2 * x / a / b / b);
        theta = theta * 180 / PI;
        cout << 90 - theta << "\n";
    }else{
        theta = atan((2 * b - (x / a * 2 / a )) / a);
        theta = theta * 180 / PI;
        cout << theta << "\n";
    }


}
