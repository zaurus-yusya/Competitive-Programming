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

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll N;
    cin >> N;
    const auto &res = prime_factorize(N);

    if(res.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    
    map<ll,ll> mp;
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i){
            //cout << " " << p.first;
            mp[p.first]++;
        } 
    }
    

    ll tmp = 0;
    vector<ll> two;
    rep(i, 100){
        //cout << tmp + i+1 << endl;
        tmp += i+1;
        two.push_back(tmp);
    }

    ll ans = 0;
    for(auto i: mp){
      // << i.first << " " << i.second << endl;  //key, value
      auto Iter = upper_bound(all(two), i.second);
      ans += (ll)(Iter - two.begin());
    }
    cout << ans << endl;



}