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

    rep(i,q){
        ll t;
        cin >> t;
        if(t == 1){
            char c;
            ll x;
            cin >> c >> x;
            //deq.push_back(make_pair(c, x));
            if(!deq.empty()){
                char b = deq.back().first;
                ll num = deq.back().second;
                if(b == c){
                    deq.pop_back();
                    deq.push_back({c,x+num});
                }else{
                    deq.push_back({c,x});
                }
            }else{
                deq.push_back({c,x});
            }
            
        }else{
            ll d;
            ll ans = 0;
            cin >> d;

            if(deq.empty()){
                cout << 0 << endl;
            }else{

                map<char, ll> mp;

                while(!deq.empty()){
                    char now = deq.front().first;
                    ll num = deq.front().second;
                    deq.pop_front();
                    if(num > d){
                        mp[now] += d;
                        deq.push_front({now,num-d});
                        break;
                    }else if(num == d){
                        mp[now] += d;
                        break;
                    }else{
                        mp[now] += num;
                        d = d - num;
                    }
                }

                for(auto i: mp){
                    ans += i.second*i.second;
                }
                cout << ans << endl;
            }
        }
    }


}