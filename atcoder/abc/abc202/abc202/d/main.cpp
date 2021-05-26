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

map<string, ll> mp;

void calc(ll a, ll b, ll nowa, ll nowb, string s){

    if(nowa + nowb == a + b){
        mp[s]++;
    }else{

        if(nowa < a){
            s += 'a';
            calc(a, b, nowa+1, nowb, s);
            s.pop_back();
        }
        if(nowb < b){
            s += 'b';
            calc(a, b, nowa, nowb+1, s);
        }

    }

}

ll ncr(ll n, ll r){
    ll res = 1;
    for(ll i = 1; i <= r; i++){
        res *= (n+1-i);
        res /= i;
    }
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b, k; cin >> a >> b >> k;

    //calc(a, b, 0, 0, "");
    //cout << ncr(3, 2) << endl;

    string res = "";
    ll cnt = 0;
    ll nowa = a, nowb = b;
    rep(i, a+b){
        if(nowa == 0){
            res += 'b'; continue;
        }
        if(nowb == 0){
            res += 'a'; continue;
        }

        //aかどうか
        ll x = ncr(a+b-1-i, nowb);
        if(cnt + x < k){
            //b
            cnt += x;
            res += 'b';
            nowb -= 1;
        }else{
            //a
            res += 'a';
            nowa -= 1;
        }

    }
    cout << res << endl;
    

    /*
    ll cnt = 0;
    for(auto i : mp){
        cnt++;
        if(cnt == k){
            cout << i.first << endl;
            break;
        }
        //cout << i.first << " " << i.second << endl;
    }
    */



}