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
    ll n, p, q, r; cin >> n >> p >> q >> r;
    vector<long long> a(n);
    vector<ll> sum(n+1);
    map<ll, ll> mp;
    mp[0] = 0;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
        mp[sum[i+1]] = (i+1);
    }

    // [1, 3)
    //vecdbg(sum);
    for(ll x = 0; x < n+1; x++){
        if(mp.count(p + sum[x]) == 0){
            continue;
        }
        ll y = mp[p + sum[x]];

        if(mp.count(q + sum[y]) == 0){
            continue;
        }
        ll z = mp[q + sum[y]];

        if(mp.count(r + sum[z]) == 0){
            continue;
        }

        ll w = mp[r + sum[z]];

        cout << "Yes" << endl; return 0;

    }
    cout << "No" << endl;





    /*
    //vector<ll> a(n)で区間[left, right)の合計値がx以下になる区間の総和(しゃくとり)
    //O(2 * n)
    vector<ll> a(n);
    ll x = 0;
    ll res = 0; //答え
    
    ll right = 0;
    ll sum = 0; //合計値
    for(ll left = 0; left < n; left++){
        while(right < n && sum + a[right] <= x){
            sum += a[right];
            right++;
        }
    
        res += (right - left);
    
        if(right == left){
            right++;
        }else{
            sum -= a[left];
        }
    }
    
    cout << res << endl;
    */


}