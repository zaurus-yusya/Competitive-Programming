#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(4);
    string a, b, c; cin >> a >> b >> c;
    bool flag = true;
    rep(i, b.size()){
        if(b[i] == '.') flag = false;
    }
    ld x = stod(a);
    ld y = stod(b);
    ld r = stod(c);

    //cout << x << " " << y << " " << r << endl;
    

    //ld x, y, r; cin >> x >> y >> r;
    if(x < 0) x = x * (-1);
    if(y < 0) y = y * (-1);

    ld migi = x + r;
    ll start = floor(migi);

    ld hidari = x - r;
    ll end;
    if(hidari < 0){
        hidari *= -1;
        end = floor(hidari) * (-1);
    }else{
        end = floor(hidari);
    }
    ll ans = 0;
    for(ll i = start; i >= end; i--){
        ld Y = sqrt(r*r - (i - x)*(i - x));
        //cout << "Y = " << Y << endl;
        ld ue = y + Y;
        ld shita = y - Y;
        cout << ue << " " << shita << endl;
        ll tmp = floor(ue - shita);
        cout << "tmp" << " " << tmp << endl;
        ans += tmp;

        if(flag) ans++;
        //cout << i << " " << tmp << endl;
    }
    cout << ans << endl;

    /*
    cout << migi << endl;
    cout << start << endl;
    cout << end << endl;
    cout << floor(-1.5) << endl;
    cout << sqrt(5*5 - 3*3) << endl;
    */


}