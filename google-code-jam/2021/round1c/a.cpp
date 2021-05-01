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

ld solve1(ll n, ll k, vector<ll> &p){
    ld ans = 0;

    for(ll i = 1; i <= k; i++){

        for(ll j = i; j <= k; j++){

            //cout << i << " " << j << endl;

            ll cnt = 0;
            for(ll c = 1; c <= k; c++){
                bool flag = true;
                ll idis = abs(c - i);
                ll jdis = abs(c - j);

                for(ll x = 0; x < n; x++){
                    if(abs(c - p[x]) <= idis && abs(c - p[x]) <= jdis){
                        flag = false;
                    }
                }

                if(flag){
                    cnt++;
                }
            }

            ld tmp = (ld)cnt / (ld)k;

            ans = max(ans, tmp);

        }

    }

    return ans;
}

ld solve2(ll n, ll k, vector<ll> &p){
    ld ans = 0;
    map<ll, ll> mp;
    rep(i, n){
        mp[p[i]]++;
    }

    vector<ll> x;
    for(auto i: mp){
        //cout << i.first << " " << i.second << endl;
        x.push_back(i.first);
    }

    //vecdbg(x);

    for(ll i = 0; i < x.size() + 1; i++){
        for(ll j = i; j < x.size() + 1; j++){

            ll cnt = 0;
            //cout << i << " " << j << endl;

            if(i == j){
                if(i == 0){
                    cnt = x[i] - 1;
                }else if(i == x.size()){
                    cnt = k - x[x.size() - 1];
                }else{
                    cnt += x[i] - x[i-1] - 1;
                }
            }else{
                //iの計算
                if(i == 0){
                    cnt += x[i] - 1;
                }else if(i == x.size()){
                    cnt += k - x[x.size() - 1];
                }else{
                    cnt += (x[i] - x[i-1]) / 2;
                }

                //jの計算
                if(j == 0){
                    cnt += x[j] - 1;
                }else if(j == x.size()){
                    cnt += k - x[x.size() - 1];
                }else{
                    cnt += (x[j] - x[j-1]) / 2;
                }
            }

            ld tmp = (ld)cnt / (ld)k;
            //cout << "i= " << i << " j= " << j << " cnt= " << cnt << " tmp= " << tmp << endl; 
            ans = max(ans, tmp);



        }
    }



    return ans;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, k; cin >> n >> k;
        vector<long long> p(n);
        for(long long i = 0; i < n; i ++){
            cin >> p[i];
        }

        ld ans = 0;
        if(k > 30){
            ans = solve2(n, k, p);
        }else{
            ans = solve2(n, k, p);
        }

        cout << "Case #" << T+1 << ": " << ans << endl;
    }

}