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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<string>> vec(5, vector<string>(4*n+1));
    rep(i, 5){
        string s; cin >> s;
        rep(j, 4*n+1){
            vec[i][j] = s[j];
        }
    }
    
    for(ll i = 0; i < n; i++){
        ll x = (4*i+1), y = 0;
        ll count = 0;
        for(ll j = 0; j < 5; j++){
            for(ll k = x; k < x+3; k++){
                if(vec[j][k] == "#"){
                    count++;
                }
            }
        }

        if(count == 7){
            cout << "7";
        }else if(count == 8){
            cout << "1";
        }else if(count == 13){
            cout << "8";
        }else if(count == 11){
            if(vec[y+1][x] == "."){
                if(vec[y+3][x+2] == "."){
                    cout << "2";
                }else{
                    cout << "3";
                }
            }else{
                cout << "5";
            }
        }else if(count == 12){
            if(vec[y+2][x+1] == "."){
                cout << "0";
            }else{
                if(vec[y+3][x] == "."){
                    cout << "9";
                }else{
                    cout << "6";
                }
            }
        }else if(count == 9){
            cout << "4";
        }else{
            cout << "*";
        }
    }
    cout << endl;
    

}