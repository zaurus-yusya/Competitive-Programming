#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

template <typename T>
vector<vector<T>> mat_mul(vector<vector<T>> a, vector<vector<T>> b){
    ll I = a.size(), J = b[0].size(), K = b.size();
    vector<vector<T>> res(I, vector<T>(J));

    rep(i, I){
        rep(j, J){
            ll tmp = 0;
            rep(k, K){
                tmp += a[i][k] * b[k][j];
            }
            res[i][j] = tmp;
        }
    }

    return res;
}

template <typename T>
vector<vector<T>> mat_pow(vector<vector<T>> a, ll n){
    vector<vector<T>> res(a.size(), vector<T>(a[0].size()));
    rep(i, a.size()) res[i][i] = 1;

    while(n > 0){
        if(n & 1 == 1){
            res = mat_mul(a, res);
        }
        a = mat_mul(a, a);
        n >>= 1;
    }

    return res;
}

ll vec[200010][3][3];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    rep(i, n){
        cin >> x[i] >> y[i];
    }

    rep(i, 3){
        rep(j, 3){
            if(i == j) vec[0][i][j] = 1;
            else vec[0][i][j] = 0;
        }
    }
    
    ll m; cin >> m;

    vector<vector<ll>> one = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    vector<vector<ll>> two = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    vector<vector<ll>> three = {{-1, 0, 1}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<ll>> four = {{1, 0, 0}, {0, -1, 1}, {0, 0, 1}};

    rep(i, m){
        ll t; cin >> t;

        if(t == 1){
            
            vector<vector<ll>> tmp(3, vector<ll>(3));
            rep(h, 3)rep(w, 3){
                tmp[h][w] = vec[i][h][w];
            }
            tmp = mat_mul(one, tmp);
            rep(h, 3)rep(w, 3){
                vec[i+1][h][w] = tmp[h][w];
            }
            
        }
        if(t == 2){

            vector<vector<ll>> tmp(3, vector<ll>(3));
            rep(h, 3)rep(w, 3){
                tmp[h][w] = vec[i][h][w];
            }
            tmp = mat_mul(two, tmp);
            rep(h, 3)rep(w, 3){
                vec[i+1][h][w] = tmp[h][w];
            }

        }
        if(t == 3){
            ll p; cin >> p;
            three[0][2] = 2 * p;

            vector<vector<ll>> tmp(3, vector<ll>(3));
            rep(h, 3)rep(w, 3){
                tmp[h][w] = vec[i][h][w];
            }
            tmp = mat_mul(three, tmp);
            rep(h, 3)rep(w, 3){
                vec[i+1][h][w] = tmp[h][w];
            }

            three[0][2] = 1;
        }
        if(t == 4){
            ll p; cin >> p;
            four[1][2] *= 2 * p;

            vector<vector<ll>> tmp(3, vector<ll>(3));
            rep(h, 3)rep(w, 3){
                tmp[h][w] = vec[i][h][w];
            }
            tmp = mat_mul(four, tmp);
            rep(h, 3)rep(w, 3){
                vec[i+1][h][w] = tmp[h][w];
            }

            four[1][2] = 1;

        }

    }

    ll q; cin >> q;
    rep(i, q){
        ll a, b; cin >> a >> b; b--;
        ll X = 0, Y = 0;
        X += vec[a][0][0] * x[b];
        X += vec[a][0][1] * y[b];
        X += vec[a][0][2] * 1;
        Y += vec[a][1][0] * x[b];
        Y += vec[a][1][1] * y[b];
        Y += vec[a][1][2] * 1;
        cout << X << " " << Y << endl;
    }
    
}