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

ll question(ll a, ll b, ll c){
    cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';
    cout.flush();
    ll x; cin >> x;
    return x;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        ll k = 0;
        vector<ll> vec(n, -1);

        // 0 : black, 1 : white
        ll bef, aft;
        bef = question(0, 1, 2);
        ll zero, one;
        for(ll i = 3; i <= n-3; i+=3){
            
            //bef = question(i, i+1, i+2);
            aft = question(i, i+1, i+2);

            if(bef != aft){
                ll bef2, aft2;
                //中二つ
                bef2 = question(i-2, i-1, i);
                aft2 =  question(i-1, i, i+1);

                if(bef2 == aft2){
                    if(bef == 0){
                        zero = i-3;
                        one = i+2;
                        k++;
                    }else{
                        zero = i+2;
                        one = i-3;
                        k++;
                    }
                    break;
                }else{
                    if(bef2 == 0){
                        vec[i-2] = 0;
                        vec[i+1] = 1;
                        zero = i-2;
                        one = i+1;
                        //中決める
                        ll x = question(i-2, i+1, i-1);
                        if(x == 0){
                            vec[i-1] = 0; vec[i] = 1;
                        }else{
                            vec[i-1] = 1; vec[i] = 0;
                        }
                        k+=2;
                        break;
                    }else{
                        vec[i-2] = 1;
                        vec[i+1] = 0;

                        zero = i-2;
                        one = i+1;
                        //中決める
                        ll x = question(i-2, i+1, i-1);
                        if(x == 0){
                            vec[i-1] = 0; vec[i] = 1;
                        }else{
                            vec[i-1] = 1; vec[i] = 0;
                        }
                        k+=2;
                        break;
                    }
                }
                
            }

            bef = aft;
        }

        rep(i, n){
            if(k >= n*2/3) break;
            if(vec[i] == -1){
                ll x = question(zero, one, i);
                if(x == 0){
                    vec[i] = 0;
                    k++;
                }else{
                    vec[i] = 1;
                }
            }
        }

        vector<ll> ans;
        rep(i, n){
            if(vec[i] == 0) ans.push_back(i+1);
        }
        cout << "! " << ans.size();
        rep(i, ans.size()){
            cout << ' ' << ans[i];
        }br;


    }

}