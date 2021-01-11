#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
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
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    vector<ll> b(n);
    map<ll, ll> ima_nimotsu;
    map<ll, ll> nimotsu_basyo;
    rep(i, n){
        cin >> a[i].first; 
        a[i].second = i;
    } 
    rep(i, n){
        cin >> b[i];
    }
    rep(i, n){
        ll x; cin >> x; x--;
        ima_nimotsu[i] += x;
        nimotsu_basyo[x] += i;
    }

    vector<ll> omosa = b;
    sort(all(omosa), greater<ll>());

    //cout << "---" << endl;
    for(auto i: ima_nimotsu){
        //cout << "hito " << i.first << " nimotsu " << i.second << endl;
        if(a[i.first].first <= b[i.second] && i.first != i.second){
            cout << -1 << endl;
            return 0;
        }
    }

    sort(all(a));

    /*
    cout << "---" << endl;
    for(auto i: nimotsu_basyo){
         cout << "nimotsu " << i.first << " hito " << i.second << endl;
    }
    */

    
    ll ans = 0;
    vector<pair<ll, ll>> res;
    rep(i, n){
        //cout << a[i].first << " " << a[i].second << endl;
        if(a[i].second == ima_nimotsu[a[i].second]) continue;
        ll from_hito = a[i].second;
        ll to_hito = nimotsu_basyo[a[i].second];
        ll after_nimotsu = ima_nimotsu[a[i].second];
        //cout << from_hito << " " << to_hito << " " << after_nimotsu << endl;
        ima_nimotsu[a[i].second] = a[i].second;
        nimotsu_basyo[a[i].second] = a[i].second;
        ima_nimotsu[to_hito] = after_nimotsu;
        nimotsu_basyo[after_nimotsu] = to_hito;
        ans++;
        res.push_back({from_hito+1, to_hito+1});

    }
    cout << ans << endl;
    rep(i, ans){
        cout << res[i].first << " " << res[i].second << "\n";
    }
    


    

}