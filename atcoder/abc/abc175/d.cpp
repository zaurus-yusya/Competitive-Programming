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

    /*
    ll ans = -1e18;
    rep(si, n){
        ll x = si;
        vector<ll> s;
        ll total = 0;
        while(true){
            x = p[x];
            s.push_back(c[x]);
            total += c[x];
            if(x == si) break;
        }
        ll l = s.size();
        ll t = 0;
        rep(i, l){
            t += s[i];
            if(i+1 > k) break;
            ll now = t;
            if(total > 0){
                now += total * ((k-i-1) / l);
            }
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    */

    
    
    vector<ll> dist(n, -1);
    ll ans = -1e18;
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

            ll size = res.size();
            
            rep(i, size){
                ll t = 0;
                rep(j, size){
                    t += res[(j + i) % size];
                    ll now = t;
                    if(one_roop > 0){
                        now += one_roop * ((k - j - 1) / size);
                    }
                    ans = max(ans, now);
                }
                
            }

            /*
            ll saigo = 0;
            ll tmp_k = k;
            if(one_roop > 0){
                if(res.size() < tmp_k){
                    saigo = one_roop * (tmp_k / res.size());
                    tmp_k = tmp_k % res.size();
                }
            }else{
                if(res.size() < tmp_k){
                    tmp_k = tmp_k % res.size();
                }
            }
            
            ll this_ans = 0;
            bool this_flag = true;
            rep(i, res.size()){
                ll tmp = 0;
                rep(j, tmp_k){
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
            ///
            
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