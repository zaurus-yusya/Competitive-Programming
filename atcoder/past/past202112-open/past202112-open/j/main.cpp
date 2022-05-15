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

ll n, q;

vector<vector<pair<ll, ll>>> tokei(vector<vector<pair<ll, ll>>> vec){
    vector<vector<pair<ll, ll>>> tmp;
    tmp = vec;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            vec[i][j] = tmp[n-1-j][i];
        }
    }
    return vec;
}
void tokeir(vector<vector<pair<ll, ll>>> &vec){
    vector<vector<pair<ll, ll>>> tmp;
    tmp = vec;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            vec[i][j] = tmp[j][n-1-i];
        }
    }
}
vector<vector<pair<ll, ll>>> jouge(vector<vector<pair<ll, ll>>> vec){
    vector<vector<pair<ll, ll>>> tmp;
    tmp = vec;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            vec[i][j] = tmp[n-1-i][j];
        }
    }
    return vec;
}
void sayuu(vector<vector<pair<ll, ll>>> &vec){
    vector<vector<pair<ll, ll>>> tmp;
    tmp = vec;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            vec[i][j] = tmp[i][n-1-j];
        }
    }
}

// jouge 0
// sayuu +2

// {0, 0} {0, 1} {0, 2}    {2, 0} {2, 1} {2, 2}
// {1, 0} {1, 1} {1, 2}    {1, 0} {1, 1} {1, 2}
// {2, 0} {2, 1} {2, 2}    {0, 0} {0, 1} {0, 2}

// {2, 0} {1, 0} {0, 0}    {0, 0} {1, 0} {2, 0}
// {2, 1} {1, 1} {0, 1}    {0, 1} {1, 1} {2, 1} 
// {2, 2} {1, 2} {0, 2}    {0, 2} {1, 2} {2, 2}

// {2, 2} {2, 1} {2, 0}    {0, 2} {0, 1} {0, 0}
// {1, 2} {1, 1} {1, 0}    {1, 2} {1, 1} {1, 0}
// {0, 2} {0, 1} {0, 0}    {2, 2} {2, 1} {2, 0}

// {0, 2} {1, 2} {2, 2}    {2, 2} {1, 2} {0, 2}
// {0, 1} {1, 1} {2, 1}    {2, 1} {1, 1} {0, 1}
// {0, 0} {1, 0} {2, 0}    {2, 0} {1, 0} {0, 0}

// tokei
// {2, 0} {1, 0} {0, 0}
// {2, 1} {1, 1} {0, 1}
// {2, 2} {1, 2} {0, 2}

// tokeir
// {0, 2} {1, 2} {2, 2}
// {0, 1} {1, 1} {2, 1}
// {0, 0} {1, 0} {2, 0}

// jouge
// {2, 0} {2, 1} {2, 2}
// {1, 0} {1, 1} {1, 2}
// {0, 0} {0, 1} {0, 2}

// sayuu
// {0, 2} {0, 1} {0, 0}
// {1, 2} {1, 1} {1, 0}
// {2, 2} {2, 1} {2, 0}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> q;
    vector<vector<pair<ll, ll>>> vec(n, vector<pair<ll, ll>>(n));
    vector<vector<ll>> res(n, vector<ll>(n));

    rep(i, n){
        rep(j, n){
            vec[i][j] = {i, j};
        }
    }
    vector<vector<vector<pair<ll, ll>>>> ans(8, vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>(n)));
    vector<vector<pair<ll, ll>>> vec0(n, vector<pair<ll, ll>>(n)); vec0 = vec;
    vector<vector<pair<ll, ll>>> vec1(n, vector<pair<ll, ll>>(n)); vec1 = tokei(vec0);
    vector<vector<pair<ll, ll>>> vec2(n, vector<pair<ll, ll>>(n)); vec2 = tokei(vec1);
    vector<vector<pair<ll, ll>>> vec3(n, vector<pair<ll, ll>>(n)); vec3 = tokei(vec2);
    vector<vector<pair<ll, ll>>> vec4(n, vector<pair<ll, ll>>(n)); vec4 = jouge(vec);
    vector<vector<pair<ll, ll>>> vec5(n, vector<pair<ll, ll>>(n)); vec5 = tokei(vec4);
    vector<vector<pair<ll, ll>>> vec6(n, vector<pair<ll, ll>>(n)); vec6 = tokei(vec5);
    vector<vector<pair<ll, ll>>> vec7(n, vector<pair<ll, ll>>(n)); vec7 = tokei(vec6);
    ans[0] = vec0; ans[1] = vec1; ans[2] = vec2; ans[3] = vec3;
    ans[4] = vec4; ans[5] = vec5; ans[6] = vec6; ans[7] = vec7;

    ll hanten = 0, kaiten = 0;
    rep(i, q){
        ll t; cin >> t;
        if(t == 1){
            ll y, x; cin >> y >> x; y--; x--;
            ll ind = hanten * 4 + kaiten;
            // ll Y = vec[y][x].first;
            // ll X = vec[y][x].second;
            ll Y = ans[ind][y][x].first;
            ll X = ans[ind][y][x].second;
            res[Y][X] = (res[Y][X] + 1) % 2;
        }
        if(t == 2){
            char c; cin >> c;
            if(c == 'A'){
                kaiten += 1; kaiten %= 4;
                // tokei(vec);
            }else{
                kaiten += 3; kaiten %= 4;
                // tokeir(vec);
            }
        }
        if(t == 3){
            char c; cin >> c;
            if(c == 'A'){
                if(hanten == 0){
                    if(kaiten % 2 == 0){
                        hanten = 1;
                    }else{
                        hanten = 1;
                        kaiten += 2; kaiten %= 4;
                    }
                }else{
                    if(kaiten % 2 == 0){
                        hanten = 0;
                    }else{
                        hanten = 0;
                        kaiten += 2; kaiten %= 4;
                    }
                }
                // jouge(vec);
            }else{
                if(hanten == 0){
                    if(kaiten % 2 == 1){
                        hanten = 1;
                    }else{
                        hanten = 1;
                        kaiten += 2; kaiten %= 4;
                    }
                }else{
                    if(kaiten % 2 == 1){
                        hanten = 0;
                    }else{
                        hanten = 0;
                        kaiten += 2; kaiten %= 4;
                    }
                }
                // sayuu(vec);
            }
        }
    }

    rep(i, n){
        rep(j, n){
            ll ind = hanten * 4 + kaiten;
            ll Y = ans[ind][i][j].first;
            ll X = ans[ind][i][j].second;
            if(res[Y][X] == 0){
                cout << 0;
            }else{
                cout << 1;
            }
        }br;
    }

}