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

ll x = 360 * 12e10;
ll y = 12e10;

bool f = false;
ll H = 0, M = 0, S = 0, NS = 0;

void calc(ll hour, ll minute, ll sec){

    //ナノsecの余り


    //hourについて
    //6時間経過でで180 * 12e10
    //1時間経過で30 * 12e10
    //1分経過で30 * 12e10 / 60
    //1秒経過で30 * 12e10 / 60 / 60

    //何秒経過したか
    ll timesec = hour / (30 * 12e10 / 60 / 60);

    //時間
    ll realhour = timesec / 3600;
    //分
    ll realmin = timesec / 60 % 60;
    //秒
    ll realsec = timesec % 60;
    //ナノ秒


    //分
    //1秒で12*10^9数値
    //秒
    //1秒で720*10^9数値

    ll mm = (realmin * 60 + realsec) * 12*1e9;
    ll ss = realsec * 720 * 1e9; 

    if(mm == minute && ss == sec){
        f = true;
        H = realhour;
        M = realmin;
        S = realsec;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll a, b, c; cin >> a >> b >> c;
        //1時間 60分 60秒
        //1時間 = 3600秒
        //1分 = 60秒
        //時間 1nanosec 1メモリ
        //分 1nanosec 12メモリ
        //秒 1nanosec 720メモリ 1秒で720*10^9数値
        //ナノ秒 1ナノ秒で720数値
        //1メモリ　1 / 12e10 度
        //時を固定したら時のメモリで何時何分何秒かわかる

        for(ll i = 0; i <= 360; i++){
            ll aa = (a + y * i) % x;
            ll bb = (b + y * i) % x;
            ll cc = (c + y * i) % x;
            f = false;
            vector<ll> vec = {aa, bb, cc};
            sort(all(vec));
            do{
                calc(vec[0], vec[1], vec[2]);
                if(f){
                    cout << "Case #" << (T+1) << ": " << H << " " << M << " " << S << " " << NS << endl;
                    break;
                }

            }while(next_permutation(vec.begin(), vec.end()));

            if(f) break;
        }

    }

}