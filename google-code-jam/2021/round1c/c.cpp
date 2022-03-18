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

void solve(ll test_num){
    string s, t; cin >> s >> t;
    if(s.size() > 8){
        cout << "Case #" << test_num << ": " << 0 << endl;
    }else{
        map<ll, ll> mp;

        ll start = 0;
        for(ll i = 0; i < s.size(); i++){
            if(s[s.size() - 1 - i] == '1'){
                start += POW(2, i);
            }
        }
        ll goal = 0;
        for(ll i = 0; i < t.size(); i++){
            if(t[t.size() - 1 - i] == '1'){
                goal += POW(2, i);
            }
        }

        mp[start] = 1;
        queue<ll> que;
        que.push(start);
        while(!que.empty()){
            ll now = que.front();
            //cout << "now = " << now << endl;
            que.pop();

            ll twice = now * 2;
            //cout << "twice = " << twice << endl;
            if(twice < (1<<20)){
                if(mp.count(twice) == 0){
                    mp[twice] = mp[now] + 1;
                    que.push(twice);
                }
            }

            //ビット反転
            ll x = 0, tmp = now, cnt = 0;
            if(tmp == 0){
                x = 1;
            }else{
                while(tmp > 0){
                    if(!(tmp & 1)){
                        x += POW(2, cnt);
                    }
                    cnt++;
                    tmp >>= 1;
                }
            }
            //cout << "x = " << x << endl;
            if(mp.count(x) == 0){
                mp[x] = mp[now] + 1;
                que.push(x);
            }
        }

        if(mp[goal] == 0){
            cout << "Case #" << test_num + 1 << ": " << "IMPOSSIBLE" << endl;
        }else{
            cout << "Case #" << test_num + 1 << ": " << mp[goal] - 1 << endl;
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        solve(T);
    }

}