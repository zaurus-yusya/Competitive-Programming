#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}
// for(auto& i: mp) &&&&&&&&&&&&&

int isInside(double ax, double ay, double bx, double by, double cx, double cy, double tx, double ty)
{
    double abXat, bcXbt, caXct;
 
    abXat = (bx-ax)*(ty-ay) - (by-ay)*(tx-ax);
    bcXbt = (cx-bx)*(ty-by) - (cy-by)*(tx-bx);
    caXct = (ax-cx)*(ty-cy) - (ay-cy)*(tx-cx);
  
    if(( abXat > 0.0 && bcXbt > 0.0 && caXct > 0.0) || ( abXat < 0.0 && bcXbt < 0.0 && caXct < 0.0))
    {
        return 1;
    }
    else if(abXat*bcXbt*caXct == 0.0)
    {
        return 0;
    }
 
    return 0;
 
}

int isConcave(vector<ld> px, vector<ld>py)
{
    int i;
    for(i=0; i<4; i++)
    {
        if(isInside(px[i%4], py[i%4], px[(i+1)%4], py[(i+1)%4], px[(i+2)%4], py[(i+2)%4], px[(i+3)%4], py[(i+3)%4]))
        {
            return 1;
        }
    }
 
    return 0;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    vector<ld> x(4);
    vector<ld> y(4);
    rep(i, 4){
        cin >> x[i] >> y[i];
    }

    if(isConcave(x,y))
    {
        cout << "No" << endl;
        //printf("凹を含む四角形です\n");
    }
    else
    {
        cout << "Yes" << endl;
        // printf("○凹=3\n");
    }



}