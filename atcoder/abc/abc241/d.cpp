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
    ll q; cin >> q;

    priority_queue<ll> que; //降順
    priority_queue<ll, vector<ll>, greater<ll>> que2; //昇順
    map<ll, ll> mp;
    vector<ll> query;
    rep(i, q){
        ll t; cin >> t;
        if(t == 1){
            ll x; cin >> x;
            que.push(x);
            que2.push(x);
            mp[x]++;
        }else if(t == 2){
            ll x, k; cin >> x >> k;
            auto itr = mp.upper_bound(x);
            if(itr == mp.begin()){
                cout << -1 << '\n'; continue;
            }
            itr--;
            
            //cout << itr->first << " " << itr-> second << endl;

            while(true){

                if(itr -> second >= k){
                    cout << itr->first << '\n'; break;
                }else{
                    k -= itr->second;
                    if(itr == mp.begin()){
                        cout << -1 << '\n'; break;
                    }
                    itr--;
                    /*
                    if(itr == mp.end()){
                        cout << -1 << '\n'; break;
                    }
                    */
                }
            }

        }else if(t == 3){
            ll x, k; cin >> x >> k;
            auto itr = mp.lower_bound(x);

            while(true){
                if(itr == mp.end()){
                    cout << -1 << '\n'; break;
                }
                if(itr ->second >= k){
                    cout << itr->first << '\n'; break;
                }else{
                    k -= itr->second;
                    itr++;
                    if(itr == mp.end()){
                        cout << -1 << '\n'; break;
                    }
                }
            }

        }
    }

}