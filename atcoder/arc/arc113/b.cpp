#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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


int main() {
    std::cout << std::fixed << std::setprecision(15);
    string a; cin >> a;
    string b; cin >> b;
    ll num_b = stoi(b);
    ll c; cin >> c;
    ll a_1 = a[a.size() - 1] - 48;
    //cout << a_1 << endl;

    
    if(a_1 == 0 || a_1 == 1 || a_1 == 5 || a_1 == 6){
        cout << a_1 << endl; return 0;
    }

    vector<vector<ll>> syuki(10);
    syuki[0] = {0};
    syuki[1] = {1};
    syuki[2] = {2,4,8,6};
    syuki[3] = {3,9,7,1};
    syuki[4] = {4,6};
    syuki[5] = {5};
    syuki[6] = {6};
    syuki[7] = {7,9,3,1};
    syuki[8] = {8,4,2,6};
    syuki[9] = {9,1};

    if(a_1 == 4 || a_1 == 9){
        if(num_b % 2 == 0){
            cout << syuki[a_1][1] << endl;
        }else{
            cout << syuki[a_1][0] << endl;
        }
        return 0;
    }

    ll x = num_b % 4;
    ll y = c % 4;

    if(x == 0 && y == 0){
        cout << syuki[a_1][3] << endl; return 0;
    }
    

    ll tmp = POW(x, y) % 4;
    if(tmp == 0){
        tmp = 4;
    }

    cout << syuki[a_1][tmp-1] << endl;
    



    /*

    ll mod_a = syuki[a_1].size();

    ll b_1 = b[b.size() - 1] - 48;
    //cout << b_1 << endl;
    ll mod_b = syuki[b_1].size();
    cout << "mod_b " << mod_b << endl;

    ll x = c % mod_b;
    cout << "x " << x << endl;
    if(x == 0){
        x = syuki[b_1].size();
    }

    ll y = syuki[b_1][ (x - 1) % syuki[b_1].size()];

    if(y == 0){
        y = syuki[a_1].size();
    }
    cout << "y " << y << endl;

    ll ans = syuki[a_1][ (y-1) % syuki[a_1].size()];
    cout << ans << endl;
    */





    //for(ll i = )

}