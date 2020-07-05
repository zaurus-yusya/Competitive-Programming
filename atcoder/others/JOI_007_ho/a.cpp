#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    
    vector<pll> stone;
    rep(i, n){
        ll num; cin >> num;
        if(i == 0){
            stone.push_back({1, num});
            continue;
        }

        
        if(i % 2  == 0){
            //そのまま置くだけ
            if(num == stone[stone.size() - 1].second){
                stone[stone.size() - 1].first++;
            }else{
                stone.push_back({1, num});
            }
        }else{
            //場合分け
            if(num == stone[stone.size() - 1].second){
                stone[stone.size() - 1].first++;
            }else{
                if(stone.size() > 1){
                    ll tmp = stone[stone.size() - 1].first;
                    stone.pop_back();
                    stone[stone.size() - 1].first += tmp + 1;
                }else{
                    stone[0].first++;
                    stone[0].second = (stone[0].second + 1) % 2;
                }
            }
        }
    }

    ll ans = 0;
    rep(i, stone.size()){
        if(stone[i].second == 0){
            ans += stone[i].first;
        }
    }
    cout << ans << endl;

}