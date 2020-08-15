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
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<long long> p(n);
    for(long long i = 0; i < n; i ++){
        cin >> p[i];
        p[i]--;
    }
    vector<long long> c(n);
    for(long long i = 0; i < n; i ++){
        cin >> c[i];
    }

    vector<ll> dist(n, -1);
    ll ans = 0;
    bool flag = true;
    
    rep(i, n){
        if(dist[i] == -1){

            vector<ll> res;
            ll next = i;
            ll one_roop = 0;
            while(true){
                next = p[next];
                if(dist[next] != -1){
                    break;
                }
                dist[next] = 0;
                res.push_back(c[next]);
                one_roop += c[next];
            }

            ll saigo = 0;
            if(one_roop > 0){
                if(res.size() < k){
                    saigo = one_roop * (k / res.size());
                    k = k % res.size();
                }
            }

            ll this_ans = 0;
            bool this_flag = true;
            rep(i, res.size()){
                ll tmp = 0;
                rep(j, k){
                    tmp += res[(i + j) % res.size()];
                    if(this_flag){
                        this_ans = tmp;
                        this_flag = false;
                    }
                    this_ans = max(this_ans, tmp);
                }
            }
            this_ans += saigo;
            if(flag){
                ans = this_ans;
                flag = false;
            }
            ans = max(ans, this_ans);

            /*
            
            ll size = res.size();
            ll one_roop_size = size;
            
            rep(i, size){
                res.push_back(res[i]);
            }
            size = res.size();

            vector<ll> sum(size+1);
            rep(i, size+1){
                sum[i+1] = sum[i] + res[i];
            }

            if(k > one_roop_size){
                saigo = one_roop * (k / one_roop_size);
                k = k % one_roop_size;
            }

            for(ll i = 1; i <= k; i++){
                for(ll j = 0; j < sum.size()-i; j++){
                    ll val = sum[i+j] - sum[j];
                    if(flag){
                        ans = val;
                        flag = false;
                    } 
                    if(ans < val) ans = val;
                }
            }
            ans = ans + saigo;
            */
        } 
    }
    cout << ans<< endl;

}