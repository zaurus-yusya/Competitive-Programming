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
    ll L = 1; ll R = n;
    ll q = 0;

    if(n == 2){
        cout << "?" << " " << L << " " << R << endl;
        fflush(stdout);
        ll x; cin >> x;
        if(x == 1){
            cout << 2 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }

    cout << "?" << " " << L << " " << R << endl; q++;
    fflush(stdout);
    q++;
    ll sec; cin >> sec;

    //左を調べる
    ll lval = 0;
    if(sec != 1){
        cout << "?" << " " << 1 << " " << sec << endl; q++;
        fflush(stdout);
        cin >> lval;
    }

    if(lval == sec){
        R = sec;
        ll l = 1, r = sec-1;
        while(abs(r - l) > 1){
            ll mid = (l + r) / 2;
            cout << "?" << " " << mid << " " << R << endl; q++;
            fflush(stdout);
            ll x; cin >> x;
            if(x == sec){
                l = mid;
            }else{
                r = mid;
            }

        }

        
        if(l > r){
            swap(l, r);
        }
        
        if(r == R){
            cout << "!" << " " << l << endl;
            return 0;
        }
        cout << "?" << " " << r << " " << R << endl; q++;
        fflush(stdout);
        ll res; cin >> res;
        if(res == sec){
            cout << "!" << " " << r << endl;
        }else{
            cout << "!" << " " << l << endl;
        }


    }else{
        L = sec;
        ll l = sec+1, r = n;
        while(abs(r - l) > 1){
            ll mid = (l + r) / 2;
            cout << "?" << " " << L << " " << mid << endl; q++;
            fflush(stdout);
            ll x; cin >> x;
            if(x == sec){
                r = mid;
            }else{
                l = mid;
            }
        }
        
        if(l > r){
            swap(l, r);
        }
        
        if(L == l){
            cout << "!" << " " << r << endl;
            return 0;
        }
        cout << "?" << " " << L << " " << l << endl; q++;
        fflush(stdout);
        ll res; cin >> res;
        if(res == sec){
            cout << "!" << " " << l << endl;
        }else{
            cout << "!" << " " << r << endl;
        }
    }

    cout << q << endl;
}

