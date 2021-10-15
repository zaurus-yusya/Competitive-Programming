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
const long long MOD = 1e9+7;
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

void rotate(vector<vector<char>> &x){

    vector<vector<char>> tmp = x;

    rep(i, x.size()){
        rep(j, x.size()){
            x[i][j] = tmp[j][x.size() - 1 - i];
        }
    }

}

bool issame(vector<vector<char>> &s, vector<vector<char>> &t, ll n, ll count){

    for(ll sy = -n; sy < n; sy++){
        for(ll sx = -n; sx < n; sx++){

            bool f = true;
            ll cnt = 0;
            bool tmp = true;
            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < n; j++){
                    char x;
                    if(i+sy < 0 || i+sy >= n || j+sx < 0 || j+sx >= n){
                        x = '.';
                    }else{
                        x = t[i+sy][j+sx];
                    }
                    if(x == '#') cnt++;
                    if(s[i][j] != x){
                        f = false;
                        tmp = false;
                        break;
                    }
                }

                if(!tmp) break;
            }

            if(cnt != count){
                //cout << "false" << endl;
                f = false;
            }
            if(f){
                //cout << sy << " " << sx << endl;
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    rep(i, n)rep(j, n) cin >> s[i][j];
    vector<vector<char>> t(n, vector<char>(n));
    rep(i, n)rep(j, n) cin >> t[i][j];

    ll cnt = 0;
    rep(i, n)rep(j, n) if(t[i][j] == '#') cnt++;

    rep(i, 4){
        //vecvecdbg(t);
        if(issame(s, t, n, cnt)){
            cout << "Yes" << endl; return 0;
        }

        rotate(t);
        
    }
    cout << "No" << endl;

    

}