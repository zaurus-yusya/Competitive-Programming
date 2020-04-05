#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)
// コンパイル　g++ -std=c++17 a.cpp

int main() {
    
    ll n;
    cin >> n;
    vector<ll> vec(n);
    vector<ll> vec2(n);
    rep(i,n){
        cin >> vec.at(i);
    }




    /*
    rep(i,n-1){
        ll tmp = 0;
        tmp = vec.at(i) | vec.at(i+1);
        tmp -= vec.at(i+1);
        vec.at(i+1) = tmp;
        cout << vec.at(i+1) << endl;
    }


    cout << vec.at(n-1) << endl;
    */
    
    sort(all(vec),greater<ll>());

    rep(i,n){
        cout << vec.at(i) << " ";
    }
    cout << endl;



}