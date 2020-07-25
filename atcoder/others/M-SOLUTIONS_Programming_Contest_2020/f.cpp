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
using pld = pair<ld, ld>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(1);
    ll n; cin >> n;
    vector<ld> x(n); vector<ld> y(n);

    vector<pld> U;
    vector<pld> R;
    vector<pld> D;
    vector<pld> L;

    rep(i, n){
        ld a, b; char c; cin >> a >> b >> c;
        if(c == 'U'){
            U.emplace_back(a, b);
        }
        if(c == 'D'){
            D.emplace_back(a, b);
        } 
        if(c == 'R'){
            R.emplace_back(a, b);
        } 
        if(c == 'L'){
            L.emplace_back(a, b);
        }
    }

    ld ans = 10000000000;
    rep(i, U.size()){
        //D
        rep(j, D.size()){
            if(U[i].first == D[j].first && U[i].second <= D[j].second){
                ld tmp = (D[j].second - U[i].second) / 2; tmp = tmp * 10;
                ans = min(ans, tmp);
            }
        }
        //R
        rep(j, R.size()){
            if(U[i].first < R[j].first){
                continue;
            }else{
                ld tmp_x = R[j].first - U[i].first;
                ld tmp_y = R[j].second - U[i].second;
                if((tmp_x * -1) == tmp_y){
                    ld tmp = abs(tmp_x); tmp = tmp * 10;
                    ans = min(ans, tmp);
                }
            }
        }
        //L
        rep(j, L.size()){
            if(U[i].first > L[j].first){
                continue;
            }else{
                ld tmp_x = L[j].first - L[i].first;
                ld tmp_y = L[j].second - L[i].second;
                if((tmp_x * -1) == tmp_y){
                    ld tmp = abs(tmp_x); tmp = tmp * 10;
                    ans = min(ans, tmp);
                }
            }
        }
    }

    rep(i, D.size()){
        //R
        rep(j, R.size()){
            if(D[i].first < R[j].first){
                continue;
            }else{
                ld tmp_x = R[j].first - D[i].first;
                ld tmp_y = R[j].second - D[i].second;
                if((tmp_x * -1) == tmp_y){
                    ld tmp = abs(tmp_x); tmp = tmp * 10;
                    ans = min(ans, tmp);
                }
            }
        }
        //L
        rep(j, L.size()){
            if(D[i].first > L[j].first){
                continue;
            }else{
                ld tmp_x = L[j].first - D[i].first;
                ld tmp_y = L[j].second - D[i].second;
                if((tmp_x * -1) == tmp_y){
                    ld tmp = abs(tmp_x); tmp = tmp * 10;
                    ans = min(ans, tmp);
                }
            }
        }
    }

    rep(i, R.size()){
        rep(j, L.size()){
            if(R[i].second == L[j].second && R[i].first <= L[j].first){
                ld tmp = abs(L[j].first - R[i].first) / 2; tmp = tmp * 10;
                ans = min(ans, tmp);
            }
        }
    }

    if(ans == 10000000000){
        cout << "SAFE" << endl;
    }else{
        cout << ans << endl;
    }

}