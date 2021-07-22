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
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, m; cin >> n >> m;
        vector<long long> p(n);
        for(long long i = 0; i < n; i ++){
            cin >> p[i];
        }

        // 1 2 3 4
        // 2 1 4 3　2回
        // 2 3 4 1  3回

        // 1 2 3 4 5
        // 2 1 4 3 5
        // 3 2 1 5 4
        // -2 0 +2
        // 2 3 4 5 1
        // 4 3 2 5 1
        // +3  -1

        map<ll, ll> mp;
        rep(i, n){
            mp[(i+1) - p[i]]++;
        }
        vector<ll> ans;
        for(auto i: mp){
            //cout << i.first << " " << i.second << endl;
            //不一致数
            ll x = n - i.second;

            //回数
            ll num = 0;
            map<ll, ll> tmp = mp;
            ll tasu = 0;
            for(auto j : tmp){
                if(i.first == j.first) continue;
                ll X = i.first - j.first;
                
                if(tmp.count(i.first - (-1*j.first)) > 0 && tmp[i.first - (-1*j.first)] > 0){
                    ll hiku = min(i.second, j.second);
                    num += hiku;
                    tmp[i.first] -= hiku; tmp[j.first] -= hiku;
                }else{
                    tasu += j.second;
                    //num += j.second;
                }
            }
            if(tasu > 0) num += tasu - 1;

            //cout << "num = " << num << endl;

            ll y = i.first;
            //if(x - 1 <= m){
            if(num <= m){
                if(y < 0){
                    y += n;
                }
                ans.push_back(y);
            }
        }
        
        sort(all(ans));

        cout << ans.size();
        rep(i, ans.size()){
            cout << " " << ans[i];
        }br;
        cout << "--" << endl;

        // m = 1  m+1箇所以上一致
        // 1 2 3 4  1箇所一致　3箇所不一致　2回
        // 2 3 4 1　2箇所一致　 2箇所不一致　1回
        // 3 4 1 2　1箇所一致　3箇所不一致　2回
        // 4 1 2 3　0箇所一致　４箇所不一致　3回

        // 2 3 1 4
        // -1 -1 +2 0
        // 1 2 3 4　１箇所
        // 2 3 4 1　２箇所
        // 3 4 1 2　１箇所
        // 4 1 2 3　０箇所

        // 2 3 1 4 5
        // -1 -1 +2 +0 +0
        
        // 1 2 3 4 5　２箇所
        // 2 3 4 5 1　２箇所
        // 3 4 5 1 2　０箇所
        // 4 5 1 2 3　１箇所
        // 5 1 2 3 4　０箇所



        // 3 4 1 2

        // 1 2 3
        // 2 3 1
        // 3 1 2

    }

}