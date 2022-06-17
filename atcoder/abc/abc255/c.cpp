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
    ll x, a, d, n; cin >> x >> a >> d >> n;

    if(d < 0){
        x *= -1;
        a *= -1;
        d *= -1;
    }

    if(d == 0){
        cout << abs(x - a) << endl; return 0;
    }

    if(d > 0){
        ll mi = a;
        ll ma = a + d * n;

        ll ok = -1, ng = n;

        while(ng - ok > 1){
            // cerr << "ng = " << ng << " ok = " << ok << endl;
            ll mid = (ng + ok) / 2;
            ll num = a + d * mid;
            if(x > num){
                ok = mid;
            }else{
                ng = mid;
            }
            // cerr << "mid = " << mid << endl;
            // cerr << "ng = " << ng << " ok = " << ok << endl;
            //cerr << ng - ok << endl;
        }

        // cerr << "ok = " << ok << endl;

        if(ok == n-1){
            //cerr << "in " << endl;
            // cerr << x << " " << a + d * n << endl;
            cout << abs(x - (a + d * (n-1))) << endl;
        }else if(ok == -1){
            cout << abs(x - a) << endl;    
        }else{

            ll res = a + d * ok;
            ll res2 = a + d * (ok + 1);
            ll res3 = a + d * (ok - 1);

            ll ans = min(abs(x - res), abs(x - res2));
            if(ok != 0){
                ans = min(ans, abs(x - res3));
            }
            cout << ans << endl;
        }

    }else{
        ll mi = a + d * n;
        ll ma = a;

        ll ok = -1, ng = n;

        while(ng - ok > 1){
            ll mid = (ng + ok) / 2;
            ll num = a + d * mid;
            if(x < num){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        // cerr << ok << endl;

        if(ok == n-1){
            cout << abs(x - (a)) << endl;
        }else if(ok == -1){
            cout << abs(x - (a + d * n)) << endl;    
        }else{
            ll res = a + d * ok;
            ll res2 = a + d * (ok - 1);

            ll ans = min(abs(x - res), abs(x - res2));
            cout << ans << endl;
        }



    }

    return 0;


    ll fi = a;
    ll la = a + d * n;
    cerr << fi << " " << la << endl;

    ll mo = a % d;

    ll xmo = x % d;
    ll ans = min((mo - xmo), (mo + d - xmo));
    cout << ans << endl; return 0;
    // ll ans = abs(mo - xmo);


    // d % a の数
    // d * n - (d - a) = X
    ll kousu = ((d - a) + x) / n;
    cout << kousu << endl;
    cout << mo << endl;

}