#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

ll dpa[100010][2][2];
ll dpb[100010][2][2];

int main() {
    std::cout << std::fixed << std::setprecision(15);

    ll x, y; cin >> x >> y; x--;
    string a = to_string(x);
    string b = to_string(y);
    ll ketaa = a.size(), ketab = b.size();

    //hinagata
    dpa[0][0][0] = 1;
    for(ll i = 0; i < ketaa; i++){
        ll num = a[i] - '0'; //stringの数値を文字列型
        for(ll smaller = 0; smaller < 2; smaller++){ //smaller: 未満フラグ
            for(ll k = 0; k < 2; k++){
                for(ll j = 0; j <= (smaller ? 9 : num); j++){
                    dpa[i+1][smaller || (j < num)][k || (j == 4) || (j == 9)] += dpa[i][smaller][k];
                }
            } 
        }
    }

    dpb[0][0][0] = 1;
    for(ll i = 0; i < ketab; i++){
        ll num = b[i] - '0'; //stringの数値を文字列型
        for(ll smaller = 0; smaller < 2; smaller++){ //smaller: 未満フラグ
            for(ll k = 0; k < 2; k++){
                for(ll j = 0; j <= (smaller ? 9 : num); j++){
                    dpb[i+1][smaller || (j < num)][k || (j == 4) || (j == 9)] += dpb[i][smaller][k];
                }
            } 
        }
    }

    cout << dpb[ketab][0][1] + dpb[ketab][1][1] - dpa[ketaa][0][1] - dpa[ketaa][1][1] << endl;

}