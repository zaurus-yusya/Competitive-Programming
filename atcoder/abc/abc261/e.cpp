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
// for(auto& i: mp) &&&&&&&&&&&&&

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, c; cin >> n >> c;
    vector<ll> t(n);
    vector<ll> a(n);
    rep(i, n){
        cin >> t[i] >> a[i];
    }

    vector<ll> p2(30);
    ll pp = 1;
    for(ll i = 0; i < 30; i++){
        p2[i] = pp;
        pp *= 2;
    }

    vector<vector<ll>> vec(n+10, vector<ll>(32));
    vector<vector<ll>> vec_1(n+10, vector<ll>(32));

    // 前計算
    ll now = 0;
    ll now_1 = POW(2, 30) - 1;
    rep(i, n){

        if(t[i] == 1){
            // and
            ll tmp = now, x = a[i];
            ll tmp_1 = now_1, y = a[i];
            for(ll j = 0; j < 30; j++){
                vec[i][j] = (tmp & x) & 1;
                tmp >>= 1;
                x >>= 1;

                vec_1[i][j] = (tmp_1 & y) & 1;
                tmp_1 >>= 1;
                y >>= 1;
            }
            now = now & a[i];
            now_1 = now_1 & a[i];
        }
        else if(t[i] == 2){
            // or
            ll tmp = now, x = a[i];
            ll tmp_1 = now_1, y = a[i];
            for(ll j = 0; j < 30; j++){
                vec[i][j] = (tmp | x) & 1;
                tmp >>= 1;
                x >>= 1;

                vec_1[i][j] = (tmp_1 | y) & 1;
                tmp_1 >>= 1;
                y >>= 1;
            }
            now = now | a[i];
            now_1 = now_1 | a[i];
        }
        else if(t[i] == 3){
            // xor
            ll tmp = now, x = a[i];
            ll tmp_1 = now_1, y = a[i];
            for(ll j = 0; j < 30; j++){
                vec[i][j] = (tmp ^ x) & 1;
                tmp >>= 1;
                x >>= 1;

                vec_1[i][j] = (tmp_1 ^ y) & 1;
                tmp_1 >>= 1;
                y >>= 1;
            }
            now = now ^ a[i];
            now_1 = now_1 ^ a[i];
        }
    }


    // 答え求める
    for(ll i = 0; i < n; i++){
        ll tmp = c;
        vector<ll> nowc(30);

        ll cnt = 0;
        while(tmp > 0){
            nowc[cnt] = (tmp & 1);
            tmp >>= 1;
            cnt++;
        }
        
        vector<ll> num(30);
        for(ll j = 0; j < 30; j++){
            if(nowc[j] == 1){
                num[j] = vec_1[i][j];
            }else{
                num[j] = vec[i][j];
            }
        }

        ll next = 0;
        rep(j, 30){
            next += p2[j] * num[j];
        }
        cout << next << '\n';
        c = next;
    }
    

}