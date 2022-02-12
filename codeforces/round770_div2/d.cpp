#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
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
        ll n; cin >> n;

        //1, 2, x
        map<ll, ll> mpp;
        ll fi = -1, se = -1, fiind = -1, seind = -1;
        for(ll i = 3; i <= n; i++){
            cout << "? 1 2 " << i << endl;
            cout.flush();
            ll x; cin >> x; mpp[x]++;
            //cerr << "x = " << x << endl;
            if(fi < x){
                se = fi; seind = fiind;
                fi = x; fiind = i;
                
            }else if(se < x){
                se = x; seind = i;
            }
        }
        // if(mpp.size() == 1){
        //     cout << "! " << 1 << " " << 2 << endl;
        //     cout.flush();
        //     continue;
        // }
        
        cerr << "fi = " << fi << " fiind = " << fiind << endl;
        cerr << "se = " << se << " seind = " << seind << endl;

        ll ma = -1, maind = -1;
        ll ffi = -1, sse = -1, ffiind = -1, sseind = -1;
        map<ll, ll> mp;
        for(ll i = 1; i <= n; i++){
            if(i == fiind || i == seind){
                continue;
            }
            cout << "? " << fiind << " " << seind << " " << i << endl;
            cout.flush();
            ll x; cin >> x; mp[x]++;
            if(ma < x){
                ma = x; maind = i;
            }
            if(ffi < x){
                sse = ffi; sseind = ffiind;
                ffi = x; ffiind = i;
                
            }else if(sse < x){
                sse = x; sseind = i;
            }
        }

        // if(mp.size() == 1){
        //     cout << "! " << fiind << " " << seind << endl;
        //     cout.flush();
        //     continue;
        // }

        //2個選ぶ
        vector<ll> vec;
        for(ll i = 1; i <= n; i++){
            if(i == ffiind || i == fiind || i == seind){
                continue;
            }else{
                vec.push_back(i);
                if(vec.size() == 1){
                    break;
                }
            }
        }

        //cerr << "ma = " << ma << " maind = " << maind << endl;
        cerr << "ffi = " << ffi << " ffiind = " << ffiind << endl;
        cerr << "sse = " << sse << " sseind = " << sseind << endl;

        if(fi > ffi){
            cout << "! " << 1 << " " << 2 << endl;
            cout.flush();
            continue;
        }

        cout << "? " << ffiind << " " << vec[0] << " " << fiind << endl;
        cout.flush();
        ll x; cin >> x;
        cout << "? " << ffiind << " " << vec[0] << " " << seind << endl;
        cout.flush();
        ll y; cin >> y;

        // cout << "? " << vec[0] << " " << vec[1] << " " << fiind << endl;
        // cout.flush();
        // ll x; cin >> x;
        // cout << "? " << vec[0] << " " << vec[1] << " " << seind << endl;
        // cout.flush();
        // ll y; cin >> y;


        if(x < y){
            cout << "! " << ffiind << " " << seind << endl;
            cout.flush();
        }else if(x == y){
            cout << "! " << ffiind << " " << vec[0] << endl;
            cout.flush();
        }else{
            cout << "! " << ffiind << " " << fiind << endl;
            cout.flush();
        }

        

        // cout << "! " << maind << " " << seind << endl;
        // cout.flush();

        
    }

}