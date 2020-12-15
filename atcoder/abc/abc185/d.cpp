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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    vector<long long> vec(m);
    for(long long i = 0; i < m; i ++){
        cin >> vec[i];
        vec[i]--;
    }
    sort(all(vec));

    vector<ll> haba;
    ll haba_min = INF;
    for(ll i = 0; i < m; i++){
        if(i == 0){
            if(vec[i] == 0){
                continue;
            }else{
                haba.push_back(vec[i]);
                if(vec[i] != 0){
                    haba_min = min(haba_min, vec[i]);
                }
                
            }
        }else{
            haba.push_back(vec[i] - vec[i-1] - 1);
            if(vec[i] - vec[i-1] - 1 != 0){
                haba_min = min(haba_min, vec[i] - vec[i-1] - 1);
            }  
        }
    }
    if(vec[m-1] != n-1){
        haba.push_back(n-1 - vec[m-1]);
        if(n-1 - vec[m-1] != 0){
            haba_min = min(haba_min, n-1 - vec[m-1]);
        }
    }

    if(haba.size() == 0){
        cout << 0 << endl; return 0;
    }
    ll ans = 0;
    rep(i, haba.size()){
        //ans += haba[i] - haba_min + 1;
        if(haba[i] == 0) continue;
        ans += ceilll(haba[i], haba_min);
    }
    cout << ans << endl;

}