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
    ll n, m, k; cin >> n >> m >> k;

    vector<long long> vec_a(n);
    vector<long long> sum_a(n + 1);
    rep(i, n){
        cin >> vec_a[i];
        sum_a[i+1] = vec_a[i] + sum_a[i];
    }

    vector<long long> vec_b(m);
    vector<long long> sum_b(m + 1);
    rep(i, m){
        cin >> vec_b[i];
        sum_b[i+1] = vec_b[i] + sum_b[i];
    }
    /*
    rep(i, n+1){
        cout << sum_a[i] << " ";
    }
    br;
    rep(i, m+1){
        cout << sum_b[i] << " ";
    }
    br;
    */

    ll ans = 0;
    for(ll i = 0; i <= n; i++){
        ll tmp = k - sum_a[i];
        if(tmp == 0){
            ans = max(ans, i);
            continue;
        }else if(tmp < 0){
            continue;
        }

        ll tmp_b = lower_bound(sum_b.begin(), sum_b.end(), tmp) - sum_b.begin();
        if(i + tmp_b <= k){
            
            if(sum_b[tmp_b] == tmp){
                ans = max(ans, i+tmp_b);
            }else{
                ans = max(ans, i+tmp_b-1);
            }

            //cout << tmp << " " << i << " " << tmp_b << endl;
             
        }
        /*
        for(ll j = 1; j <= m; j++){
            if(sum_a[i] + sum_b[j] <= k){
                ans = max(ans, i+j);
            }
        }
        */
    }
    cout << ans << endl;

    /*
    vector<long long> vec_a(n);
    queue<ll> que_a;
    for(long long i = 0; i < n; i ++){
        cin >> vec_a[i];
        que_a.push(vec_a[i]);
    }
    vector<long long> vec_b(m);
    queue<ll> que_b;
    for(long long i = 0; i < m; i ++){
        cin >> vec_b[i];
        que_b.push(vec_b[i]);
    }
    vec_a.push_back(1e10);
    vec_b.push_back(1e10);

    ll a = 0, b = 0;
    ll res = 0;
    ll count = 0;
    while(true){
        if(vec_a[a] > vec_b[b]){
            if(res + vec_b[b] > k){
                break;
            }
            res += vec_b[b];
            b++;
            count++;
            
        }else if(vec_a[a] < vec_b[b]){
            if(res + vec_a[a] > k){
                break;
            }
            res += vec_a[a];
            a++;
            count++;
        }else{
            if(res + vec_a[a] > k){
                break;
            }
            res += vec_a[a];
            a++;
            count++;
        }
        if(a == n && b == m){
            break;
        }
    }

    cout << "res = " << res << endl;
    cout << count << endl;
    */


}