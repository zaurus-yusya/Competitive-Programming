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
        vector<long long> d(2 * n);
        vector<ll> sum(2 * n + 1);
        map<ll, ll> mp;
        bool flag = true;
        for(long long i = 0; i < 2 * n; i ++){
            cin >> d[i];
            if(d[i] % 2 == 1) flag = false;
            mp[d[i]]++;
        }
        

        
        sort(all(d), greater<ll>());
        rep(i, 2*n){
            sum[i+1] = sum[i] + d[i];
        }

        vecdbg(d);
        vecdbg(sum);

        cout << "---" << endl;
        for(ll i = 0; i < 2 * n; i++){
            //cout << ( sum[i] - sum[0] - (i * d[i]) ) << " " << ( (2*n-i-1)*d[i] - (sum[2*n] - sum[i+1])) <<endl;
            cout << ( sum[i] - sum[0] - (i * d[i]) ) + ( (2*n-i-1)*d[i] - (sum[2*n] - sum[i+1])) <<endl;
        }
        cout << "---" << endl;
        
        
        
        vector<ll> sa;
        ll now = 0;
        ll res = 0;
        bool flag2 = false;
        for(auto i: mp){
            if(flag2){
                sa.push_back(i.first - now);
                now = i.first;
                res = i.first;
            }else{
                flag2 = true;
                now = i.first;
            }
            /*
            now = i.first;
            cout << i.first <<  " " << i.second << endl;
            */
        }
        vecdbg(sa);

        string ans = "YES";
        ll tmp = 1, tmp2 = 1;
        ll cur = 2;
        rep(i, sa.size()){
            if(sa[i] % cur != 0){
                ans = "NO";
            }
            tmp2 = tmp2 + sa[i] / cur;
            tmp += tmp2;
            cur += 2;
        }
        cout << tmp << " " << res << endl;
        if(tmp > (res/2)){
            ans = "NO";
        }
        cout << ans << endl;

    }

}