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
const long long INF = 1e10;
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> A(n+1);
    vector<long long> B(n+1);
    vector<long long> C(n+1, -1);
    vector<pair<ll, ll>> P(n+1);

    vector<pair<ll, ll>> OK(n+1);

    map<ll, ll> mp;
    for(long long i = 0; i < n; i ++){
        cin >> A[i+1] >> B[i+1];

        if(mp[A[i+1]] > 0 || mp[B[i+1]] > 0){
            cout << "No" << endl; return 0;
        }

        if(A[i+1] != -1){
            mp[A[i+1]] = (i+1);
        }else{
            A[i+1] = INF;
        }
        if(B[i+1] != -1){
            mp[B[i+1]] = (i+1);
        }else{
            B[i+1] = INF;  
        }

        if(A[i+1] != INF && B[i+1] != INF){
            C[i+1] = B[i+1] - A[i+1];
            OK.emplace_back(A[i+1], B[i+1]);
        }

        P[i+1] = make_pair(A[i+1], B[i+1]);
        
        
    }

    sort(all(P));
    sort(all(OK));
    rep(i, n+1){
        cout << P[i].first << " " << P[i].second << endl;
    }
    cout << "---" << endl;
    rep(i, (2*n) + 1){
        cout << mp[i] << endl;
    }
    cout << "---" << endl;
    rep(i, OK.size()){
        cout << OK[i].first << " " << OK[i].second << endl;
    }

    ll cnt = 0;
    for(ll i = 1; i < 2 * n + 1; i++){
        if(mp[i] > 0){
            continue;
        }else{
            for(ll j = i+1; j < n; j++){
                
            }
        }
    }



}