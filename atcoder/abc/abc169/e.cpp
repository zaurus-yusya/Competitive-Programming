#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
typedef pair<int,int> pint;
bool cmp(pint a, pint b) { return a.second < b.second; }

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);

    ll med_min = 0;
    ll med_max = 0;
    rep(i, n){
        cin >> A[i] >> B[i];
    }

    sort(all(A));
    sort(all(B));

    if(n % 2 == 0){
        cout << ((B[n/2] + B[n/2 - 1]) - (A[n/2] + A[n/2 - 1])) + 1 << endl;
    }

    if(n % 2 == 1){
        cout << B[n/2] - A[n/2] + 1 << endl;
    }

    

}