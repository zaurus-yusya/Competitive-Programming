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
    ll n, m, k; cin >> n >> m >> k;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(all(a), greater<ll>());

    vector<ll> pow2(31);
    rep(i, 31){
        pow2[i] = POW(2, i);
    }
    //vecdbg(pow2);
    //return 0;


    // 最上位からk個andとれるか
    ll ok = 0, ng = POW(2, 31);

    ll syoki = POW(2, 30) - 1;
    rep(i, k){
        syoki = (syoki & a[i]);
    }
    // cerr << "syoki = " << syoki << endl;
    // ok = syoki;

    // TODO: ok=0じゃなくて適当にk箇所選んだ&の方がいいかも
    vector<ll> vec(n); // 回数入れる
    while((ng - ok) > 1){
        

        ll mid = (ok + ng) / 2;
        // cerr << "mid = " << mid << endl;

        rep(i, n){
            // 初めてmidが1なのに0のところで切る
            bool f = true;
            ll num = 0;
            for(ll j = 30; j >= 0; j--){
                // midのビットが1
                if((pow2[j] & mid) > 0 && (pow2[j] & a[i]) == 0){
                    // 初めてmidが1なのに0
                    num = j;
                    f = false;
                    break;
                }
            }

            if(f){
                vec[i] = 0;
            }else{
                // cerr << "num = " << num << endl;
                ll mid_ = 0;
                ll a_ = 0;
                for(ll j = num; j >= 0; j--){
                    if((pow2[j] & mid) > 0){
                        mid_ += pow2[j];
                    }
                    if((pow2[j] & a[i]) > 0){
                        a_ += pow2[j];
                    }
                }
                vec[i] = mid_ - a_;
            }
        }

        sort(all(vec));

        // vecdbg(vec);
        // K個取る
        ll kaisu = 0;
        for(ll j = 0; j < k; j++){
            kaisu += vec[j];
        }

        // cerr << "kaisu = " << kaisu << endl;
        if(kaisu <= m){
            // cerr << "ok" << endl;
            ok = mid;
        }else{
            // cerr << "ng" << endl;
            ng = mid;
        }

    }
    cout << ok << endl;

}