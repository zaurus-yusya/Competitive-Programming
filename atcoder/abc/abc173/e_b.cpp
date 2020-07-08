#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long mod = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<long long> posi;
    vector<long long> nega;
    vector<long long> zen;
    for(long long i = 0; i < n; i ++){
        ll tmp; cin >> tmp;
        if(tmp < 0){
            nega.push_back(tmp);
            zen.push_back(tmp);
        }else{
            posi.push_back(tmp);
            zen.push_back(tmp);
        }
    }

    bool ok = false;
    //正にできるか
    if(posi.size() > 0){
        if(n == k && nega.size() % 2 == 1){
            ok = false;
        }else{
            ok = true;
        }
    }else{
        if(k % 2 == 1){
            ok = false;
        }else{
            ok = true;
        }
    }

    mint ans = 1;
    if(!ok){
        sort(zen.begin(), zen.end(), [](ll x, ll y){
            return abs(x) < abs(y);
        });
        for(ll i = 0; i < k; i++){
            ans *= zen[i];
            //ans = ( ((ans * zen[i]) % MOD) + MOD) % MOD;
        }
    }else{
        sort(posi.begin(), posi.end());
        sort(nega.rbegin(), nega.rend());
        if(k % 2 == 1){
            ans *= posi.back();
            //ans = (ans * posi.back()) % MOD;
            posi.pop_back();
        }
        vector<ll> ab;
        while(posi.size() >= 2){
            ll x = posi.back(); posi.pop_back();
            x *= posi.back(); posi.pop_back();
            //x = (x * posi.back()) % MOD; posi.pop_back();
            ab.push_back(x);
        }
        while(nega.size() >= 2){
            ll x = nega.back(); nega.pop_back();
            x *= nega.back(); nega.pop_back();
            //x = (x * nega.back()) % MOD; nega.pop_back();
            ab.push_back(x);
        }
        sort(ab.rbegin(), ab.rend());
        rep(i, k/2){
            ans *= ab[i];
        }

    }

    cout << ans << endl;

}