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

ll n, k;
vector<ll> vec;
map<ll, ll> mp;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> k;
    vec.resize(n);
    rep(i, n){
        cin >> vec[i];
    }
    sort(all(vec));

    for(ll i = 0; i < (1<<n); i++){
        vector<ll> num;
        for(ll j = 0; j < n; j++){
            if(i & (1<<j)){
                num.push_back(vec[j]);
            }
        }

        if(num.size() != k) continue;

        do{
            ll res = 0;
            for(ll i = 0; i < num.size(); i++){
                //cout << num[i] << " ";
                ll keta = get_digit(num[i]);
                rep(j, keta){
                    res *= 10;
                }
                res += num[i];
            }
            mp[res]++;
        }while(next_permutation(num.begin(), num.end()));

    }

    cout << mp.size() << endl;



}