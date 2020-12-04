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
    ll n; cin >> n;
    vector<long long> vec(n);
    map<ll, ll> even;
    map<ll, ll> odd;
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
        if(i % 2 == 1){
            even[vec[i]]++;
        }else{
            odd[vec[i]]++;
        }
    }

    ll even_first = 0, even_second = 0;
    ll even_first2 = 0, even_second2 = 0;
    ll odd_first = 0, odd_second = 0;
    ll odd_first2 = 0, odd_second2 = 0;

    ll tmp = 0;
    for(auto i: even){
        if(tmp < i.second){
            even_first = i.first, even_second = i.second;
            tmp = i.second;
        }
    }
    tmp = 0;
    for(auto i: even){
        if(tmp < i.second && i.first != even_first){
            even_first2 = i.first, even_second2 = i.second;
            tmp = i.second;
        }
    }
    tmp = 0;
    for(auto i: odd){
        if(tmp < i.second){
            odd_first = i.first, odd_second = i.second;
            tmp = i.second;
        }
    }
    tmp = 0;
    for(auto i: odd){
        if(tmp < i.second && i.first != odd_first){
            odd_first2 = i.first, odd_second2 = i.second;
            tmp = i.second;
        }
    }

    if(even_first == odd_first){
        cout << min( n - even_second2 - odd_second, n - even_second - odd_second2 ) << endl;
    }else{
        cout << n - even_second - odd_second << endl;
    }
}