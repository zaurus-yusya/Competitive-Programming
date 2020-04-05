#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    
    ll n;
    cin >> n;
    
    vector<ll> zero(61);
    vector<ll> one(61);
    rep(i, n){
        ll count = 0;
        ll tmp;
        cin >> tmp;
        for(ll j = 0; j < 61; j++){
            if(tmp & 1){
                one.at(count)++;
            }else{
                zero.at(count)++;
            }
            count++;
            tmp = tmp >> 1;
        }
    }

    ll ans = 0;
    ll twopow = 1;
    rep(i, 61){
        ll tmp;
        tmp = (zero[i] * one[i]) % MOD;
        tmp = (twopow * tmp) % MOD;
        ans = (ans + tmp) % MOD;
        twopow = (twopow * 2) % MOD; 
    }

    cout << ans << endl;
    
}