#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
    string s, t; cin >> s >> t;
    ll size = s.size();
    s += s;

    // a 0 z 25
    vector<ll> first(26, INF);
    vector<vector<ll>> mozi(26);
    rep(i, s.size()){
        ll c = s[i] - 'a';
        first[c] = min(first[c], (i));
        mozi[c].push_back(i);
    }

    vector<vector<ll>> tugi(size, vector<ll>(26, -1));
    rep(i, size){
        rep(j, 26){
            if(mozi[j].size() == 0) continue;

            //次が現れる最小
            ll x = upper_bound(mozi[j].begin(), mozi[j].end(), i) - mozi[j].begin();
            if(( (mozi[j][x] - i) % size )== 0){
                tugi[i][j] = size;
            }else{
                tugi[i][j] = (mozi[j][x] - i) % size;
            }
            

            
        }
    }

    ll ans = 0;
    ll cur = 0;
    rep(i, t.size()){
        ll c = t[i] - 'a';
        if(i == 0){
            if(first[c] == INF){
                cout << -1 << endl; return 0;
            }else{
                ans += first[c] + 1;
                cur += first[c];
            }
        }else{
            if(tugi[cur][c] == -1){
                cout << -1 << endl; return 0;
            }else{
                ans += tugi[cur][c];
                cur = (cur + tugi[cur][c]) % size;
            }
        } 

    }
    cout << ans << endl;

}