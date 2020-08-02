#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;
    map<ll, ll> mp;
    ll cnt = 0;
    priority_queue<ll> pq;
    rep(i, n){
        if(s[i] == 'R'){
            mp[i]++;
            cnt++;
            //pq.push(i);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < cnt; i++){
        if(mp[i] == 0){
            ans++;
        }
    }
    cout << ans << endl;

    /*
    ll ans = 0;
    ll flag = 0;
    vector<ll> 
    rep(i, n){
        if(s[i] == 'W'){
            ans++;
            flag++;
        }
        if(s[i] == 'R'){

        }
    }
    */

}