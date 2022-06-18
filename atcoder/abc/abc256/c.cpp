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

ll ans = 0;
ll h1, h2, h3, w1, w2, w3;

vector<vector<ll>> vec(3, vector<ll>(3));

void calc_3(){
    
    bool f = true;

    ll x1 = vec[0][0];
    ll y1 = vec[1][0];
    ll z1 = w1 - y1 - x1;

    ll x2 = vec[0][1];
    ll y2 = vec[1][1];
    ll z2 = w2 - y2 - x2;

    ll x3 = vec[0][2];
    ll y3 = vec[1][2];
    ll z3 = w3 - y3 - x3;

    if(z1 > 0 && z2 > 0 && z3 > 0 && (z1+z2+z3) == h3){
        ans++;
    }


}

void calc_2(){
    for(ll i = 1; i < h2; i++){
        ll x = i;
        for(ll j = 1; j < h2; j++){
            ll y = j;
            ll z = h2 - y - x;
            if(z <= 0) continue;

            // cerr << x << " " << y << " " << z << endl;
            vec[1][0] = x;
            vec[1][1] = y;
            vec[1][2] = z;

            calc_3();
        }
    }
}

void calc_1(){
    for(ll i = 1; i < h1; i++){
        ll x = i;
        for(ll j = 1; j < h1; j++){
            ll y = j;
            ll z = h1 - y - x;
            if(z <= 0) continue;

            // cerr << x << " " << y << " " << z << endl;
            vec[0][0] = x;
            vec[0][1] = y;
            vec[0][2] = z;

            calc_2();
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    calc_1();

    cout << ans << endl;
    
}