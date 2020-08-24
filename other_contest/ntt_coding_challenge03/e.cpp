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

map<ll, ll> mp;

void calc(ll keta, ll now_keta, string s, ll n, ll t, ll n_cnt, ll t_cnt){
    
    if(s.size() == keta){
        if(n_cnt != 0 && t_cnt != 0){
            if(n_cnt == t_cnt * 2 || t_cnt == n_cnt * 2){
                ll tmp = stoll(s);
                mp[tmp]++;
            }
        }   
    }else if(now_keta == 0 && n == 0){
        s = s + to_string(t);
        calc(keta, now_keta + 1, s, n, t, 0, 1);
    }else{
        
        calc(keta, now_keta + 1, s + to_string(n), n, t, n_cnt + 1, t_cnt);
        calc(keta, now_keta + 1, s + to_string(t), n, t, n_cnt, t_cnt + 1);
        
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll k; cin >> k;
    for(ll i = 0; i <= 9; i++){
        for(ll j = i+1; j <= 9; j++){
            calc(3, 0, "", i, j, 0, 0);
            calc(6, 0, "", i, j, 0, 0);
            calc(9, 0, "", i, j, 0, 0);
            calc(12, 0, "", i, j, 0, 0);
            calc(15, 0, "", i, j, 0, 0);
        }
    }
    
    ll cnt = 1;
    for(auto i: mp){
        if(cnt == k){
            cout << i.first << endl;
            return 0;
        }else{
            cnt++;
        }
    }

}