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
    ll n; cin >> n;
    vector<long long> card(n);
    ll odd_min = INF, even_min = INF;
    for(long long i = 0; i < n; i ++){
        cin >> card[i];
        if(i % 2 == 0){
            chmin(odd_min, card[i]);
        }else{
            chmin(even_min, card[i]);
        }
    }
    ll odd_num = (n+1) / 2;
    ll even_num = n / 2;
    
    ll Q; cin >> Q;
    ll ans = 0;
    ll can_odd = 0;
    ll can_even = 0;
    rep(q,Q){
        ll task; cin >> task;
        if(task == 1){
            ll x, a; cin >> x >> a;
            x--;
            if(x % 2 == 0){
                if(card[x] - a >= can_odd){
                    card[x] -= a;
                    ans += a;

                    chmin(odd_min, card[x]);
                }
            }else{
                if(card[x] - a >= can_even){
                    card[x] -= a;
                    ans += a;

                    chmin(even_min, card[x]);
                }
            }  
        }

        if(task == 2){
            ll a; cin >> a;
            if(odd_min - a >= can_odd){
                can_odd += a;
                ans += (a * odd_num);
            }
        }

        if(task == 3){
            ll a; cin >> a;
            if( (odd_min - a >= can_odd) && (even_min - a >= can_even)){
                can_odd += a;
                can_even += a;
                ans += (a * n);
            }
        }
    }

    cout << ans << endl;

}