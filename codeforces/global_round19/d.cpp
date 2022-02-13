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

vector<ll> res;
bool f = false;

void rec(vector<vector<ll>> &dp, vector<ll> &a, vector<ll> &b, ll i, ll j, vector<ll> &keiro){
    if(f){
        return;
    }

    if(i == 0){
        if(j == 0){
            res = keiro;
            f = true;
        }
        return;
    }

    if(f){
        return;
    }

    //Aの方に遡る
    if(j - a[i-1] >= 0){
        if(dp[i-1][j - a[i-1]]){
            keiro.push_back(a[i-1]);
            rec(dp, a, b, i-1, j - a[i-1], keiro);
            keiro.pop_back();
        }
    }

    if(f){
        return;
    }

    //Bの方に遡る
    if(j - b[i-1] >= 0){
        if(dp[i-1][j - b[i-1]]){
            keiro.push_back(b[i-1]);
            rec(dp, a, b, i-1, j - b[i-1], keiro);
            keiro.pop_back();
        }
    }

    if(f){
        return;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        f = false;
        res.resize(0);

        ll n; cin >> n;
        vector<long long> a(n);
        ll suma = 0;
        for(long long i = 0; i < n; i ++){
            cin >> a[i]; suma += a[i];
        }
        vector<long long> b(n);
        ll sumb = 0;
        for(long long i = 0; i < n; i ++){
            cin >> b[i]; sumb += b[i];
        }
        if(n == 1){
            cout << 0 << endl;
            continue;
        }

        vector<vector<ll>> dp(110, vector<ll>(10010));
        dp[0][0] = 1;
        for(ll i = 0; i < n; i++){

            for(ll j = 0; j <= 10000; j++){
                //Aから選ぶ
                if(j + a[i] <= 10000){
                    dp[i+1][j + a[i]] += dp[i][j];
                    
                    if(dp[i+1][j + a[i]] > 1){
                        dp[i+1][j + a[i]] = 1;
                    }
                    
                }
                //Bから選ぶ
                if(j + b[i] <= 10000){
                    dp[i+1][j + b[i]] += dp[i][j];
                    
                    if(dp[i+1][j + b[i]] > 1){
                        dp[i+1][j + b[i]] = 1;
                    }
                    
                }
            }

        }

        ll sumall = suma + sumb;
        ll ma = INF, val = -1;
        for(ll j = 0; j <= 10000; j++){
            if(dp[n][j] == 0) continue;

            ll x = j * j + (sumall - j) * (sumall - j);
            if(ma > x){
                ma = x; val = j;
            }
        }


        //復元
        vector<ll> keiro;
        keiro.resize(0);
        rec(dp, a, b, n, val, keiro);

        reverse(all(res));

        vector<ll> resa;
        vector<ll> resb;

        rep(i, n){
            if(res[i] == a[i]){
                resa.push_back(a[i]);
                resb.push_back(b[i]);
            }else{
                resa.push_back(b[i]); 
                resb.push_back(a[i]); 
            }
        }

        ll cost = 0;
        for(ll i = 0; i < n; i++){
            for(ll j = i+1; j < n; j++){
                cost += (resa[i] + resa[j]) * (resa[i] + resa[j]);
                cost += (resb[i] + resb[j]) * (resb[i] + resb[j]);
            }
        }
        cout << cost << endl;

    }

}