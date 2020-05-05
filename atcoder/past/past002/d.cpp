#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

string s;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    
    cin >> s;
    map<string,ll> mp;


    if(s.size() == 1){
        mp["."]++;
    }else if(s.size() == 2){
        mp["."]++;
        mp[".."]++;
    }else if(s.size() >= 3){
        mp["."]++;
        mp[".."]++;
        mp["..."]++;
    }

    string tmp = ".";
    for(ll i = 0; i < s.size(); i++){
        mp[s.substr(i,1)]++;
    }
    if(s.size() >= 2){
        for(ll i = 0; i < s.size() - 1; i++){
            mp[s.substr(i,2)]++;
            mp[tmp + s.substr(i+1,1)]++;
            mp[s.substr(i,1) + tmp]++;
        }
    }
    
    if(s.size() >= 3){
        for(ll i = 0; i < s.size() - 2; i++){
            mp[s.substr(i,3)]++;

            mp[tmp + s.substr(i+1,2)]++;
            mp[s.substr(i,1) + tmp + s.substr(i+2,1)]++;
            mp[s.substr(i,2) + tmp]++;

            mp[tmp + tmp + s.substr(i+2,1)]++;
            mp[tmp + s.substr(i+1,1) + tmp]++;
            mp[s.substr(i,1) + tmp + tmp]++;
        }
    }
    

    cout << mp.size() << endl;

}