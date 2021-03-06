#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll x, k, d; cin >> x >> k >> d;

    x = abs(x);
        if(x >= d){
            ll tmp = x / d;
            if(tmp > k){
                cout << x - (d * k) << endl;
                return 0;
            }

            k -= tmp;
            ll now = x - (d * tmp);
            if(k % 2 == 0){
                cout << abs(now) << endl;
            }else{
                if(now < 0){
                    cout << abs(now + d) << endl;
                }else{
                    cout << abs(now - d) << endl;
                }
            }
        }else{
            k -= 1;
            ll now = x - d;
            if(k % 2 == 0){
                cout << abs(now) << endl;
            }else{
                if(now < 0){
                    cout << abs(now + d) << endl;
                }else{
                    cout << abs(now - d) << endl;
                }
                
            }
        }

}