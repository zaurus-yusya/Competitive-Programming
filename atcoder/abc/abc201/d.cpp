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
const long long INF = 1e18;
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
    ll h, w; cin >> h >> w;
    vector<vector<ll>> vec(h, vector<ll>(w));

    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            if(s[j] == '-'){
                vec[i][j] = -1;
            }else{
                vec[i][j] = 1;
            }
        }
    }

    //コーナー
    ////////////////////////
    if(h == 1 && w == 1){
        cout << "Draw" << endl; return 0;
    }

    if(h == 1 && w > 1){
        ll taka = 0, aoki = 0;
        rep(j, w){
            if(j == 0) continue;
            if(j % 2 == 1){
                taka += vec[0][j];
            }else{
                aoki += vec[0][j];
            }
        }
        if(taka > aoki){
            cout << "Takahashi" << endl;
        }else if(taka == aoki){
            cout << "Draw" << endl;
        }else{
            cout << "Aoki" << endl;
        }
        return 0;
    }

    if(h > 1 && w == 1){
        ll taka = 0, aoki = 0;
        rep(i, h){
            if(i == 0) continue;
            if(i % 2 == 1){
                taka += vec[i][0];
            }else{
                aoki += vec[i][0];
            }
        }
        if(taka > aoki){
            cout << "Takahashi" << endl;
        }else if(taka == aoki){
            cout << "Draw" << endl;
        }else{
            cout << "Aoki" << endl;
        }
        return 0;
    }
    //////////////////////



    ll taka = 0;
    ll aoki = vec[h-1][w-1];

    vector<vector<pair<ll, ll>>> res(h, vector<pair<ll, ll>>(w));

    ll cnt = 0;
    if((h-1+w-1) % 2 == 0){
        res[h-1][w-1] = {0, vec[h-1][w-1]};
    }else{
        res[h-1][w-1] = {vec[h-1][w-1], 0};
        cnt = 1;
    }
    
    //横
    for(ll j = w-2; j >= 0; j--){
        if(cnt % 2 == 0){
            res[h-1][j] = {res[h-1][j+1].first + vec[h-1][j], res[h-1][j+1].second};
        }else{
            res[h-1][j] = {res[h-1][j+1].first, res[h-1][j+1].second + vec[h-1][j]};
        }
        cnt++;
    }
    cnt = 0;
    if((h-1+w-1) % 2 == 1){
        cnt = 1;
    }
    
    //縦
    for(ll i = h-2; i >= 0; i--){
        if(cnt % 2 == 0){
            res[i][w-1] = {res[i+1][w-1].first + vec[i][w-1], res[i+1][w-1].second};
        }else{
            res[i][w-1] = {res[i+1][w-1].first, res[i+1][w-1].second + vec[i][w-1]};
        }
        cnt++;
    }

    for(ll i = h-2; i >= 0; i--){
        for(ll j = w-2; j >= 0; j--){

            if((i+j) % 2 == 0){
                //たかはし良い方 //あおきにたす
                //右
                ll migi = res[i][j+1].first - res[i][j+1].second;
                //下
                ll sita = res[i+1][j].first - res[i+1][j].second;

                if(migi > sita){
                    res[i][j].first = res[i][j+1].first;
                    res[i][j].second = res[i][j+1].second + vec[i][j];
                }else{
                    res[i][j].first = res[i+1][j].first;
                    res[i][j].second = res[i+1][j].second + vec[i][j];
                }

            }else{
                //あおき良い方 //たかはしにたす
                //右
                ll migi = res[i][j+1].first - res[i][j+1].second;
                //下
                ll sita = res[i+1][j].first - res[i+1][j].second;

                if(migi > sita){
                    res[i][j].first = res[i+1][j].first + vec[i][j];
                    res[i][j].second = res[i+1][j].second;
                }else{
                    res[i][j].first = res[i][j+1].first + vec[i][j];
                    res[i][j].second = res[i][j+1].second;
                }
            }
        }
    }
    /*
    rep(i, h){
        rep(j, w){
            cout << "{";
            cout << res[i][j].first << " " << res[i][j].second;
            cout << "} ";
        }br;
    }
    */
    

    ll migisa = res[0][1].first - res[0][1].second;
    ll sitasa = res[1][0].first - res[1][0].second;
    if(migisa > 0 || sitasa > 0){
        cout << "Takahashi" << endl;
    }else if(migisa == 0 || sitasa == 0){
        cout << "Draw" << endl;
    }else{
        cout << "Aoki" << endl;
    }

}