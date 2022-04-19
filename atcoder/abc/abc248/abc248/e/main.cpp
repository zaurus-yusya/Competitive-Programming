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
// for(auto& i: mp) &&&&&&&&&&&&&

//dijkstra
struct Node
{
    ll x, y;
    Node(ll x = 0, ll y = 0) : x(x), y(y) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

struct Node2
{
    ll bunshi, bunbo, b;
    Node2(ll bunshi = 0, ll bunbo = 0, ll b = 0) : bunshi(bunshi), bunbo(bunbo), b(b) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<Node> vec(n);
    rep(i, n){
        ll x, y; cin >> x >> y;
        vec[i].x = x;
        vec[i].y = y;
    }

    if(n == 1){
        if(k == 1){
            cout << "Infinity" << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }
    if(k == 1){
        cout << "Infinity" << endl; return 0;
    }
    
    vector<ll> ncr(310);
    for(ll i = 1; i <= 300; i++){
        ncr[i] = (i) * (i-1) / 2;
    }

    map<P, ll> mp;
    //map<Node2, ll> mp2;
    map<pair<pair<ll, ll>, pair<ll, ll>>, ll> mp2;
    map<ll, ll> zero;
    map<ll, ll> yzero;

    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            ll bunshi = vec[j].y - vec[i].y; // yの増加量
            ll bunbo = vec[j].x - vec[i].x; // xの増加量
            //cerr << bunshi << " " << bunbo << endl;

            if(bunbo == 0){
                //cerr << "in" << endl;
                zero[vec[j].x]++;
            }else if(bunshi == 0){
                yzero[vec[j].y]++;
            }else{
                if(bunbo < 0){
                    bunshi *= -1;
                    bunbo *= -1;
                }

                ll x = gcd(bunshi, bunbo);
                bunshi = bunshi / x;
                bunbo = bunbo / x;

                mp[{bunshi, bunbo}]++;

                ll b = bunbo * vec[j].y - bunshi * vec[j].x;
                //Node2 tmp;
                pair<pair<ll, ll>, pair<ll, ll>> tmp;
                tmp.first.first = bunshi; tmp.first.second = bunbo; tmp.second.first = b; tmp.second.second = bunbo;
                //tmp.bunshi = bunshi; tmp.bunbo = bunbo; tmp.b = b;
                mp2[tmp]++;
            }
        }
    }

    ll ans = 0;
    cerr << "---" << endl;
    // for(auto& i: mp){
    //     ans += i.second / ncr[k];
    //     cerr << i.first.first << " " << i.first.second << " " << i.second << endl;
    // }
    for(auto& i: mp2){
        if(i.second >= ncr[k]){
            ans += 1;
        }
        // ans += i.second / ncr[k];
        // cerr << ans << endl;
        // cerr << i.first.first.first << " " << i.first.first.second << " " << i.first.second.first << " " << i.first.second.second << " " << i.second << endl;
    }
    cerr << "---" << endl;
    for(auto& i: zero){
        if(i.second >= ncr[k]){
            ans += 1;
        }
        //cerr << i.first <<  " " << i.second << endl;
    }
    cerr << "---" << endl;
    for(auto& i: yzero){
        if(i.second >= ncr[k]){
            ans += 1;
        }
        //cerr << i.first <<  " " << i.second << endl;
    }
    cerr << "---" << endl;

    cout << ans << endl;


}