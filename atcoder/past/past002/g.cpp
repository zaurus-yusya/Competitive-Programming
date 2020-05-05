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
    ll q;
    cin >> q;
    deque<pair<char,ll>> deq;

    vector<ll> res;
    rep(i,q){
        ll t;
        cin >> t;
        if(t == 1){
            char c;
            ll x;
            cin >> c >> x;
            deq.push_back(make_pair(c, x));
        }else{
            ll d;
            ll ans = 0;
            cin >> d;

            if(deq.empty()){
                //res.push_back(0);
                cout << 0 << endl;
                continue;
            }

            while(true){
                if(deq.empty()){
                    //res.push_back(ans);
                    cout << ans << endl;
                    break;
                }else{
                    pair<char, ll> top = deq.front();
                    if(top.second >= d){
                        ans += (d * d);
                        //res.push_back(ans);
                        cout << ans << endl;
                        deq.pop_front();
                        if(top.second != d){
                            deq.push_front(make_pair(top.first, top.second - d));
                        }
                        break;
                    }else{
                        ans += (top.second * top.second);
                        d -= top.second;
                        deq.pop_front();
                    }
                }
            }

        }
    }

    /*
    rep(i,res.size()){
        cout << res[i] << endl;
    }
    */

}