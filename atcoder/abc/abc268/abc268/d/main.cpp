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


void calc(vector<string> &vs, vector<ll> &num, set<string> &st, ll c_sum, ll now){
    // cerr << "now = " << now << " c_sum = " << c_sum << endl;
    if(now >= vs.size() - 1){
        return;
    }

    for(ll i = 1; i + c_sum <= 16; i++){
        // 入れる
        num[now] = i;

        // 判定する
        if(now == vs.size() - 2){
            // 文字作る
            string s = "";
            rep(i, vs.size()){
                s += vs[i];
                rep(j, num[i]){
                    s += '_';
                }
            }

            if(st.find(s) != st.end()){

            }else{
                if(c_sum + i >= 3 && c_sum <= 16){
                    cout << s << endl; 
                    // cerr << c_sum + i << endl;
                    exit(0);
                }
            }
        }

        // 次の空間に行く
        calc(vs, num, st, c_sum + i, now+1);
        num[now] = 0;
    }


}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<string> vs(n); // 8  16文字以内
    set<string> st; // 10^5

    ll c_sum = 0;
    rep(i, n){
        cin >> vs[i];
        c_sum += vs[i].size();
    }
    rep(i, m){
        string t; cin >> t;
        st.insert(t);
    }

    if(n == 1){
        if(vs[0].size() < 3){
            cout << -1 << endl;
        }else if(st.find(vs[0]) != st.end()){
            cout << -1 << endl;
        }else{
            cout << vs[0] << endl;
        }
        return 0;
    }

    vector<ll> num(n);
    sort(all(vs));
    // 40320
    do{ 
        // for(ll i = 0; i < n; i++){
        //     cerr << vs[i] << " ";
        // }
        // cerr << endl;
        // cerr << "---" << endl;
        calc(vs, num, st, c_sum, 0);
    }while(next_permutation(vs.begin(), vs.end()));



    cout << -1 << endl;
}