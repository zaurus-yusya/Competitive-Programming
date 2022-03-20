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
    map<ll, ll> mp;

    ll tmp = 0;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] == 1) tmp++;
    }
    mp[tmp]++;

    ll now = -1, cnt = 0;
    vector<ll> num;
    vector<ll> kosu;
    ll res = 0;

    rep(i, n){
        if(now != a[i]){
            num.push_back(now);
            kosu.push_back(cnt);

            now = a[i];
            cnt = 1;
            res += 1;
        }else{
            cnt++;
        }
    }

    /*
    if(res == 1){
        cout << n+1 << endl; return 0;
    }
 
    cout << n+1 - (res-2) << endl;
    */

    //cout << "tmp = " << tmp << endl;
    num.push_back(now);
    kosu.push_back(cnt);

    vector<ll> sum;
    vector<ll> sum2;
    sum.push_back(0);
    sum2.push_back(0);
    rep(i, num.size()){
        //cout << "num = " << num[i] << endl;
        if(num[i] == -1) continue;
        if(num[i] == 1){
            sum.push_back(sum[sum.size() - 1] - kosu[i]);
            sum2.push_back(sum2[sum2.size() - 1] + kosu[i]);
        }else{
            sum.push_back(sum[sum.size() - 1] + kosu[i]);
            sum2.push_back(sum2[sum2.size() - 1] - kosu[i]);
        }
    }
    // vecdbg(num);
    // vecdbg(kosu);
    vecdbg(sum);
    vecdbg(sum2);

    ll ma = tmp;
    rep(i, num.size()){
        
    }




}