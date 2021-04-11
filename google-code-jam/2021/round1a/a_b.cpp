#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
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
__int128 POW2(__int128 a, __int128 n){ __int128 res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
cpp_int POW3(cpp_int a, cpp_int n){ cpp_int res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
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

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

string to_string128(__int128 x){
  string res = "";
  while(x > 0){
    res += (x % 10) + '0';
    x /= 10;
  }
  reverse(all(res));
  return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<cpp_int> x(n);
        for(long long i = 0; i < n; i ++){
            // string s; cin >> s;
            // cpp_int tmp = parse(s);
            // x[i] = tmp;
            cin >> x[i];
        }


        ll ans = 0;
        for(ll i = 1; i < n; i ++){

            if(x[i] > x[i-1]){
                continue;
            }else if(x[i] == x[i-1]){
                x[i] = x[i]*10;
                ans += 1;
                continue;
            }

            // ll maeketa = to_string128(x[i-1]).size();
            // ll atoketa = to_string128(x[i]).size();
            ll maeketa = x[i-1].str().size();
            ll atoketa = x[i].str().size();

            if(maeketa < atoketa){
                continue;
            }else if(maeketa == atoketa){
                // add 0
                x[i] = x[i]*10;
                ans += 1;
            }else{
                // maeketa > atoketa
                string bef = x[i-1].str();
                string aft = x[i].str();
                ll flag = 0; // 0同じ　1大 2小
                for(ll j = 0; j < atoketa; j++){

                    if(bef[j] == aft[j]){
                        continue;
                    }else if((bef[j] - '0') < (aft[j] - '0')){
                        flag = 1; break;
                    }else{
                        flag = 2; break;
                    }
                }

                if(flag == 0){
                    //cerr << "flag = 0 " << endl;
                    bool nine = true;
                    for(ll j = atoketa; j < maeketa; j++){
                        //cerr << bef[j] << endl;
                        if(bef[j] != '9'){
                            nine = false; break;
                        }
                    }
                    //後ろ全部9だったらダメ
                    //全部9じゃなかったら+1
                    if(nine){
                        x[i] = x[i] * POW3(10, (maeketa - atoketa + 1));
                        ans += (maeketa - atoketa + 1);
                    }else{
                        x[i] = x[i-1] + 1;
                        ans += (maeketa - atoketa);
                        //cerr << "in" << endl;
                    }
                }else if(flag == 1){
                    x[i] = x[i] * POW3(10, (maeketa - atoketa));
                    ans += (maeketa - atoketa);
                }else{
                    // cout << x[i] << endl;
                    // cout << POW2(10, (maeketa - atoketa + 1)) << endl;
                    x[i] = x[i] * POW3(10, (maeketa - atoketa + 1));
                    
                    ans += (maeketa - atoketa + 1);
                }
                
            }

        }

        vecdbg(x);


        cout << "Case #" << (T+1) << ": " << ans << endl;

    }

}