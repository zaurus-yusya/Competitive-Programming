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
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
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
    ll n, k;
    cin >> n >> k;

    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i]; vec[i]--;
    }

    //2 1 3 0
    //0->2->3->0->2->3
    //1->1->1->
    vector<vector<ll>> dabu(66, vector<ll>(n));
    for(ll i = 0; i <= 65; i++){
        if(i == 0){
            for(ll j = 0; j < n; j ++){
                dabu[i][j] = vec[j];
            }
        }else{
            for(ll j = 0; j < n; j ++){
                dabu[i][j] = dabu[i-1][dabu[i-1][j]];
            }
        }
    }

    ll cnt = 0, now = 0;
    while(k > 0){
        if(k & 1){
            now = dabu[cnt][now];
        }
        k = (k >> 1);
        cnt++;
    }
    cout << now + 1 << endl;

    /*
    ll count = 1;

    vector<ll> ans;
    ans.push_back(0);
    map<ll,ll> mp;

    ll tmp = 0;
    count = 0;
    mp[0] = 0;
    while(true){
        if(mp.count(vec[tmp]) != 0){
            count++;
            break;
        }else{
            count++;
            tmp = vec[tmp];
            ans.push_back(tmp);
            mp[tmp] = count;
        }
    }

    ll mod = count - mp[vec[tmp]];

    k -= mp[vec[tmp]];
    if(k < 0){
        k += mp[vec[tmp]];
        cout << ans[k] + 1 << endl;
    }else{
        ll tmp2 = k % mod;
        cout << ans[tmp2 + mp[vec[tmp]]] + 1 << endl;
    }
    */
    

}