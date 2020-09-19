#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
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
    ll n, x, m; cin >> n >> x >> m;
    map<ll ,ll> mp;
    vector<ll> vec;

    ll amari;
    ll flag = -1;
    rep(i, n){
        
        if(i == 0){
            amari = x % m;
            vec.push_back(amari);
            mp[amari]++;
        }else{
            amari = (amari * amari) % m;
            
            if(mp[amari] >= 1){
                flag = amari;
                break;
            }
            vec.push_back(amari);
            mp[amari]++;
        }

        if(amari == 0){
            break;
        }
        
    }

    ll size = vec.size();
    ll ans = 0;

    if(flag != -1){
        ll ind;
        ll syuki_mae = 0;
        ll syuki = 0;
        bool syuki_flag = false;
        rep(i, vec.size()){
            if(vec[i] == flag){
                ind = i;
                syuki_flag = true;
            }
            if(syuki_flag){
                syuki += vec[i];
            }else{
                syuki_mae += vec[i];
            }
        }

        ans += syuki_mae;

        n = n - ind;
        ll syuki_size = vec.size() - 1 - ind + 1;
        ll syuki_num = n / syuki_size;
        ll syuki_amari = n % syuki_size;

        ans += syuki_num * syuki;

        for(ll i = ind; i < ind + syuki_amari; i++){
            //cout << "a " << ind << " " << syuki_amari << endl;
            ans += vec[i];
        }

        /*
        cout << "ind " << ind << endl; 
        cout << "flag " << flag << endl; 
        cout << "syuki_size " << syuki_size << endl;
        cout << "vec_size " << vec.size() << endl;
        */

    }else{
        //cout << "no" << endl;
        rep(i, vec.size()){
            ans += vec[i];
        }
    
    }
    

    cout << ans << endl;
    //cout << flag << endl;

}