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

map<P, ll> mp;
vector<P> res;
vector<P> ans;
void calc(ll y, ll x, ll r, ll c, ll cnt){
    //cout << "in " << y << " " << x << " " << cnt<< endl;
    
    if(cnt == r * c){
        ans = res;
        return;
    }

    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){

            if(i == y){
                //cout << "a" << i << " " << j << " " << y << " " << x << endl;
                break;
            }
            if(j == x){
                //cout << "a" << i << " " << j << " " << y << " " << x << endl;
                continue;
            }
            if(i - j == y - x){
                //cout << "a" << i << " " << j << " " << y << " " << x << endl;
                continue;
            }
            if(i + j == y + x){
                //cout << "a" << i << " " << j << " " << y << " " << x << endl;
                continue;
            }

            if(mp[{i, j}] > 0) continue;
            //go
            res.push_back({i, j});
            mp[{y, x}]++;
            calc(i, j, r, c, cnt+1);
            mp[{y, x}]--;
            res.pop_back();

            if(ans.size() == r * c) break;
        }
        if(ans.size() == r * c) break;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll r, c; cin >> r >> c;

        if(r > 5 || c > 5){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
            continue;
        }

        bool f = false;
        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                mp.clear();
                res.clear();
                ans.clear();

                //cout << "start " << i << j << endl;
                res.push_back({i, j});
                calc(i, j, r, c, 1);

                if(ans.size() == r * c){
                    f = true;
                    break;
                }
            }

            if(f) break;
        }



        if(ans.size() == 0){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
        }else{
            cout << "Case #" << T+1 << ": " << "POSSIBLE" << '\n';
            rep(i, ans.size()){
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
            }
        }

    }

}