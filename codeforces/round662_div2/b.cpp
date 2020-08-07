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

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    map<ll, ll> mp;
    for(long long i = 0; i < n; i ++){
        ll a; cin >> a;
        mp[a] ++;
    }

    ll two_num = 0, four_num = 0;
    for(auto i: mp){
        if(i.second >= 4){
            four_num += 1;
            two_num += (i.second / 2);
        }else if(i.second >= 2){
            two_num += 1;
        }
    }


    ll q; cin >> q;
    rep(i, q){
        string s; ll x;
        cin >> s >> x;
        if(s == "+"){
            ll tmp = mp[x];
            if(tmp == 3){
                four_num ++;    
            }
            if(tmp % 2 == 1){
                two_num ++;
            }
            mp[x]++;
        }else{
            ll tmp = mp[x];
            if(tmp == 4){
                four_num--;
            }
            if(tmp % 2 == 0){
                two_num--;
            }
            mp[x]--;
        }

        if(four_num >= 1){
            ll tmp_two = two_num - 2;
            if(tmp_two >= 2){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }

    }

}