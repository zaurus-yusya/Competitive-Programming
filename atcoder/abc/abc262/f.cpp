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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<long long> p(n);
    ll one_ind;
    bool f = false;
    ll one_right = 0;
    for(long long i = 0; i < n; i ++){
        cin >> p[i];
        if(f){
            one_right++;
        }
        if(p[i] == 1){
            one_ind = i;
            f = true;
        }

    }

    cerr << "one_ind = " << one_ind << endl;
    ll one_left = one_ind;
    cerr << "one_right = " << one_right << endl;


    // 消す回数
    // 1より右を消す
    vector<ll> kesujun;
    stack<ll> st;
    for(ll i = one_ind + 1; i < n; i++){
        if(st.empty()){
            st.push(p[i]);
        }else{
            ll now = p[i];
            while(!st.empty()){
                ll top_ = st.top();
                if(top_ > now){
                    kesujun.push_back(top_);
                    st.pop();
                }else{
                    break;
                }
            }
            st.push(now);
        }
    }

    while(!st.empty()){
        ll top_ = st.top();
        kesujun.push_back(top_);
        st.pop();
    }
    vecdbg(kesujun);

    vector<ll> kesujunleft;
    for(ll i = one_ind + 1; i < one_ind; i++){

    }
    

    // 1より左を消す
    // 1を左に持っていく
    

    // 1より右で持っていく回数
    for(ll i = 0; i <= one_right; i++){

    }



}