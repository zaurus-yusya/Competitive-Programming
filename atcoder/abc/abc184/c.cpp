#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
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
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    if(r1 == r2 && c1 == c2){
        cout << 0 << endl;
        return 0;
    }

    //cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;



    r2 = r2 - r1;
    c2 = c2 - c1;
    //(0, 0)から移動
    /*
    cout << c2 - r2 << endl;
    cout << "--" << endl;
    cout << r2 << " " << c2 << endl;
    */
    

    if(r2 == c2 || r2*(-1) == c2){
        cout << 1 << endl;
    }else if(abs(r2) + abs(c2) <= 3){
        cout << 1 << endl;
    }else if(abs(c2 - r2) <= 3 || abs(c2*(-1) - r2) <= 3) {
        cout << 2 << endl;
    }else{
        if((c2 - r2) % 2 == 0){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
        
    }




}