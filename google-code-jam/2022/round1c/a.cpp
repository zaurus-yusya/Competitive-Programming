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

vector<ll> fi;
vector<ll> topo_sort(vector<vector<ll>> &g, vector<vector<ll>> &gr){
    vector<ll> res;
    ll n = g.size();
    vector<ll> ind(n);
    rep(i, n){
        for(auto next: g[i]){
            ind[next]++;
        }
    }
    queue<ll> que2;
    rep(i, n){
        if(ind[i] == 0){
            if(g[i].size() == 0 && gr[i].size() == 0){
                // cerr << i << endl;
                fi.push_back(i);
            }else{
                que2.push(i);
            }
        }
    }
    queue<ll> que;
    while(!que2.empty()){
        ll x = que2.front(); que2.pop();
        que.push(x);
        while(!que.empty()){
            ll now = que.front();
            que.pop();
            // if(g[now].size() == 0){
            //     fi.push_back(now); continue;
            // }
            res.push_back(now);
            for(auto next: g[now]){
                ind[next]--;
                if(ind[next] == 0){
                    que.push(next);
                }
            }
        }
    }
    return res;
    //res.size()がnだったらトポジカルソートできた(DAG)、nじゃなかったらDAGじゃない(閉路あり)
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<string> s(n);
        rep(i, n){
            cin >> s[i];
        }

        // 1文字のやつを他のやつにくっつけられるならくっつける
        rep(i, n){
            bool one = true; char x = s[i][0];
            rep(j, s[i].size()){
                if(s[i][j] != x) one = false;
            }
            if(one){
                for(ll j = 0; j < n; j++){
                    if(i == j) continue;
                    if(x == s[j][0]){
                        s[j] = s[i] + s[j];
                        s[i] = "-";
                        break;
                    }
                    if(x == s[j][s[j].size() - 1]){
                        s[j] = s[j] + s[i];
                        s[i] = "-";
                        break;
                    }
                }
            }
        }

        vector<string> ns;
        rep(i, n){
            if(s[i] != "-"){
                ns.push_back(s[i]);
            }
        }

        // vecdbg(ns);

        ll nn = ns.size();
        // グラフに辺を張る
        vector<vector<ll>> g(nn);
        vector<vector<ll>> gr(nn);
        for(ll i = 0; i < nn; i++){
            for(ll j = 0; j < nn; j++){
                if(i == j) continue;
                if(ns[i][ns[i].size() - 1] == ns[j][0]){
                    g[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }

        
        fi.clear();
        vector<ll> res = topo_sort(g, gr);


        if(res.size() + fi.size() != nn){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
        }else{
            //最終チェック
            string ans = "";
            rep(i, fi.size()){
                ans += ns[fi[i]];
            }
            rep(i, res.size()){
                ans += ns[res[i]];
            }

            map<char, ll> mp;
            char now = '.';
            bool f = true;
            rep(i, ans.size()){
                if(now != ans[i]){
                    if(mp.count(ans[i]) > 0){
                        f = false; break;
                    }else{
                        mp[ans[i]]++;
                    }
                    now = ans[i];
                }else{

                }
            }

            if(f){
                cout << "Case #" << T+1 << ": " << ans << '\n';
            }else{
                cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
            }

        }
        
    }

}