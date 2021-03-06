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
    ll n; cin >> n;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }
    sort(all(vec));
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            for(ll k = j+1; k < n; k++){
                if(vec[i] + vec[j] > vec[k] && vec[j] + vec[k] > vec[i] && vec[k] + vec[i] > vec[j]){
                    if(vec[i] != vec[j] && vec[j] != vec[k] && vec[k] != vec[i]){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;


}