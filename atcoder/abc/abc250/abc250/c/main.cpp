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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    vector<ll> vec(n);
    map<ll, ll> basyo;
    rep(i, n){
        vec[i] = i;
        basyo[i] = i;
    }
    rep(i, q){
        ll x; cin >> x; x--;

        ll ind = basyo[x];

        ll num;
        if(ind == n-1){
            num = vec[n-2];
        }else{
            num = vec[ind+1];
        }

        // cerr << ind << " " << ind+1 << endl;
        // cerr << x << " " << num << endl;
        // cerr << "--" << endl;

        if(ind == n-1){
            swap(vec[n-1], vec[n-2]);
            basyo[x] = n-2;
            basyo[num] = n-1;
        }else{
            swap(vec[ind], vec[ind+1]);
            basyo[x] = ind+1;
            basyo[num] = ind;
        }

        // vecdbg(vec);

    }

    // rep(i, n){
    //     cout << basyo[i] << " ";
    // }br;

    rep(i, n){
        cout << vec[i]+1 << " ";
    }br;

}