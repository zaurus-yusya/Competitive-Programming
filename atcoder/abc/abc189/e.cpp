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



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    rep(i, n){
        cin >> x[i] >> y[i];
    }
    ll m; cin >> m;
    vector<pair<ll, ll>> op(m);
    //1 x -> y, y -> -x
    //2 x -> -y, y -> x
    //3 x -> x + (p-x)*2
    //4 y -> y + (p-y)*2
    vector<ll> hanten_num(m+1);

    vector<ll> xxx(m+1);
    vector<ll> yyy(m+1);
    xxx[0] = 1;
    yyy[0] = 1;
    vector<ll> xx(m+1);
    vector<ll> xx_sousa(m+1);
    vector<ll> yy(m+1);
    vector<ll> yy_sousa(m+1);
    ll hanten = 0;
    rep(i, m){
        ll o; cin >> o;

        if(o < 3){
            op[i] = {o, 0};

            hanten++;
            hanten_num[i+1] = hanten;

            if(o == 1){
                //sousa_x[i+1] *= -1;
                //sousa_y[i+1] *= 1;
                xxx[i+1] = x[i] * -1;
                yyy[i+1] = y[i];
            }else{
                //sousa_x[i+1] *= 1;
                //sousa_y[i+1] *= -1;
                xxx[i+1] = x[i];
                yyy[i+1] = y[i] * -1;
            }

        }else{
            ll p; cin >> p;
            op[i] = {o, p};

            hanten_num[i+1] = hanten;

            if(hanten_num[i] % 2 == 0){
                if(o == 3){
                    //x変更
                    //sousa_x[i+1] = sousa_x[i] + (p - now_x) * 2;
                    //sousa_y[i+1] *= 1;
                    xx[i+1] = xx[i] + p*2;
                    xx_sousa[i+1] = xx_sousa[i] + 1;
                    yy[i+1] = yy[i];
                    yy_sousa[i+1] = yy_sousa[i];
                }else{
                    //y変更
                    //sousa_x[i+1] *= sousa_x[i] + (p - now_x) * 2;
                    //sousa_y[i+1] *= 1;
                    yy[i+1] = yy[i] + p*2;
                    yy_sousa[i+1] = yy_sousa[i] + 1;
                    xx[i+1] = xx[i];
                    xx_sousa[i+1] = xx_sousa[i];
                }
            }else{
                if(o == 3){
                    //y変更
                    yy[i+1] = yy[i] + p*2;
                    yy_sousa[i+1] = yy_sousa[i] + 1;
                    xx[i+1] = xx[i];
                    xx_sousa[i+1] = xx_sousa[i];
                }else{
                    //x変更
                    xx[i+1] = xx[i] + p*2;
                    xx_sousa[i+1] = xx_sousa[i] + 1;
                    yy[i+1] = yy[i];
                    yy_sousa[i+1] = yy_sousa[i];
                }
            }
            
        }

    }

    

    
    


    ll q; cin >> q;
    rep(i, q){
        ll a, b; cin >> a >> b; b--;
        if(hanten_num[a] % 2 == 0){
            cout << xxx[a] * (x[b] + xx[a] - xx_sousa[a]*2*x[b]) << " " << yyy[a] * (y[b] + yy[a] - yy_sousa[a]*2*y[b]) << "\n";
        }else{
            cout << yyy[a] * (y[b] + yy[a] - yy_sousa[a]*2*y[b]) << " " << xxx[a] * (x[b] + xx[a] - xx_sousa[a]*2*x[b])<< "\n";
        }
    }

}