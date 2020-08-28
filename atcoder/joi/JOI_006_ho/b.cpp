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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<long long> vec(k);
    for(long long i = 0; i < k; i ++){
        cin >> vec[i];
    }
    sort(all(vec));
    
    bool flag = false;
    if(vec[0] == 0){
        vec.erase(vec.begin());
        flag = true;
    }
    
    //vecdbg(vec);

    ll cnt = 0;
    ll now = -1;
    vector<ll> res;
    for(ll i = 0; i < k; i ++){
        if(i == 0){
            now = vec[i]; cnt = 1; continue;
        }else if(vec[i] - now == 1){
            now = vec[i];
            cnt++;
        }else if(vec[i] - now == 2){
            res.push_back(cnt);
            res.push_back(-1);
            now = vec[i];
            cnt = 1;
        }else{
            res.push_back(cnt);
            res.push_back(-2);
            now = vec[i];
            cnt = 1;
        }
    }
    res.push_back(0);

    ll ans = 0;
    if(flag){
        rep(i, res.size()){
            ans = max(ans, res[i]);
            if(res[i] == -1){
                ans = max(ans, res[i-1] + res[i+1] + 1);
            }
        }
    }else{
        rep(i, res.size()){
            ans = max(ans, res[i]);
        }
    }

    //vecdbg(res);

    cout << ans << endl;


}