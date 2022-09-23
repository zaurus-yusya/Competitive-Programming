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
    ll n; cin >> n;

    ll q = 0;

    ll top = 0, bot = n-1;
    ll first = -1;
    while(true){
        ll mid = (top + bot) / 2;
        // cerr << mid+1 << endl;

        // 縦調べる
        cout << "?" << " " << top+1 << " " << mid+1 << " " << 1 << " " << n << endl;
        flush(std::cout);

        ll x; cin >> x;
        if(x == -1){
            return 0;
        }
        ll kazu = (mid - top) + 1;

        if(x == 0){
            first = mid;
            break;
        }

        if(kazu == x){
            // 下側の時
            top = mid+1;
        }else{
            bot = mid;
        }
        q++;
        if(q == 10){
            first = mid+1;
            break;
        }
    }

    // cout << first+1 << endl;

    // 横調べる
    ll left = 0, right = n-1;
    ll second = -1;
    ll qq = 0;
    while(true){
        ll mid = (left + right) / 2;

        // 横調べる
        cout << "?" << " " << 1 << " " << n << " " << left+1 << " " << mid+1 << endl;
        flush(std::cout);

        ll x; cin >> x;
        if(x == -1){
            return 0;
        }
        ll kazu = (mid - left) + 1;

        if(x == 0){
            second = mid;
            break;
        }

        if(kazu == x){
            // 右側の時
            left = mid+1;
        }else{
            right = mid;
        }


        qq++;
        if(qq == 10){
            second = mid+1;
            break;
        }
    }

    cout << "! " << first+1 << " " << second+1 << endl;


}