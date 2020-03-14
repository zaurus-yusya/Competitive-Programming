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
    long double a, b, c;
    cin >> a >> b >> c;

    if(a + b + 2 * sqrtl((long double)a * (long double) b) < c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    /*
    long double tmp_a = sqrtl((long double)a);
    long double tmp_b = sqrtl((long double)b);
    long double tmp_c = sqrtl((long double)c);
    */

    /*
    if(sqrtl((long double)c) - sqrtl((long double)a) - sqrtl((long double)b) > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    */

    /*
    if(a + b + (2 * sqrt(a*b)) < c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    */

    
    /*
    double tmp_a = sqrt(a);
    double tmp_b = sqrt(b);
    double tmp_c = sqrt(c);
    
    cout << tmp_a << endl;
    cout << tmp_b << endl;
    cout << tmp_c << endl;
    
    if(tmp_a + tmp_b < tmp_c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    double x = 1000000000 * 1000000000;
    cout << x << endl;
    */
    

}