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
    ll t; cin >> t;
    rep(T, t){
        ll n, k; cin >> n >> k; k--; // sum n = 200000
        vector<long long> a(n);
        vector<ll> sum(n+1);
        for(long long i = 0; i < n; i ++){
            cin >> a[i];
            sum[i+1] = sum[i] + a[i];
        }

        //ここから
        vector<ll> res(n, -INF);
        res[k] = a[k];

        // 右に向かう
        ll l = k, r = k;
        ll ma = a[k];

        char muki = 'R';

        while(true){
            cerr << l << " " << r << endl;
            if(r == n-1){
                break;
            }
            bool f = false;
            // 右に行けるか
            if(muki == 'R'){
                if(res[r] + a[r+1] >= 0){
                    // 行ける
                    f = true;
                    muki = 'R';
                    res[r+1] = res[r] + a[r+1];
                    ma = max(ma, res[r+1]);
                    r = r + 1;
                    continue;
                }
            }else{
                if(ma + a[r+1] >= 0){
                    // 行ける
                    f = true;
                    muki = 'R';
                    res[r+1] = ma + a[r+1];
                    ma = max(ma, res[r+1]);
                    r = r+1;
                    continue;
                }
            }

            // 左に行けるか
            if(l > 0){
                if(muki == 'R'){
                    if(ma + a[l-1] >= 0){
                        // 行ける
                        f = true;
                        muki = 'L';
                        res[l-1] = ma + a[l-1];
                        ma = max(ma, res[l-1]);
                        l = l - 1;
                        continue;
                    }
                }else{
                    if(res[l] + a[l-1] >= 0){
                        // 行ける
                        f = true;
                        muki = 'L';
                        res[l-1] = res[l] + a[l-1];
                        ma = max(ma, res[l-1]);
                        l = l - 1;
                        continue;
                    }
                }
            }

            if(!f){
                // どっちもいけない
                break;
            }
        }

        vecdbg(res);

        if(res[n-1] >= 0){
            cerr << "r" << endl;
            cout << "YES" << endl;
            continue;
        }

        res.assign(n, -INF);
        res[k] = a[k];

        // 左に向かう
        l = k, r = k;
        ma = a[k];

        muki = 'L';

        while(true){
            if(l == 0){
                break;
            }

            bool f = false;
            // 左に行けるか
            if(muki == 'L'){
                if(res[l] + a[l-1] >= 0){
                    // 行ける
                    f = true;
                    muki = 'L';
                    res[l-1] = res[l] + a[l-1];
                    ma = max(ma, res[l-1]);
                    l = l - 1;
                    continue;
                }
            }else{
                if(ma + a[l-1] >= 0){
                    // 行ける
                    f = true;
                    muki = 'L';
                    res[l-1] = ma + a[l-1];
                    ma = max(ma, res[l-1]);
                    l = l-1;
                    continue;
                }
            }

            // 右に行けるか
            if(r < n-1){
                if(muki == 'L'){
                    if(ma + a[r+1] >= 0){
                        // 行ける
                        f = true;
                        muki = 'R';
                        res[r+1] = ma + a[r+1];
                        ma = max(ma, res[r+1]);
                        r = r + 1;
                        continue;
                    }
                }else{
                    if(res[r] + a[r+1] >= 0){
                        // 行ける
                        f = true;
                        muki = 'R';
                        res[r+1] = res[r] + a[r+1];
                        ma = max(ma, res[r+1]);
                        r = r + 1;
                        continue;
                    }
                }
            }

            if(!f){
                // どっちもいけない
                break;
            }
        }

        vecdbg(res);

        if(res[0] >= 0){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;

    }

}