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

pair<ll, ll> numberhenkan(string s, string e){
    ll x = 0, y = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[s.size() - 1 - i] == '1'){
            x += POW(2, i);
        }
    }
    for(ll i = 0; i < e.size(); i++){
        if(e[e.size() - 1 - i] == '1'){
            y += POW(2, i);
        }
    }

    return {x, y};
}

vector<ll> memo( ((1 << 10) + 10), -1);

ll ans = INF;
ll C = 0;
void calc(ll x, ll y, ll cnt){
    if(x == y){
        //cout << x << " " << y << " " << cnt << endl;
        //cout << memo[y] << endl; 
        chmin(ans, cnt);
        return;
    }

    if(x >= ((1 << 10) + 10) ){
        return;
    }

    memo[x] = cnt;


    if(x*2 < ((1<<10) + 10)){
        if(memo[x*2] == -1){
            calc(x * 2, y, cnt+1);
        }else if(memo[x * 2] > cnt+1){
            calc(x * 2, y, cnt+1);
        }
    }
    

    //NOT
    ll num = 0;
    if(x == 0){
        num = 1;
    }else{
        ll tmp_x = x;
        ll c = 0;
        while(tmp_x > 0){

            if( (tmp_x & 1) ){

            }else{
                num += POW(2, c);
            }

            tmp_x = (tmp_x >> 1);
            c++;
        }
    }


    if(num < ((1<<10) + 10)){
        if(memo[num] == -1){
            calc(num, y, cnt+1);
        }else if(memo[num] > cnt + 1){
            calc(num, y, cnt+1);
        }
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        string s, e; cin >> s >> e;
        memo.assign((1<<10)+10, -1);
        ans = INF;
        if(s == e){
            cout << "Case #" << T+1 << ": " << 0 << endl; continue;
        }
        pair<ll, ll> v = numberhenkan(s, e);
        ll x = v.first, y = v.second;

        calc(x, y, 0);

        if(ans == INF){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << endl; 
        }else{
            cout << "Case #" << T+1 << ": " << ans << endl; 
        }
        //cout << C << endl;

    }

}