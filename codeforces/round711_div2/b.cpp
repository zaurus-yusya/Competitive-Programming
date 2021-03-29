#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
        ll n, W; cin >> n >> W;
        vector<long long> w(n);

        vector<ll> vec(20);
        vector<ll> two(20);
        rep(i, 20){
            two[i] = POW(2, i);
        }

        for(long long i = 0; i < n; i ++){
            cin >> w[i];
            ll x = (ll)log2(w[i]);
            vec[x]++;
        }

        //vecdbg(vec);

        ll cnt = 0;
        ll ans = 0;
        while(cnt < n){
            ll now = W;
            for(ll i = 19; i >= 0; i--){
                if(vec[i] == 0){
                    continue;
                }else{
                    //ある
                    //cout << vec[i] << " " << two[i] << endl;
                    while(vec[i] > 0 && now > 0){

                        if(two[i] > now){
                            break;
                        }else{
                            now -= two[i];
                            vec[i]--;
                            cnt++;
                        }
                    }
                }
            }
            ans++; //段を増やす
        }
        cout << ans << endl;


        /*
        sort(all(w), greater<>());
        cout << ceilll(sum, W) << endl;
        */

    }
    
    


}