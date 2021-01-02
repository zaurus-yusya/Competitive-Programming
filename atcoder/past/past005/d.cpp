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

bool cmp(pair<string, string> a, pair<string, string> b){
    if(a.first.size() != b.first.size()){
        return a.first.size() < b.first.size();
    }else if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<string> vec(n);
    rep(i, n) cin >> vec[i];
    vector<pair<string, string>> vec2(n);
    for(ll i = 0; i < n; i++){
        string l = "", r = "";
        bool flag = true;
        for(ll j = 0; j < vec[i].size(); j++){
            if(vec[i][j] == '0' && flag){
                r += vec[i][j];
            }else{
                flag = false;
                l += vec[i][j];
            }
        }
        vec2[i] = {l, r};
    }

    sort(all(vec2), cmp);

    rep(i, n){
        if(vec2[i].second.size() != 0){
            cout << vec2[i].second << vec2[i].first << endl;
        }else{
            cout << vec2[i].first << endl;
        }
        
    }


}