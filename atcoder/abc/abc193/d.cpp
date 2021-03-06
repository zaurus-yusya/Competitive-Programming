#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
    ll k; cin >> k;
    string s, t; cin >> s >> t;


    vector<ll> taka(10); // 0~9 : 1~9
    vector<ll> aoki(10);

    map<ll, ll> nokori;
    rep(i, 9) nokori[i+1] = k;

    rep(i, 4){
        ll x = s[i] - '0';
        ll y = t[i] - '0';
        nokori[x] -= 1;
        nokori[y] -= 1;
    }

    //dbg
    /*
    for(auto i : nokori){
        cout << i.first << " " << i.second << endl;
    }
    */

    //taka計算
    for(ll i = 1; i <= 9; i++){
        if(nokori[i] == 0) continue;

        map<ll, ll> mp;
        mp[i]++;
        for(ll j = 0; j < 4; j++){
            ll x = s[j] - '0';
            mp[x]++;
        }
        ll res = 0;
        for(ll j = 1; j <= 9; j++){
            res += j * POW(10, mp[j]);
        }
        taka[i] = res;
    }
    //aoki計算
    for(ll i = 1; i <= 9; i++){
        if(nokori[i] == 0) continue;

        map<ll, ll> mp;
        mp[i]++;
        for(ll j = 0; j < 4; j++){
            ll x = t[j] - '0';
            mp[x]++;
        }
        ll res = 0;
        for(ll j = 1; j <= 9; j++){
            res += j * POW(10, mp[j]);
        }
        aoki[i] = res;
    }

    //dbg
    //vecdbg(taka);
    //vecdbg(aoki);

    ll card_num = (k*9) - 8; //残りのカードの枚数
    ld ans = 0;
    //takaが引くカード
    for(ll i = 1; i <= 9; i++){
        if(nokori[i] == 0) continue;
        ld taka_kaku = (ld)nokori[i] / (ld)card_num;
        nokori[i] -= 1;

            //aokiの引くカード
            for(ll j = 1; j <= 9; j++){
                if(nokori[j] == 0) continue;

                ld aoki_kaku = (ld)nokori[j] / ((ld)card_num - (ld)1);
                if(taka[i] > aoki[j]){
                    //takaの勝ち
                    //cout << "in " << i << " " << j << endl;
                    ans += taka_kaku * aoki_kaku;
                }
            }

        nokori[i] += 1;
    }

    cout << ans << endl;

}