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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll N; cin >> N;
    ll n = 1;
    rep(i, N){
        n *= 2;
    }

    vector<pair<ll, ll>> vec(n);
    vector<ll> ans(n);
    for(long long i = 0; i < n; i ++){
        ll tmp;
        cin >> tmp;
        vec[i] = {i, tmp};
    }

    vector<pair<ll, ll>> now = vec;
    

    for(ll i = 0; i < N; i++){
        
        if(i == N-1){
            ans[now[1].first] = i+1;
            ans[now[0].first] = i+1;
            break;
        }
        
        vector<pair<ll, ll>> next;
        for(ll j = 0; j < now.size(); j += 2){
            if(now[j].second > now[j+1].second){
                next.push_back({now[j].first, now[j].second});
                ans[now[j+1].first] = i+1;
            }else{
                next.push_back({now[j+1].first, now[j+1].second});
                ans[now[j].first] = i+1;
            }
        }
        now = next;
    }

    rep(i,n){
        cout << ans[i] << endl;
    }


}