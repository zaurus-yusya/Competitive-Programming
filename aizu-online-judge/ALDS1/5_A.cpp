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
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

bool ok = false;
map<ll,ll>mp;
void dfs(ll now, ll itr, vector<ll> A){

    if(itr < A.size()){
        //select
        mp[now+A[itr]]++;
        dfs(now+A[itr], itr+1, A);
        //not select
        dfs(now, itr+1, A);
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n;
    cin >> n;
    vector<long long> A(n);
    rep(i, n) cin >> A[i];
    ll q;
    cin >> q;
    vector<long long> m(q);
    rep(i, q) cin >> m[i];

    dfs(0, 0, A);
    rep(t,q){
        if(mp.count(m[t]) >=1){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

}