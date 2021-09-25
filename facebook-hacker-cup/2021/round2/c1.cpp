#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll r, c, k; cin >> r >> c >> k; k--;
        vector<vector<char>> vec(r, vector<char>(c));
        rep(i, r){
            string s; cin >> s;
            rep(j, c){
                vec[i][j] = s[j];
            }
        }

        //vecvecdbg(vec);

        //縦に関してマス目の位置を記録
        vector<vector<ll>> tateichi(c);
        rep(j, c){
            rep(i, r){
                if(vec[i][j] == 'X'){
                    tateichi[j].push_back(i);
                }
            }
        }

        ll ans = INF;

        //x回上にやってから全消し
        for(ll x = 0; x < r - k + 1; x++){
            ll tmp = 0;
            tmp += x;
            //cout << "x = " << x << endl;
            rep(j, c){
                //xマス下が'X'だったらそのマスは'X'
                if((k + x < r) && (vec[k + x][j] == 'X')){
                    tmp += 1;
                    continue;
                }

                //二分探索
                ll dis = upper_bound(tateichi[j].begin(), tateichi[j].end(), k+x) - tateichi[j].begin();
                //cout << "j = " << j << " dis = " << dis << endl;
                if(dis > k){
                    tmp += 1;
                }
            }
            ans = min(ans, tmp);
            //cout << "x = " << x << " tmp = " << tmp << endl;
        }

        //x回下にやってから全消し
        for(ll x = 0; x < k+1+1; x++){
            ll tmp = 0;
            tmp += x;
            //cout << "x = " << x << endl;
            rep(j, c){
                //'X'マスが1つもないならcontinue
                if(tateichi[j].size() == 0) continue;
                //xマス上が'X'だったらそのマスは'X'
                if((k - x >= 0) && (vec[k - x][j] == 'X')){
                    tmp += 1;
                    continue;
                }

                //二分探索
                ll dis = lower_bound(tateichi[j].begin(), tateichi[j].end(), k-x) - tateichi[j].begin();
                //cout << "j = " << j << " dis = " << dis << " tateichi = " << tateichi[j].size() - dis <<endl;
                if(tateichi[j].size() - dis >= r-k){
                    tmp += 1;
                }
            }
            //cout << "x = " << x << " tmp = " << tmp << endl;
            ans = min(ans, tmp);
        }

        





        cout << "Case #" << T+1 << ": " << ans << endl;
    }

}