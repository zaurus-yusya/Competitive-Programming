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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s;
    cin >> s;

    vector<ll> tmp;
    map<string, ll> mp;
    rep(i, s.size()){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
            tmp.push_back(i);
        }
    }

    for(ll i = 0; i < tmp.size(); i+= 2){
        mp[s.substr(tmp[i], tmp[i+1]-tmp[i]+1)]++;
    }

    for(auto i: mp){
        string t = i.first;
        t[0] = t[0] - 32;
        t[t.size()-1] = t[t.size()-1] - 32;
        rep(j, i.second){
            cout << t;  //key, value
        }
    }
    cout << endl;


}