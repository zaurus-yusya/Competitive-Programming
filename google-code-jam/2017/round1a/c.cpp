#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
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
        ll HD, AD, HK, AK, B, D; cin >> HD >> AD >> HK >> AK >> B >> D;
        // buff debuff 全探索
        ll ans = INF;
        for(ll buff = 0; buff <= 100; buff++){
            for(ll debuff = 0; debuff <= 100; debuff++){
                ll hd = HD, ad = AD, hk = HK, ak = AK, b = B, d = D; 
                ll cnt = 0;
                ll bufftime = buff;
                ll debufftime = debuff;
                // debuff -> buff -> attack
                bool f = true;
                bool cure = false;
                while(hk > 0){
                    cnt++;
                    //cerr << "hd = " << hd << " hk = " << hk << " ad = " << ad << " ak = " << ak << endl;
                    // 次の攻撃で倒せるか
                    if(hk - ad <= 0){
                        hk -= ad;
                        cure = false;
                    }else if(hd - ak <= 0){ // 次の攻撃で死ぬか
                        // debufftimeが残っていて かつ debuffすれば生き残るか
                        if(debufftime > 0 && hd - (ak - d) > 0){
                            ak -= d;
                            if(ak < 0) ak = 0;
                            debufftime--;

                            cure = false;
                        }else{
                            if(cure){
                                f = false; break;
                            }
                            hd = HD; // CURE
                            cure = true;
                        }
                    }else{
                        if(debufftime > 0){ //debuff終わっているか
                            ak -= d;
                            if(ak < 0) ak = 0;
                            debufftime--;
                        }else if(bufftime > 0){ //buff終わっているか
                            ad += b;
                            bufftime--;
                        }else{
                            hk -= ad;
                        }
                        cure = false;
                    }

                    if(hk <= 0){
                        break;
                    }
                    // knight attacked
                    hd -= ak;

                    if(hd <= 0){
                        f = false; break;
                    }
                }

                if(f){
                    //cerr << "bu " << buff << " de " << debuff << " cnt " << cnt << endl; 
                    ans = min(ans, cnt);
                }
            }
        }

        if(ans == INF){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
        }else{
            cout << "Case #" << T+1 << ": " << ans << '\n';
        }
    }

}