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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b; cin >> a >> b; a--;
    ll keta_a = 0, keta_b = 0;
    string s = to_string(a), t = to_string(b);

    ll tmp_a = a;
    while(true){
        keta_a ++;
        if(tmp_a / 10 == 0){
            break;
        }
        tmp_a /= 10;
    }
    ll tmp_b = b;
    while(true){
        keta_b ++;
        if(tmp_b / 10 == 0){
            break;
        }
        tmp_b /= 10;
    }


    ll dp_a[keta_a + 1][2][2];
    ll dp_b[keta_b + 1][2][2];

    rep(i, keta_a+1){
        rep(j, 2){
            rep(k, 2){
                dp_a[i][j][k] = 0;
            }
        }
    }
    rep(i, keta_b+1){
        rep(j, 2){
            rep(k, 2){
                dp_b[i][j][k] = 0;
            }
        }
    }

    dp_a[0][0][0] = 1;
    dp_b[0][0][0] = 1;

    for(ll i = 0; i < keta_a; i++){
        ll tmp = s[i] - '0';
        for(ll j = 0; j < 2; j++){
            for(ll k = 0; k < 2; k ++){
                for(ll d = 0; d <= (j ? 9 : tmp); d++){
                    dp_a[i+1][j || d < tmp][k || d == 4 || d == 9] += dp_a[i][j][k];
                }
            }
        }
    }

    for(ll i = 0; i < keta_b; i++){
        ll tmp = t[i] - '0';
        for(ll j = 0; j < 2; j++){
            for(ll k = 0; k < 2; k ++){
                for(ll d = 0; d <= (j ? 9 : tmp); d++){
                    dp_b[i+1][j || d < tmp][k || d == 4 || d == 9] += dp_b[i][j][k];
                }
            }
        }
    }

    cout << (dp_b[keta_b][0][1] + dp_b[keta_b][1][1]) - (dp_a[keta_a][0][1] + dp_a[keta_a][1][1]) << endl;

}