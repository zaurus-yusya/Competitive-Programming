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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        string a, s; cin >> a >> s;
        ll nowa = a.size() - 1;
        ll nows = s.size() - 1;

        bool f = true;
        string b = "";
        while(true){
            ll numa = a[nowa] - '0';
            ll nums = s[nows] - '0';

            if(nows < 0){
                f = false; break;
            }

            //cout << "numa = " << numa   << " nums = " << nums << endl;

            ll tmp = 0;
            for(ll j = 0; j <= 9; j++){
                if((numa + j) % 10 == nums){
                    tmp = j; break;
                }
            }

            //cout << "tmp = " << tmp << endl;

            if(numa + tmp < 10){
                b = b + (char)(tmp + '0');
                nowa--;
                nows--;
            }else{
                if(nows == 0){
                    f = false; break;
                }else if(s[nows - 1] != '1'){
                    f = false; break;
                }else{
                    b = b + (char)(tmp + '0');
                    nowa--;
                    nows -= 2;
                }
            }

            //cout << "nowa = " << nowa  << " nows = " << nows<< endl;
            
            if(nowa == -1){
                while(nows >= 0){
                    b = b + (char)(s[nows]);
                    nows--;
                }
                break;
            }
        }

        if(f){
            reverse(all(b));
            bool ff = true;
            for(ll i = 0; i < b.size(); i++){
                if(b[i] == '0' && ff){
                    continue;
                }else{
                    ff = false;
                    cout << b[i];
                }
                
            }br;

            //cout << b << endl;
        }else{
            cout << -1 << endl;
        }

    }

}