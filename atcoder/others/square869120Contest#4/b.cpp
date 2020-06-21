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

ll n, k;
vector<long long> vec(n);
ll ans = 1e15;

void bit_search(ll n, ll k){

    for(ll bit = 0; bit < (1<<n); bit++){
        ll can_see = 0;
        vector<ll> build;
        vector<ll> test;
        for(ll i = 0; i < n; i++){
            if(bit & (1<<i)){
                can_see++;
                build.push_back(vec[i]);
                test.push_back(i);
            }
        }
        
        if(can_see >= k){
            ll tmp = 0;
            ll now = 0;
            ll count = 0;

            for(ll j = 0; j < n; j++){
                if(j == test[count]){
                    if(now >= vec[j]){
                        tmp += now + 1 - vec[j];
                        now = now + 1;
                    }else{
                        now = vec[j];
                    }
                    count++;
                }else{
                    now = max(now, vec[j]);
                }
            }

            ans = min(ans, tmp);
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> k;
    vec.resize(n);
    
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }

    bit_search(n, k);

    cout << ans << endl;


}