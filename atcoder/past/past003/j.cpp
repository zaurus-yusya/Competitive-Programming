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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<long long> vec(m);
    for(long long i = 0; i < m; i ++){
        cin >> vec[i];
    }

    
    vector<ll> child;

    rep(i, m){
        if(i == 0){
            child.push_back(vec[i]);
            cout << 1 << endl;
            continue;
        }

        auto itr = lower_bound(all(child), vec[i]);

        if(itr - child.begin() == 0){
            if(child.size() < n){

                auto itr = child.begin();
                child.insert(itr, vec[i]);

                cout << child.size() << endl;
            }else{
                cout << -1 << endl;
            }
        }else{
            child[itr - child.begin() -1] = vec[i];
            cout << child.size() - (itr - child.begin()) + 1 << endl;
        }

    }

}