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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, c; cin >> n >> c;
    vector<ll> A(n);
    vector<ll> B(n);
    vector<ll> C(n);
    vector<tuple<ll, ll, ll>> t;
    
    rep(i, n){
        cin >> A[i] >> B[i] >> C[i]; A[i]--;
        t.emplace_back(A[i], B[i], C[i]);
    }
    sort(all(t));

    /*
    rep(i, n){
        cout << get<0>(t[i]) << " " << get<1>(t[i]) << " " << get<2>(t[i]) << endl;
    }
    */

    vector<pair<ll, ll>> nichi;
    map<ll, ll> mp;
    rep(i, n){
        nichi.push_back({A[i], C[i]});
        nichi.push_back({B[i], C[i] * (-1)});
        mp[A[i]] += C[i];
        mp[B[i]] -= C[i];
    }
    sort(all(nichi));

    /*
    rep(i, nichi.size()){
        cout << nichi[i].first << " " << nichi[i].second << endl;
    }
    */

    bool flag = true;
    ll now_nichi = 0;
    ll now_price = 0;
    ll ans = 0;
    for(auto i: mp){
        if(flag){
            flag = false;
            now_nichi = i.first;
            now_price = i.second;
        }else{
            if(now_price < c){
                ans += now_price * (i.first - now_nichi);
            }else{
                ans += c * (i.first - now_nichi);
            }
            now_nichi = i.first;
            now_price = now_price + i.second;
        }
        //cout << ans << endl;
        //cout << i.first << " " << i.second << endl;
    }

    cout << ans << endl;




}