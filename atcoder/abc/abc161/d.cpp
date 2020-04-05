#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
//#define mp make_pair
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

map<ll,ll> mp;

void calc2(ll keta, ll num, string s){
    
    ll tmp = stol(s);
    mp[tmp]++;
    
    keta++;

    if(keta == 10){
        return;
    }

    if(num == 0){
        calc2(keta, 0, s + "0");
        calc2(keta, 1, s + "1");
    }else if(num == 9){
        calc2(keta, 8, s + "8");
        calc2(keta, 9, s + "9");
    }else{
        calc2(keta, num-1, s + to_string(num-1));
        calc2(keta, num, s + to_string(num));
        calc2(keta, num+1, s + to_string(num+1));
    }
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll K;
    cin >> K;

    ll keta = 0;

    calc2(0, 1, "1");
    calc2(0, 2, "2");
    calc2(0, 3, "3");
    calc2(0, 4, "4");
    calc2(0, 5, "5");
    calc2(0, 6, "6");
    calc2(0, 7, "7");
    calc2(0, 8, "8");
    calc2(0, 9, "9");

    ll count = 0;
    for(auto i: mp){
        count++;
        if(count == K){
            cout << i.first << endl;
            break;
        }
    }

}