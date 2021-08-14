#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
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
    ll n; cin >> n;
    ll sum = 0;
    vector<long long> s(n);
    for(long long i = 0; i < n; i ++){
        cin >> s[i];
        sum += s[i];
    }
    vector<long long> t(n);
    vector<P> T(n);
    map<ll, ll> mp;
    ll mi = INF, mii = -1;
    for(long long i = 0; i < n; i ++){
        cin >> t[i];
        T[i] = {t[i], i};
        mp[i] = t[i];
        if(mi > t[i]){
            mi = t[i]; mii = i;
        }
    }

    //sort(all(T));

    vector<ll> ans(n);

    ll x = mii; //最初の石の場所
    ll basyo = mi;
    ans[x] = basyo;
    cerr << "x = " << x << endl;

    rep(i, n){
        if(i == 0) continue;

        if(mp[(x + i) % n] < ans[(x+i-1) % n] + s[(x+i-1) % n]){
            ans[(x + i) % n] = T[(x + i) % n].first;
            //cerr << "in " << (x + i) % n << " " << T[(x + i) % n].first << endl;
        }else{
            ans[(x + i) % n] = ans[(x+i-1) % n] + s[(x+i-1) % n];
            //cerr << (x + i) % n << " " << ans[(x+i-1) % n] + s[(x+i-1) % n] << endl;
        }

    }


    rep(i, n){
        cout << ans[i] << '\n';
    }
    /*
    rep(i, n){
        cout << T[i].first << " " << T[i].second << endl;
    }
    */






}