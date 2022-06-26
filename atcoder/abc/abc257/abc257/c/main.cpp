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

ll calc(vector<ll> &kodomo, vector<ll> &otona, ll x){

    ll dis_k = lower_bound(kodomo.begin(), kodomo.end(), x) - kodomo.begin();
    ll tmp2 = dis_k;

    ll dis_o = lower_bound(otona.begin(), otona.end(), x) - otona.begin();
    ll tmp = otona.size() - dis_o;

    // cerr << x << " " << dis_o << " " << dis_k << " " << tmp << " " << tmp2 << endl;
    return tmp + tmp2;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;
    vector<long long> w(n);

    vector<ll> kodomo;
    vector<ll> otona;
    map<ll, ll> mp;
    for(long long i = 0; i < n; i ++){
        cin >> w[i];
        mp[w[i]]++;
        if(s[i] == '0'){
            kodomo.push_back(w[i]);
        }else{
            otona.push_back(w[i]);
        }
    }

    bool f = true;
    rep(i, n){
        if(s[i] == '1') f = false;
    }
    if(f){
        cout << n << endl; return 0;
    }

    f = true;
    rep(i, n){
        if(s[i] == '0') f = false;
    }
    if(f){
        cout << n << endl; return 0;
    }


    // 以上：大人　未満：子供
    
    sort(all(kodomo));
    
    sort(all(otona));

    // cerr << "kodomo" << endl;
    // vecdbg(kodomo);
    // cerr << "otona" << endl;
    // vecdbg(otona);

    ll ans = 0;

    for(auto &i: mp){
        ll x = i.first;

        for(ll j = x-1; j <= x+1; j++){
            ll res = calc(kodomo, otona, j);
            // cerr << j << " " << res << endl;
            ans = max(ans, res);
        }
    }

    cout << ans << endl; return 0;



    
    for(int i = 0; i < otona.size(); i++){
        ll x = otona[i];

        ll tmp = otona.size() - i;
        ll dis = upper_bound(kodomo.begin(), kodomo.end(), x) - kodomo.begin();

        ll tmp2 = kodomo.size() - dis;
        cerr << tmp << " " << tmp2 << endl;
        ans = max(ans, tmp + tmp2);
    }
    cout << ans << endl;



}