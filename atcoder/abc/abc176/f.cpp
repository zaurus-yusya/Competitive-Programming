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
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    queue<ll> que;
    map<ll, ll> mp;
    for(long long i = 0; i < 3*n; i ++){
        ll x; cin >> x;
        mp[x]++;
        que.push(x);
    }

    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        map<ll, ll> tmp;
        rep(j, 5){
            ll x = que.front();
            que.pop();
            tmp[x]++;
        }
        bool flag = false;
        for(auto k: tmp){
            if(k.second >= 3){
                mp[k.second] -= 3;
                ans += 1;
                flag = true;
            }
        }
        if(!flag){
            vector<ll> next(3);
            vec[0] = que.front();
            que.pop();
            vec[1] = que.front();
            que.pop();
            vec[2] = que.front();
            que.push(vec[1]);
            que.push(vec[0]);
            map<ll, ll> nextm;
            rep(j, 3){
                nextm[vec[i]]++;
            }

            for(auto k: tmp){
                if(mp[])
            }
        }
    }





}