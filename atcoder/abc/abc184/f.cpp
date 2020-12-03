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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, t; cin >> n >> t;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }

    if(n == 1){
        if(vec[0] <= t){
            cout << vec[0] << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }
    ll x = n / 2;
    vector<ll> mae, ato;
    for(ll i = 0; i < x; i++){
        mae.push_back(vec[i]);
    }
    for(ll i = x; i < n; i++){
        ato.push_back(vec[i]);
    }

    vector<ll> maeall;
    vector<ll> atoall;

    for(ll i = 0; i < (1 << mae.size()); i++){
        ll tmp = 0;
        for(ll j = 0; j < mae.size(); j++){
            if(i >> j & 1){
                tmp += mae[j];
            }
        }
        maeall.push_back(tmp);
    }
    for(ll i = 0; i < (1 << ato.size()); i++){
        ll tmp = 0;
        for(ll j = 0; j < ato.size(); j++){
            if(i >> j & 1){
                tmp += ato[j];
            }
        }
        atoall.push_back(tmp);
    }

    sort(all(maeall));
    sort(all(atoall));

    ll ans = 0;
    for(ll i = 0; i < maeall.size(); i++){
        
        ll x = upper_bound(atoall.begin(), atoall.end(), t-maeall[i]) - atoall.begin();
        
        if(x == 0){
            continue;
        }else{
            ans = max(ans, maeall[i] + atoall[x-1]);
        }
    }
    cout << ans << endl;
}