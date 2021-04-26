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
        ll A, B, C; cin >> A >> B >> C;
        //a -= a; b -= a; c -= a;
        ll a = A, b = B, c = C;
        ll h = 0, m = 0, s = 0, n = 0;
        
        ll H = 0, M = 0, S = 0, N = 0;

        ll now = 0;
        while(a >= 0){
            vector<ll> vec = {a, b, c};
            // cout << "para " << a << " " << b << " " << c << endl;
            do{ 
                /*
                for(ll i = 0; i < 3; i++){
                    cout << vec[i] << " ";
                }
                cout << endl;
                */
                //時間
                ll z = POW(10, 9);
                h = vec[0] / (z * 3600);
                ll hm = (vec[0] % (z * 3600) ) / (60 * POW(10, 9));
                ll hs = ( (vec[0] % (z * 3600) ) % (60 * POW(10, 9)) ) / POW(10, 9);
                ll hns = ( (vec[0] % (z * 3600) ) % (60 * POW(10, 9)) ) % POW(10, 9);
                //分
                ll y = 12 * POW(10, 9);
                m = vec[1] / (y * 60);
                ll ms = ( vec[1] % (y * 60) ) / (12 * POW(10, 9));
                ll mns = ( vec[1] % (y * 60) ) % (12 * POW(10, 9));
                //秒
                ll x = 720 * POW(10, 9);
                s = vec[2] / x;
                //ナノ秒
                ll ns = vec[2] % x;

                if(hm == m && hs == s && ms == s && hns == mns && mns == ns){
                    H = h; M = m; S = s; N = n;
                    // cout << "in " << endl;
                    // cout << h << " " << m << " " << s << endl;
                }

            }while(next_permutation(vec.begin(), vec.end()));

            a -= 720 * POW(10, 9);
            b -= 720 * POW(10, 9);
            c -= 720 * POW(10, 9);
        }

        a = A, b = B, c = C;
        while(c <= 720 * POW(10, 9) * 3600 * 12){
            vector<ll> vec = {a, b, c};
            // cout << "para " << a << " " << b << " " << c << endl;
            do{ 
                /*
                for(ll i = 0; i < 3; i++){
                    cout << vec[i] << " ";
                }
                cout << endl;
                */
                //時間
                ll z = POW(10, 9);
                h = vec[0] / (z * 3600);
                ll hm = (vec[0] % (z * 3600) ) / (60 * POW(10, 9));
                ll hs = ( (vec[0] % (z * 3600) ) % (60 * POW(10, 9)) ) / POW(10, 9);
                ll hns = ( (vec[0] % (z * 3600) ) % (60 * POW(10, 9)) ) % POW(10, 9);
                //分
                ll y = 12 * POW(10, 9);
                m = vec[1] / (y * 60);
                ll ms = ( vec[1] % (y * 60) ) / (12 * POW(10, 9));
                ll mns = ( vec[1] % (y * 60) ) % (12 * POW(10, 9));
                //秒
                ll x = 720 * POW(10, 9);
                s = vec[2] / x;
                //ナノ秒
                ll ns = vec[2] % x;

                if(hm == m && hs == s && ms == s && hns == mns && mns == ns){
                    H = h; M = m; S = s; N = n;
                    // cout << "in " << endl;
                    // cout << h << " " << m << " " << s << endl;
                }

            }while(next_permutation(vec.begin(), vec.end()));

            a += 720 * POW(10, 9);
            b += 720 * POW(10, 9);
            c += 720 * POW(10, 9);
        }
        
        /*
        map<ll, ll> mp;

        // 1秒6度
        //秒を指定
        ll x = 720 * POW(10, 9);
        rep(i, 3){
            if(vec[i] % x == 0){
                //秒にする
                mp[i]++;
                s = vec[i] / x;
            }
        }

        //分を指定
        ll y = 12 * POW(10, 9);
        rep(i, 3){
            if(mp[i] > 0) continue;
            if(vec[i] % y == 0){
                //分にする
                mp[i]++;
                m = vec[i] / y / 60;
            }
        }

        //時間を指定
        ll z = POW(10, 9);
        rep(i, 3){
            if(mp[i] > 0) continue;
            if(vec[i] % z == 0){
                //時間にする
                mp[i]++;
                h = vec[i] / z / 3600;
            }
        }
        */

        /*
        cout << "--" << endl;
        cout << a / x <<  " " << b / x << " " << c / x << endl;
        cout << a % x <<  " " << b % x << " " << c % x << endl;
        cout << "--" << endl;
        cout << a / y <<  " " << b / y << " " << c / y << endl;
        cout << a % y <<  " " << b % y << " " << c % y << endl;
        */

        cout << "Case #" << T+1 << ": " << H << " " << M << " " << S << " " << N << endl;

    }

}