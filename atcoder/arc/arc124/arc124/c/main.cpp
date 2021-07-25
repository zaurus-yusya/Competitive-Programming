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
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
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

int main() {
    std::cout << std::fixed << std::setprecision(15);

    ll n; cin >> n;
    vector<ll> amae;
    vector<ll> bmae;

    vector<ll> aato;
    vector<ll> bato;
    for(ll i = 0; i < n/2; i++){
        ll a, b; cin >> a >> b;
        amae.push_back(a); bmae.push_back(b);
    }
    for(ll i = n/2; i < n; i++){
        ll a, b; cin >> a >> b;
        aato.push_back(a); bato.push_back(b);
    }

    map<pair<ll, ll>, ll> mp;

    vector<pair<ll, ll>> mae;
    for(ll i = 0; i < (1 << amae.size()); i++){
        map<ll, ll> tmp;

        ll agcd = 0, bgcd = 0; // a RED b BLUE
        for(ll j = 0; j < amae.size(); j++){
            if((i >> j) & 1){
                tmp[j]++;
                agcd = gcd(agcd, amae[j]);
                bgcd = gcd(bgcd, bmae[j]); //
            }else{
                agcd = gcd(agcd, bmae[j]); //
                bgcd = gcd(bgcd, amae[j]); //
            }
        }
        /*
        ll agcd = 0, bgcd = 0; // a RED b BLUE
        for(ll j = 0; j < amae.size(); j++){
            if(tmp[j] != 0){
                agcd = gcd(agcd, amae[j]);
                bgcd = gcd(bgcd, bmae[j]); //
            }else{
                agcd = gcd(agcd, bmae[j]); //
                bgcd = gcd(bgcd, amae[j]); //
            }
        }
        */
        if(mp[{agcd, bgcd}] == 0){
            mae.push_back({agcd, bgcd});
            mp[{agcd, bgcd}]++;
        }
    }

    mp.clear();

    vector<pair<ll, ll>> ato;
    for(ll i = 0; i < (1 << aato.size()); i++){
        map<ll, ll> tmp;
        ll agcd = 0, bgcd = 0;
        for(ll j = 0; j < aato.size(); j++){
            if((i >> j) & 1){
                tmp[j]++;
                agcd = gcd(agcd, aato[j]);
                bgcd = gcd(bgcd, bato[j]); //
            }else{
                agcd = gcd(agcd, bato[j]); //
                bgcd = gcd(bgcd, aato[j]); //
            }
        }
        /*
        ll agcd = 0, bgcd = 0;
        for(ll j = 0; j < aato.size(); j++){
            if(tmp[j] != 0){
                agcd = gcd(agcd, aato[j]);
                bgcd = gcd(bgcd, bato[j]); //
            }else{
                agcd = gcd(agcd, bato[j]); //
                bgcd = gcd(bgcd, aato[j]); //
            }
        }
        */
        if(mp[{agcd, bgcd}] == 0){
            ato.push_back({agcd, bgcd});
            mp[{agcd, bgcd}]++;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < mae.size(); i++){
        for(ll j = 0; j < ato.size(); j++){
            ll rgcd = gcd(mae[i].first, ato[j].first);
            ll bgcd = gcd(mae[i].second, ato[j].second);
            //cout << "gcdgcd " << rgcd << " " << bgcd << endl;
            ans = max(ans, lcm(rgcd, bgcd));
        }
    }

    cout << ans << endl;
    /*
    rep(i, mae.size()){
        cout << mae[i].first << " " << mae[i].second << endl;
    }
    cout << "---" << endl;
    rep(i, ato.size()){
        cout << ato[i].first << " " << ato[i].second << endl;
    }
    */
    
}