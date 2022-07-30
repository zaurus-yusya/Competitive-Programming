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

bool is_palindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;

    // if(n == 2 && s[0] == 'A' && s[1] == 'B'){
    //     cout << "No" << endl; return 0;
    // }

    if(s == "AB" || s == "BA"){
        cout << "No" << endl; return 0;
    }


    for(ll i = 0; i < n/2; i++){
        // 左端 s[i]
        // 右端 s[n-1 - i]
        if(s[i] == 'A' && s[n-1 - i] == 'B'){
            if(i == 0){
                cout << "No" << endl; return 0;
            }else{
                continue;
            }
            /*
            if(i + 1 == n-1 - i){
                cout << "Yes" << endl; return 0;
            }else{
                cout << "No" << endl; return 0;
            }
            */
        }else if(s[n-1 - i] == 'A'){
            // cerr << n-1-i << " " << i << endl;
            if( (n-1 - i - 1 == i) && (s[i] == 'B') ){
                cout << "No" << endl; return 0;
            }else{
                cout << "Yes" << endl; return 0;
            }
        }else{
            // s[i] == 'B' && s[n-1 - i] == 'B'
            continue;
        }
    }
    cout << "Yes" << endl;
    return 0;

    for(ll i = 0; i < n/2; i++){
        
        
        if(s[i] == s[n-1 - i]){
            continue;
        }else if(s[i] == 'A' && s[n-1 - i] == 'B'){
            if(i > 0 && s[i-1] == 'A'){
                s[i-1] = 'A';
                s[i] = 'B';
            }else{
                cout << "No" << endl; return 0;
            }
        }else if(s[i] == 'B' && s[n-1 - i] == 'A'){

            if(n-1 - i - 1 == i){
                cout << "No" << endl; return 0;
            }else{
                s[n-1 - i - 1] = 'A';
                s[n-1 - i] = 'B';
            }
        }
    }

    cout << "Yes" << endl;
    cerr << s << endl;

}