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
    ll n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }

    vector<vector<ll>> keta(10);
    rep(i, n){
        ll x = get_digit(a[i]);
        keta[x].push_back(a[i]);
    }

    rep(i, 10){
        sort(all(keta[i]), greater<ll>());
    }

    // for(ll i = 6; i >= 1; i--){
    //     cout << "keta: " << i << " :";
    //     rep(j, keta[i].size()){
    //         cout << keta[i][j] << " ";
    //     }br;
    // }

    vector<ll> keta_size(10);
    rep(i, 10){
        keta_size[i] = keta[i].size();
    }

    // vecdbg(keta_size);

    // 使う桁算出
    vector<ll> used(3);
    ll now = 0;
    for(ll i = 6; i >= 1; i--){
        while(keta_size[i] > 0){
            used[now] = i; now++;
            if(now == 3){
                break;
            }
            keta_size[i]--;
        }
        if(now == 3){
            break;
        }
    }

    map<ll, ll> used_mp;
    rep(i, 3){
        used_mp[used[i]]++;
    }

    // cerr << "used" << endl;
    // for(auto&i : used_mp){
    //     cerr << i.first << " " << i.second << endl;
    // }

    vector<string> st;
    for(ll i = 1; i <= 6; i++){
        rep(j, keta[i].size()){
            st.push_back(to_string(keta[i][j]));
        }
    }
    sort(all(st));
    reverse(all(st));

    string ans = "";
    rep(i, st.size()){
        ll x = st[i].size();
        if(used_mp[x] > 0){
            used_mp[x]--;
            ans += st[i];
        }
    }

    cout << ans << endl;

    // vecdbg(used);

}