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


vector<string> hand = {"R", "P", "S"};

char janken(char a, char b){
    if( (a == 'R' && b == 'P') || (a == 'P' && b == 'R')){
        return 'P';
    }
    if( (a == 'S' && b == 'P') || (a == 'P' && b == 'S')){
        return 'S';
    }
    if( (a == 'R' && b == 'S') || (a == 'S' && b == 'R')){
        return 'R';
    }
    if(a == 'R' && b == 'R'){
        return 'R';
    }
    if(a == 'P' && b == 'P'){
        return 'P';
    }
    if(a == 'S' && b == 'S'){
        return 'S';
    }
    return 0;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    if(n == 1){
        cout << s << endl; return 0;
    }

    n *= 2;
    s += s;

    vector<char> bef(n);
    vector<char> now(n);
    rep(i, n){
        bef[i] = s[i];
    }
    for(ll i = 0; i < k; i++){
        ll cnt = 0;
        for(ll j = 0; j < 2 * n; j += 2){
            now[cnt] = janken(bef[j % n], bef[(j+1) % n]);
            cnt++;
        }
        //vecdbg(now);
        bef = now;
    }
    
    cout << now[0] << endl;

}