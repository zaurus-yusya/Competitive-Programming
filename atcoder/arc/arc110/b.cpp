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
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string t; cin >> t;
    vector<ll> X = {1, 1, 0};
    ll ans = 10000000000;
    ll ans2 = 0;
    if(n % 3 == 0){
        ans2 = n / 3;
    }else{
        ans2 = n / 3 + 1;
    }
    bool flag = true;

    //corner
    if(t == "1"){
        cout << 20000000000 << endl;
        return 0;
    }
    if(t == "0"){
        cout << 10000000000 << endl;
        return 0;
    }
    if(t == "11"){
        cout << 10000000000 << endl;
        return 0;
    }
    if(t == "10"){
        cout << 10000000000 << endl;
        return 0;
    }
    if(t == "01"){
        cout << 9999999999 << endl;
        return 0;
    }


    //110110
    ll cnt = 0;
    ll cnt2 = 0;
    for(ll i = 0; i < t.size(); i++){
        ll tmp = (ll)t[i] - 48;
        if(tmp == X[i % 3]){
            cnt ++;
            if(tmp == 0){
                cnt2++;
            }
        }else{
            flag = false;
            break;
        }
    }
    if(t[n-1] == '1') cnt2++;
    if(flag = true && cnt == n){
        /*
        cout << "0--" << endl;
        cout << cnt << endl;
        */
        //cout << ans - ans2 + 1 << endl;
        cout << ans - cnt2 + 1 << endl;
        return 0;
    }
    

    cnt = 0; flag = true, cnt2 = 0;
    //10110110
    for(ll i = 0; i < t.size(); i++){
        ll tmp = (ll)t[i] - 48;
        if(tmp == X[(i+1) % 3]){
            cnt++;
            if(tmp == 0){
                cnt2++;
            }
        }else{
            flag = false;
            break;
        }
    }
    if(t[n-1] == '1') cnt2++;
    if(flag = true && cnt == n){
        /*
        cout << "1--" << endl;
        cout << cnt << endl;
        */
        //cout << ans - ans2 + 1 << endl;
        cout << ans - cnt2 + 1 << endl;
        return 0;
    }

    cnt = 0; flag = true, cnt2 = 0;
    //0110110110
    for(ll i = 0; i < t.size(); i++){
        ll tmp = (ll)t[i] - 48;
        if(tmp == X[(i+2) % 3]){
            cnt ++;
            if(tmp == 0){
                cnt2++;
            }
        }else{
            flag = false;
            break;
        }
    }
    if(t[n-1] == '1') cnt2++;
    if(flag = true && cnt == n){
        //cout << ans - ans2 + 1 << endl;
        cout << ans - cnt2 + 1 << endl;
        return 0;
    }

    cout << 0 << endl;


    
    
    
}