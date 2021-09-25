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
        ll n, m; cin >> n >> m;
        vector<long long> s(m);

        

        for(long long i = 0; i < m; i ++){
            cin >> s[i];
        }
        vector<vector<ll>> p(n, vector<ll>(m));
        rep(i, n){
            rep(j, m){
                cin >> p[i][j];
            }
        }

        map<ll, ll> saisyo;
        rep(i, m){
            saisyo[s[i]]++;
        }

        ll ans = 0;

        map<ll, ll> now;

        rep(i, n){
            map<ll, ll> usesaisyo;
            map<ll, ll> usenow;
            
            queue<ll> henkan;
            rep(j, m){
                if(now.count(p[i][j]) > 0){
                    //nowにいた
                    now[p[i][j]]--;
                    if(now[p[i][j]] == 0) now.erase(p[i][j]);
                    usenow[p[i][j]]++;
                }else if(saisyo.count(p[i][j]) > 0){
                    //saisyoにいた
                    saisyo[p[i][j]]--;
                    if(saisyo[p[i][j]] == 0) saisyo.erase(p[i][j]);
                    usesaisyo[p[i][j]]++;
                }else{
                    //変換予定に挿入
                    henkan.push(p[i][j]);
                }
            }

            while(!henkan.empty()){
                ll x = henkan.front();
                //cout << "x = " << x << endl;
                henkan.pop();

                bool f = false;
                //saisyoで変換可能なら変換
                for(auto i: saisyo){
                    //cout << "x saisyo " << x << endl;
                    usenow[x]++;
                    saisyo[i.first]--;
                    if(saisyo[i.first] == 0) saisyo.erase(i.first);
                    f = true;
                    break;
                }
                
                if(f) continue;
                //nowで変換可能なら変換
                for(auto i: now){
                    //cout << "x now " << x << endl;
                    ans++;
                    usenow[x]++;
                    now[i.first]--;
                    if(now[i.first] == 0) now.erase(i.first);
                    break;
                }
            }

            //変数更新
            saisyo = usesaisyo;
            now = usenow;

            /*
            cout << i << endl;
            cout << "saisyo" << endl;
            for(auto i : saisyo){
                cout << i.first << " " << i.second << endl;
            }
            cout << "now" << endl;
            for(auto i : now){
                cout << i.first << " " << i.second << endl;
            }
            cout << "now ans = " << ans << endl;
            cout << "---" << endl;
            */
        }

        cout << "Case #" << T+1 << ": " << ans << endl;

        


    }

}