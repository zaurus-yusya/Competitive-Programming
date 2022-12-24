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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(all(a));
    vector<ll> b(n);
    rep(i, n){
        b[i] = a[n-1 - i];
    }

    // vecdbg(a);
    // vecdbg(b);

    // 0が出るまで続ける
    
    ll cnt = 0;
    while(true){
        if(cnt % 2 == 0){
            // aでやる
            bool sousa = false;
            for(ll i = 0; i < n; i++){
                ll s = a[i];
                ll dis = lower_bound(a.begin(), a.end(), 2 * s) - a.begin();

                bool f = false;
                ll tmp = -1;
                if(dis >= n-1){
                    for(ll j = 0; j < n; j++){
                        a[j] = 2 * s - a[j];

                        tmp = max(tmp, a[j]);
                        if(a[j] == 0){
                            f = true;
                        }
                    }
                    sousa = true;
                }else{
                    continue;
                }
                // 0が含まれてるなら終わり
                if(f){
                    cout << tmp << endl;
                    return 0;
                }
                if(a == b){
                    sousa = false;
                    break;
                }
                // bの書き換え
                for(ll j = 0; j < n; j++){
                    b[n - 1 - j] = a[j]; 
                }

                break;
            }
            if(!sousa){
                // おわり
                ll ans = -1;
                rep(i, n){
                    ans = max(ans, a[i]);
                }
                cout << ans << endl;
                return 0;
            }
        }else{
            // bでやる
            bool sousa = false;
            for(ll i = 0; i < n; i++){
                ll s = b[i];
                ll dis = lower_bound(b.begin(), b.end(), 2 * s) - b.begin();

                bool f = false;
                ll tmp = -1;
                if(dis >= n-1){
                    for(ll j = 0; j < n; j++){
                        b[j] = 2 * s - b[j];

                        tmp = max(tmp, b[j]);
                        if(b[j] == 0){
                            f = true;
                        }
                    }
                }else{
                    sousa = true;
                    continue;
                }
                // 0が含まれてるなら終わり
                if(f){
                    cout << tmp << endl;
                    return 0;
                }
                if(a == b){
                    sousa = false;
                    break;
                }
                // aの書き換え
                for(ll j = 0; j < n; j++){
                    a[n - 1 - j] = b[j]; 
                }
                break;
            }
            if(!sousa){
                // おわり
                ll ans = -1;
                rep(i, n){
                    ans = max(ans, b[i]);
                }
                cout << ans << endl;
                return 0;
            }
        }
        cnt++;
        vecdbg(a);
    }
    
    return 0;

    // for(ll i = 0; i < n; i++){
    //     ll s = a[i];
    //     ll dis = lower_bound(a.begin(), a.end(), 2 * s) - a.begin();
    //     if(dis >= n-1){
    //         cerr << "in " << i << endl;
    //         ll ans = -1;
    //         for(ll j = 0; j < n; j++){
    //             cerr << 2 * s - a[j] << endl;
    //             ans = max(ans, 2 * s - a[j]);
    //         }
    //         cout << ans << endl;
    //         return 0;
    //     }else{
            
    //     }
    // }

    // cout << a[n-1] << endl;


}