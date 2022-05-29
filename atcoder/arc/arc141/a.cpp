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
    ll t; cin >> t;
    rep(T, t){ // 10^4
        string s; cin >> s;
        ll n = stoll(s);
        ll keta = get_digit(n);

        ll ans = -1;
        // i = 1のとき別でやる
        for(ll i = 1; i <= (s[0] - '0'); i++){
            string tmp = "";
            char c = i + '0';
            for(ll j = 0; j < keta; j++){
                tmp += c;
            }
            ll res = stoll(tmp);
            if(res <= n){
                ans = max(res, ans);
            }
        }

        // 9999999
        string tmp = "";
        for(ll i = 0; i < keta-1; i++){
            tmp += '9';
        }
        ll res = stoll(tmp);
        ans = max(ans, res);


        //周期の候補はketaの約数
        
        for(ll i = 2; i < keta; i++){
            if(keta % i != 0) continue;

            ll syuki = i;
            ll times = keta / i;

            // cerr << "syuki = " << syuki << endl;
            //はじめの数字
            string tmp = "";
            for(ll j = 0; j < syuki; j++){
                tmp += s[j];
            }
            // cerr << "tmp = " << tmp << endl;

            ll fi = stoll(tmp);

            string res = "";
            for(ll j = 0; j < times; j++){
                res += tmp;
            }
            // cerr << "res = " << res << endl;

            ll res_ll = stoll(res);
            if(res_ll <= n){
                ans = max(ans, res_ll);
            }else{
                ll minasu = fi - 1;
                if(get_digit(fi) == get_digit(minasu)){
                    string res2 = "";
                    string ad = to_string(minasu);
                    for(ll j = 0; j < times; j++){
                        res2 += ad;
                    }
                    ll res2_ll = stoll(res2);

                    ans = max(ans, res2_ll);
                }
            }

        }

        cout << ans << '\n';

    }

}