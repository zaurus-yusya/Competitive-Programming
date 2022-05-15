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
const long long INF = 8e18 + 1;
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
ll n;
vector<ll> seen;
vector<pair<ll, ll>> res;
vector<pair<ll, ll>> ANS;
bool f = false;

map<ll, ll> assigned;
void dfs(vector<pair<ll, ll>> &zero_distance, ll ind, vector<vector<ll>> &distance){
    if(ind == n){
        if(res.size() == n){
            f = true;
            ANS = res;
            return;
        }
    }

    ll next_assign_child = zero_distance[ind].second;

    ll tmp_dis = INF;
    ll assign_sweet = -1;

    vector<ll> assign;
    for(ll j = 0; j < distance.size(); j++){
        if(seen[j] == 1) continue;

        if(tmp_dis > distance[next_assign_child][j]){
            tmp_dis = distance[next_assign_child][j];
            assign.clear();
            assign.push_back(j);
        }else{
            assign.push_back(j);
        }
    }

    if(f) return;

    if(assign.size() == 1 && assign[0] == 0){
        return;
    }

    rep(i, assign.size()){
        if(assign[i] == 0){
            continue;
        }else{
            cerr << next_assign_child << " " <<  assign[i] << endl;
            res.push_back({next_assign_child, assign[i]});
            seen[assign[i]] = 1;
            dfs(zero_distance, ind+1, distance);
            res.pop_back();
            seen[assign[i]] = 0;
        }

        if(f) return;
    }

    if(f) return;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        cin >> n;
        ANS.clear();
        if(n > 10){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
            continue;
        }
        vector<pair<ll, ll>> child(n);
        vector<pair<ll, ll>> sweet(n+1);
        rep(i, n){
            ll x, y; cin >> x >> y;
            child[i] = {x, y};
        }
        rep(i, n+1){
            ll x, y; cin >> x >> y;
            sweet[i] = {x, y};
        }

        vector<vector<ll>> distance(n, vector<ll>(n+1)); // i : child, j: sweet
        rep(i, n){
            rep(j, n+1){
                distance[i][j] = abs(child[i].first - sweet[j].first) * abs(child[i].first - sweet[j].first) + abs(child[i].second - sweet[j].second) * abs(child[i].second - sweet[j].second);
            }
        }

        vector<pair<ll, ll>> zero_distance(n);
        rep(i, n){
            zero_distance[i] = {distance[i][0], i};
        }
        sort(all(zero_distance));

        // zero_distance順にアサインする
        seen.assign(15, 0);
        f = false;
        dfs(zero_distance, 0, distance);

        if(ANS.size() == n){
            cout << "Case #" << T+1 << ": " << "POSSIBLE" << '\n';
            rep(i, ANS.size()){
                cout << ANS[i].first + 1 << " " << ANS[i].second + 1 << '\n';
            }
        }else{
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
            cerr << ANS.size() << endl;
        }


    }





}