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
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        ll x = n / 3;
        vector<long long> a(n);
        map<ll, ll> mp;
        for(long long i = 0; i < n; i ++){
            cin >> a[i];
            mp[a[i] % 3] ++;
        }
        /*
        cout << x << endl;
        for(auto i: mp){
            cout << i.first << " " << i.second << endl;
        }
        */
        
        ll ans = 0;
        //one top
        if(mp[0] == mp[1] && mp[1] == mp[2]){
            ans = 0;
        }
        else if( (mp[0] > mp[1] && mp[0] > mp[2] ) ){
            /*
            ans += mp[0] - x;
            mp[1] = mp[1] + (mp[0] - x);
            ans += mp[1] - x;
            */
            ans = mp[0] - x + x - mp[2];
            //cout << "mp1 " << mp[1] << " x " << x << endl;
        }
        else if( (mp[1] > mp[0] && mp[1] > mp[2])){
            /*
            ans += mp[1] - x;
            mp[2] = mp[2] + (mp[1] - x);
            ans += mp[2] - x;
            */
            ans = mp[1] - x + x - mp[0];
        }
        else if( (mp[2] > mp[0] && mp[2] > mp[1])){
            /*
            ans += mp[2] - x;
            mp[0] = mp[0] + (mp[2] - x);
            ans += mp[0] - x;
            */
           ans = mp[2] - x + x - mp[1];
        }
        else if((mp[0] == mp[1] && mp[0] > mp[2])){
            /*
            ans += mp[0] - x;
            mp[1] = mp[1] + (mp[0] - x);
            ans += mp[1] - x;
            */
            ans = mp[0] - x + x - mp[2];
        }else if((mp[1] == mp[2] && mp[1] > mp[0]) ){
            /*
            ans += mp[1] - x;
            mp[2] = mp[2] + (mp[1] - x);
            ans += mp[2] - x;
            */
            ans = mp[1] - x + x - mp[0];
        }else if((mp[2] == mp[0] && mp[2] > mp[1]) ){
            /*
            ans += mp[2] - x;
            mp[0] = mp[0] + (mp[2] - x);
            ans += mp[0] - x;
            */
            ans = mp[2] - x + x - mp[1];
        }
        cout << ans << endl;

    }

}