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
    ll n, k; cin >> n >> k;
    vector<pll> vec(n);
    ll posi_flag = 0;
    rep(i, n){
        ll tmp; cin >> tmp;
        if(tmp < 0){
            tmp = (tmp * -1);
            vec[i] = {tmp, 1};
        }else{
            vec[i] = {tmp, 0};
            posi_flag++;
        }
    }
    sort(all(vec));

    if(posi_flag == 0 && k % 2 == 1){
        //nega_only
        ll ans2 = 0;
        rep(i, k){
            if(i == 0){
                ans2 = vec[i].first; continue;
            }
            ans2 = (ans2 * vec[i].first) % MOD;
        }
        ans2 = ans2 * (-1);
        cout << (ans2+MOD) % MOD << endl;
        return 0;
    }
    /*
    rep(i, n){
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    */

    vector<ll> res;
    ll nega_min = 0, posi_min = 0;
    ll nega_num = 0, posi_num = 0;
    ll nega_itr = -1, posi_itr = -1;
    for(ll i = 0; i < k; i++){
        res.push_back(vec[n-1-i].first);
        if(vec[n-1-i].second == 1){
            nega_min = vec[n-1-i].first;
            nega_itr = i;
            nega_num++;
        }else{
            posi_min = vec[n-1-i].first;
            posi_itr = i;
            posi_num++;
        }
    }


    ll ans = 0;
    vector<ll> res2;
    vector<ll> res3;
    res2 = res; res3 = res;
    if(nega_num % 2 == 1){

        //補正必要
        bool nega_to_posi = false;
        bool posi_to_nega = false;
        ll tmp2 = -1, tmp3 = -1;
        for(ll i = n-1-k; i >= 0; i--){
            if(vec[i].second == 1){
                if(posi_to_nega == false && posi_itr != -1){
                    tmp2 = res2[posi_itr] - vec[i].first;
                    res2[posi_itr] = vec[i].first;
                    posi_to_nega = true;
                }
            }else{
                if(nega_to_posi == false && nega_itr != -1){
                    tmp3 = res3[nega_itr] - vec[i].first;
                    res3[nega_itr] = vec[i].first;
                    nega_to_posi = true;
                }
            }
            if(nega_to_posi && posi_to_nega){
                break;
            }
        }

        if(tmp2 == -1){
            rep(i, res3.size()){
                if(i == 0){
                    ans = res3[i]; continue;
                }
                ans = (ans * res3[i]) % MOD;
            }
        }else if(tmp3 == -1){
            rep(i, res2.size()){
                if(i == 0){
                    ans = res2[i]; continue;
                }
                ans = (ans * res2[i]) % MOD;
            }
        }else if(tmp2 > tmp3){
            rep(i, res3.size()){
                if(i == 0){
                    ans = res3[i]; continue;
                }
                ans = (ans * res3[i]) % MOD;
            }
        }else{
            rep(i, res2.size()){
                if(i == 0){
                    ans = res2[i]; continue;
                }
                ans = (ans * res2[i]) % MOD;
            }
        }
    }else{
        //補正必要なし
        rep(i, res.size()){
            if(i == 0){
                ans = res[i]; continue;
            }
            ans = (ans * res[i]) % MOD;
        }
    }

    cout << ans << endl;


    
}