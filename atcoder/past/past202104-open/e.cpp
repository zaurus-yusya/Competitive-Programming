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
    ll n; cin >> n;
    string s; cin >> s;
    deque<char> deq;
    ll now = 1;
    rep(i, s.size()){
        if(s[i] == 'L'){
            deq.push_front(now);
        }
        if(s[i] == 'R'){
            deq.push_back(now);
        }
        if(s[i] == 'A'){
            if(deq.size() <= 0){
                cout << "ERROR" << endl;
            }else{
                ll x = deq.front();
                cout << x << endl;
                deq.pop_front();
            }
        }
        if(s[i] == 'B'){
            if(deq.size() <= 1){
                cout << "ERROR" << endl;
            }else{
                ll fi;
                fi = deq.front();
                deq.pop_front();
                ll x = deq.front();
                cout << x << endl;
                deq.pop_front();
                deq.push_front(fi);
            }
        }
        if(s[i] == 'C'){
            if(deq.size() <= 2){
                cout << "ERROR" << endl;
            }else{
                ll fi, se;
                fi = deq.front();
                deq.pop_front();
                se = deq.front();
                deq.pop_front();
                ll x = deq.front();
                cout << x << endl;
                deq.pop_front();
                deq.push_front(se);
                deq.push_front(fi);
            }
        }
        if(s[i] == 'D'){
            if(deq.size() <= 0){
                cout << "ERROR" << endl;
            }else{
                ll x = deq.back();
                cout << x << endl;
                deq.pop_back();
            }
        }
        if(s[i] == 'E'){
            if(deq.size() <= 1){
                cout << "ERROR" << endl;
            }else{
                ll fi;
                fi = deq.back();
                deq.pop_back();
                ll x = deq.back();
                cout << x << endl;
                deq.pop_back();
                deq.push_back(fi);
            }
        }
        if(s[i] == 'F'){
            if(deq.size() <= 2){
                cout << "ERROR" << endl;
            }else{
                ll fi, se;
                fi = deq.back();
                deq.pop_back();
                se = deq.back();
                deq.pop_back();
                ll x = deq.back();
                cout << x << endl;
                deq.pop_back();
                deq.push_back(se);
                deq.push_back(fi);
            }
        }

        now++;
    }

}