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

ll n;
vector<ll> group;
vector<vector<ll>> vec(n, vector<ll>(n));
ll ans = -INF;
void dfs(ll num){
    if(num == n){
        //スコア計算
        vector<ll> zero;
        vector<ll> one;
        vector<ll> two;
        rep(i, group.size()){
            if(group[i] == 0){
                zero.push_back(i);
            }
            if(group[i] == 1){
                one.push_back(i);
            }
            if(group[i] == 2){
                two.push_back(i);
            }
        }
        ll tmp = 0;
        if(zero.size() > 1){
            for(ll i = 0; i < zero.size() - 1; i++){
                for(ll j = 0; j < zero.size(); j++){
                    tmp += vec[zero[i]][zero[j]];
                }
            }
        }
        if(one.size() > 1){
            for(ll i = 0; i < one.size() - 1; i++){
                for(ll j = 0; j < one.size(); j++){
                    tmp += vec[one[i]][one[j]];
                }
            }
        }
        if(two.size() > 1){
            for(ll i = 0; i < two.size() - 1; i++){
                for(ll j = 0; j < two.size(); j++){
                    tmp += vec[two[i]][two[j]];
                }
            }
        }
        ans = max(ans, tmp);    
    }else{
        for(ll i = 0; i < 3; i++){
            group[num] = i;
            dfs(num+1);
        }
    }
}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    group.resize(n);
    vec.resize(n, vector<ll>(n));
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            cin >> vec[i][j];
        }
    }

    dfs(0);

    cout << ans << endl;

}