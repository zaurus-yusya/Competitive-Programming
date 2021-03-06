#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

void out(vector<pair<ll, char>> &v, vector<queue<char>> &q, ll n){
    bool flag = true;
    rep(i, n){
        ll num = v[i].first;
        char mark = v[i].second;
        if(i == 0){
            cout << mark << num;
        }else{
            cout << " " << mark << num;
        }
        char c = q[num].front(); 
        q[num].pop();
        if(c != mark) flag = false;
    }br;

    if(flag){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<pair<ll, char>> bubble(n);
    vector<pair<ll, char>> selection(n);
    vector<queue<char>> check_bubble(10);
    vector<queue<char>> check_selection(10);
    rep(i, n){
        string s; cin >> s;
        bubble[i] = {s[1] - '0', s[0]};
        check_bubble[s[1] - '0'].push(s[0]);
    }
    selection = bubble;
    check_selection = check_bubble;

    //bubble
    for(ll i = 0; i < n; i++){
        for(ll j = n-1; j > i; j--){
            if(bubble[j].first < bubble[j-1].first){
                swap(bubble[j], bubble[j-1]);
            }
        }
    }
    out(bubble, check_bubble, n);
   
    //selection
    for(ll i = 0; i < n; i++){
        ll minj = i;
        for(ll j = i; j < n; j++){
            if(selection[j].first < selection[minj].first){
                minj = j;
            }
        }
        swap(selection[i], selection[minj]);
    }
    out(selection, check_selection, n);


}