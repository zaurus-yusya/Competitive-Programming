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
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
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
        ll k, n, m; cin >> k >> n >> m;
        vector<long long> a(n);
        queue<ll> quea;
        for(long long i = 0; i < n; i ++){
            cin >> a[i];
            quea.push(a[i]);
        }
        vector<long long> b(m);
        queue<ll> queb;
        for(long long i = 0; i < m; i ++){
            cin >> b[i];
            queb.push(b[i]);
        }
        vector<ll> ans;
        bool flag = true;
        rep(i, n+m){
            if(quea.empty()){
                ll y = queb.front();
                if(y == 0){
                    ans.push_back(y); k++;
                    queb.pop();
                }else{
                    if(k < y){
                        flag = false;
                        break;
                    }else{
                        ans.push_back(y);
                        queb.pop();
                    }
                }
                continue;
            }
            if(queb.empty()){
                ll x = quea.front();
                if(x == 0){
                    ans.push_back(x); k++;
                    quea.pop();
                }else{
                    if(k < x){
                        flag = false;
                        break;
                    }else{
                        ans.push_back(x);
                        quea.pop();
                    }
                }
                continue;
            }
            
            ll x = quea.front();
            ll y = queb.front();

            if(x == 0){
                ans.push_back(0); k++;
                quea.pop();
                continue;
            }
            if(y == 0){
                ans.push_back(0); k++;
                queb.pop();
                continue;
            }

            if(x > y){
                if(k < y){
                    flag = false; break;
                }else{
                    ans.push_back(y);
                    queb.pop();
                }
            }else if(x < y){
                if(k < x){
                    flag = false; break;
                }else{
                    ans.push_back(x);
                    quea.pop();
                }
            }else{
                if(k < x){
                    flag = false; break;
                }else{
                    ans.push_back(x);
                    quea.pop();
                }
            }

        }

        if(flag){
            rep(i, n+m){
                cout << ans[i] << " ";
            }br;
        }else{
            cout << -1 << endl;
        }




    }

}