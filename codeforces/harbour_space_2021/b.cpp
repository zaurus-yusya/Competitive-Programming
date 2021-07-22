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

bool flag = false;
void calc(string &s, string &t, ll cnt, bool right, ll now){
    if(cnt == t.size()){
        flag = true;
    }

    //左移動
    if(now > 0 && s[now-1] == t[cnt]){
        calc(s, t, cnt+1, false, now-1);
    }

    //右移動
    if(right){
        if(now < s.size() - 1 && s[now+1] == t[cnt]){
            calc(s, t, cnt+1, right, now+1);
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll q; cin >> q;
    rep(Q, q){
        string s, t; cin >> s >> t;

        // 500 * 500 * 500
        flag = false;
        rep(i, s.size()){
            

            if(s[i] == t[0]){
                calc(s, t, 1, true, i);
            }

            if(flag == true){
                break;
            }

        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }

}