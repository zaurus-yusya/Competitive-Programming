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

void calc0(ll n){
    ll now = 0;
    rep(i, n){
        rep(j, n){
            if(j / 3 == now / 3){
                cout << '#';
            }else{
                cout << '.';
            }
        }br;
        now += 3;
        now = now % n;
    }
}

void calc1(ll n){
    ll now = 0;
    rep(i, n/3){
        rep(j, n){
            if(j / 3 == now / 3){
                cout << '#';
            }else{
                cout << '.';
            }
        }br;
        now += 3;
        now = now % n;
    }
    vector<vector<char>> vec(3, vector<char>(n, '.'));
    vec[0][n-1] = '#'; vec[1][n-1] = '#'; vec[2][n-1] = '#';
    vec[0][n-1-6] = '#'; vec[0][n-1-5] = '#';
    vec[1][n-1-4] = '#'; vec[1][n-1-3] = '#';
    vec[2][n-1-2] = '#'; vec[2][n-1-1] = '#';
    rep(i, 3){
        rep(j, n){
            cout << vec[i][j];
        }br;
    }

    ll N = n-1;
    ll NOW = 0;
    rep(i, n - 3 - n/3){
        rep(j, N){
            if(j / 3 == NOW / 3){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << '.';
        br;
        NOW += 3;
        NOW = NOW % N;
    }
}

void calc2(ll n){
    ll now = 0;
    rep(i, n/3){
        cout << '.';
        rep(j, n-1){
            if(j / 3 == now / 3){
                cout << '#';
            }else{
                cout << '.';
            }
        }br;
        now += 3;
        now = now % n;
    }

    vector<vector<char>> vec(6, vector<char>(n, '.'));
    vec[0][n-1] = '#'; vec[1][n-1] = '#'; vec[2][n-1] = '#';
    vec[0][n-1-6] = '#'; vec[0][n-1-5] = '#';
    vec[1][n-1-4] = '#'; vec[1][n-1-3] = '#';
    vec[2][n-1-2] = '#'; vec[2][n-1-1] = '#';

    vec[3][0] = '#'; vec[4][0] = '#'; vec[5][0] = '#';
    vec[3][1] = '#'; vec[3][2] = '#';
    vec[4][3] = '#'; vec[4][4] = '#';
    vec[5][5] = '#'; vec[5][6] = '#';
    rep(i, 6){
        rep(j, n){
            cout << vec[i][j];
        }br;
    }

    if(n == 8){
        return;
    }
    if(n == 11){
        vector<vector<char>> vec2(2, vector<char>(n, '.'));
        vec2[0][1] = '#'; vec2[0][2] = '#'; vec2[0][3] = '#';
        vec2[1][7] = '#'; vec2[1][8] = '#'; vec2[1][9] = '#';
        rep(i, 2){
            rep(j, n){
                cout << vec2[i][j];
            }br;
        }
        return;
    }

    now = 0;
    rep(i, n/3){
        cout << '.';
        rep(j, n-1){
            if(j / 3 == now / 3){
                cout << '#';
            }else{
                cout << '.';
            }
        }br;
        now += 3;
        now = now % n;
    }

    ll N = n - 14;
    ll NOW = 0;
    rep(i, N/3){
        rep(j, 7){
            cout << '.';
        }
        rep(j, N){
            if(j / 3 == NOW / 3){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        NOW += 3;
        NOW = NOW % N;
        rep(j, 7){
            cout << '.';
        }br;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    if(n % 3 == 0){
        calc0(n);
    }
    if(n % 3 == 1){
        calc1(n);
    }
    if(n % 3 == 2){
        calc2(n);
    }

}