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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll p, q; cin >> p >> q;
        vector<ll> y(p);
        vector<ll> x(p);
        vector<char> c(p);

        vector<pair<ll, char>> yy;
        vector<pair<ll, char>> xx;
        ll yma = 0, xma = 0;
        rep(i, p){
            cin >> x[i] >> y[i] >> c[i];
            if(c[i] == 'N' || c[i] == 'S'){
                yy.push_back({y[i], c[i]});
                if(c[i] == 'S') yma++;
            }else{
                xx.push_back({x[i], c[i]});
                if(c[i] == 'W') xma++;
            }
        }
        //下:北 上:南 左:西, 右:東
        sort(all(yy)); sort(all(xx));

        ll yind = 0, xind = 0;
        ll ynow = 0, xnow = 0;
        rep(i, yy.size()){
            if(yy[i].second == 'N'){
                ynow = yy[i].first + 1;
            }else{
                ynow = yy[i].first;
            }
            ll tmp = 0;
            rep(j, yy.size()){
                if(yy[j].second == 'N'){
                    if(ynow > yy[j].first) tmp++;
                }else{
                    if(ynow < yy[j].first) tmp++;
                }
            }
            if(tmp > yma){
                yind = ynow; yma = tmp;
            }
            //cout << "ynow = " << ynow << endl;
        }
        rep(i, xx.size()){
            if(xx[i].second == 'E'){
                xnow = xx[i].first + 1;
            }else{
                xnow = xx[i].first;
            }
            ll tmp = 0;
            rep(j, xx.size()){
                if(xx[j].second == 'E'){
                    if(xnow > xx[j].first) tmp++;
                }else{
                    if(xnow < xx[j].first) tmp++;
                }
            }
            if(tmp > xma){
                xind = xnow; xma = tmp;
            }
        }

        cout << "Case #" << T+1 << ": " << xind << " " << yind << endl;
        
    }

}