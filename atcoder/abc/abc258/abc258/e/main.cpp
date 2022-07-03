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
    ll n, q, x; cin >> n >> q >> x;
    vector<long long> w(2 * n);
    vector<ll> wsum(2 * n + 1);

    ll all_ = 0;
    for(long long i = 0; i < n; i ++){
        cin >> w[i];
        w[i + n] = w[i];
        all_ += w[i];
    }
    for(ll i = 0; i < 2*n; i++){
        wsum[i+1] = wsum[i] + w[i];
    }

    vector<ll> end_masu(n);
    vector<ll> kosu(n);

    ll tmp_ko = 0;
    ll nokori = x;

    if(all_ < x){
        ll syuki = x / all_;
        tmp_ko += n * syuki;
        // cerr << "tmp_ko" << " " << tmp_ko << endl;
        nokori = x - all_ * syuki;
    }

    // cerr << "nokori = " << nokori << endl;

    // vecdbg(w);
    // vecdbg(wsum);

    for(ll i = 0; i < n; i++){
        // start マスがiの時のend_masuとその時の個数を求める

        // nokoriはnokori
        ll nokoriX = nokori + wsum[i];
        ll dis = lower_bound(wsum.begin(), wsum.end(), nokoriX) - wsum.begin();
        ll e_masu = dis % n;
        // e_masuの1つ前のマスが終わり
        e_masu = (e_masu - 1 + n) % n;
        end_masu[i] = e_masu;
        kosu[i] = tmp_ko + (dis - i);

        // cerr << "i = " << i << " nokoriX = " << nokoriX << " dis = " << dis << " e_masu = " << e_masu << endl;
        

    }
    
    // cerr << "end_masu" << endl;
    // vecdbg(end_masu);
    // cerr << "kosu" << endl;
    // vecdbg(kosu);

    vector<vector<ll>> doubling(40, vector<ll>(n));
    rep(i, 40){
        rep(j, n){
            if(i == 0){
                doubling[i][j] = (end_masu[j] + 1) % n;
            }else{
                doubling[i][j] = doubling[i-1][doubling[i-1][j]];
            }
        }
    }

    // rep(i, n){
    //     cout << doubling[0][i] << " " << endl;
    //     cout << kosu[i] << endl;
    // }

    rep(i, q){
        ll k; cin >> k; k--;
        ll now = 0;

        ll cnt = 0;
        while(k > 0){
            if(k & 1){
                now = doubling[cnt][now];
            }
            cnt++;
            k = k >> 1;
        }

        // cout << "now = " << now << " " << kosu[now] << endl;
        cout << kosu[now] << endl;

    }



    
}