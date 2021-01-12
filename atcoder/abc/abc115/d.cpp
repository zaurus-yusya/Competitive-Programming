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
// If the result in local and judge is different, USE CODETEST!!

//BPPPB 5
//B BPPPB P BPPPB B 13  13/2 = 6

vector<ll> l(51);
vector<ll> p(51);

ll calc(ll n, ll x){
    if(n == 0) return 1;
    ll length = l[n];
    if(x == 1){
        return 0;
    }else if(x <= length / 2){
        return calc(n-1, x-1);
    }else if(x == (length / 2) + 1){
        return p[n-1] + 1;
    }else{
        return p[n-1] + 1 + calc(n-1, x - ((length/2) + 1));
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, x; cin >> n >> x;

    for(ll i = 0; i <= 50; i++){
        if(i == 0){
            l[i] = 1; p[i] = 1; continue;
        }else{
            l[i] = 2 * l[i-1] + 3;
            p[i] = 2 * p[i-1] + 1; 
        }
    }

    cout << calc(n, x) << endl;


}