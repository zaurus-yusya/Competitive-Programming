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

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_int_distribution<int> distr(0, 7);

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;

    vector<map<string, ll>> vec(10);
    vec[0]["00000000"] = 1;
    vec[8]["11111111"] = 1;
    
    for(ll i = 1; i <= 7; i++){
        vector<ll> tmp = {0,1,2,3,4,5,6,7};
        do{
            string x = "00000000";
            for(ll j = 0; j < tmp.size(); j++){
                if(tmp[j] < i){
                    x[j] = '1';
                }
            }
            vec[i][x]++;
        }while(next_permutation(tmp.begin(), tmp.end()));
    }
    vector<vector<string>> res(10);
    for(ll i = 0; i <= 8; i++){
        for(auto&j: vec[i]){
            res[i].push_back(j.first);
        }
    }

    // for(ll i = 0; i < res[2].size(); i++){
    //     cout << res[2][i] << endl;
    // }



    rep(T, t){
        ll x = 1;
        cout << 10000000 << endl;
        flush(std::cout);
        ll turn = 0;
        while(true){
            cin >> x;
            if(x == 0){
                break;
            }else if(x == -1){
                return 0;
            }else{
                // string s = "00000000";
                string s = res[x][( (T+turn) % res[x].size())];
                // rep(i, x){
                //     s[i] = '1';
                // }
                
                ll x = distr(eng);
                // string t = "00000000";
                // rep(i, 8){
                //     t[i] = s[(i+x)%8];
                // }
                // cerr << t << endl;
                // cout << t << endl;
                // cerr << s << endl;
                cout << s << endl;
                flush(std::cout);
            }
            turn++;
        }
    }

}