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
const long long MOD = 1e9+7;
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

//vector<ll> vec;

// void calc(string s, ll now, ll sub, ll nowketa, ll keta){

//     s += (char)(now + '0');
//     num++;

//     if(num == keta){
//         ll x = stoll(s);
//         vec.push_back(x);
//         return;
//     }else{
//         ll next = now + sub;
//         if(0 <= next && 9 <= next){

//         }
//     }
// }

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll x; cin >> x;

    map<ll, ll> mp;

    for(ll sub = -9; sub <= 9; sub++){
    //for(ll sub = 0; sub <= 2; sub++){

        for(ll i = 1; i <= 9; i++){
            ll x = i;
            ll num = i;
            //mp[x]++;
            while(0 <= num && num <= 9){
                mp[x]++;
                num += sub;
                x = x * 10 + num;
                if(x > 1e18) break;
            }

        }

    }
    //cout << mp.size() << endl;
    vector<ll> vec;
    for(auto& i : mp){
        //cout << i.first << " " << i.second << endl;
        vec.push_back(i.first);
    }
    
    sort(all(vec));

    ll dis = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    cout << vec[dis] << endl;

    

    // for(ll keta = 1; keta < 17; keta++){

    //     for(ll i = 1; i <= 9; i++){ //first

    //         for(ll j = -9; j <= 9; j++){
    //             calc(S, i, j, 0, keta);
    //         }

    //     }
        

    // }
}