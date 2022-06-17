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

ll n;
vector<ll> P;
vector<ll> I;
map<ll, ll> mpP;
map<ll, ll> mpI;
vector<pair<ll, ll>> ans;


void calc(ll P_l, ll P_r, ll I_l, ll I_r){ // [l, r) PとIの部分木の左端と右端
    try{
        ll P_root_node = P.at(P_l);
        ll I_root_index = mpI.at(P_root_node);

        if(P_r - P_l == 1){
            ans.at(P_root_node) = {0, 0};
            return;
        }

        // Iのrootが [l, r)外だったらダメ
        // if(I_root_index < I_l || I_r <= I_root_index){
        //     cout << -1 << endl; exit(0);
        // }

        ll left_tree_length = I_root_index - I_l;
        ll right_tree_length = I_r - I_root_index - 1;


        // Pの左の部分木
        if(left_tree_length > 0){
            calc(P_l+1, P_l+1 + left_tree_length, I_l, I_root_index);
            ans.at(P_root_node).first = P[P_l+1] + 1;
        }else{
            ans.at(P_root_node).first = 0;
        }

        // Pの右の部分木
        if(right_tree_length > 0){
            calc(P_l+1 + left_tree_length, P_r, I_root_index + 1, I_r);
            ans.at(P_root_node).second = P.at(P_l+1 + left_tree_length) + 1;
        }else{
            ans.at(P_root_node).second = 0;
        }
    }catch(exception& e){
        cout << -1 << endl;
        exit(0);
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    P.assign(n, 0); I.assign(n, 0);

    rep(i, n){
        cin >> P[i]; P[i]--;
        mpP[P[i]] = i;
    }
    rep(i, n){
        cin >> I[i]; I[i]--;
        mpI[I[i]] = i;
    }

    if(P[0] != 0){
        cout << -1 << endl; return 0;
    }

    ans.assign(n, {-1, -1});

    try{
        calc(0, n, 0, n);
    }
    catch(exception& e){
        cout << -1 << endl;
        return 0;
    }

    rep(i, n){
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
}