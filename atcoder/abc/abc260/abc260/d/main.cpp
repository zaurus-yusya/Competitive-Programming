#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}
// for(auto& i: mp) &&&&&&&&&&&&&

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<long long> p(n);
    for(long long i = 0; i < n; i ++){
        cin >> p[i];
        // p[i]--;
    }



    vector<vector<ll>> vec(n+10);
    map<ll, ll> kuwareru; // ichi, turn
    map<ll, ll> mp; // p[i], cnt
    map<ll, ll> mpr; // cnt, p[i]

    vector<ll> ans(n+10, -1);

    ll cnt = 0;
    rep(i, n){
        // cerr << "p[i] = " << p[i] << endl;
        auto itr = mp.lower_bound(p[i]);
        
        if(itr == mp.end()){
            // cerr << "insert back " << p[i] << endl;
            mp[p[i]] = cnt;
            mpr[cnt] = p[i];

            kuwareru[cnt]++;
            vec[cnt].push_back(p[i]);
            

            //削除するなら削除判定
            if(kuwareru[cnt] >= k){
                // cerr << "k in cnt" << endl;
                rep(j, vec[cnt].size()){
                    // cerr << vec[cnt][j] << endl;
                    ans[vec[cnt][j]] = i;
                }

                mp.erase(p[i]);
                mpr.erase(cnt);
            }

            cnt++;
        }else{
            // cerr << itr->first << " " << itr->second << endl;

            // cerr << "mp insert " << p[i] << " " << itr->second << endl;
            mp[p[i]] = itr->second;
            // cerr << "mpr insert " << itr->second << " " << p[i] << endl;
            
            mpr[itr->second] = p[i];
            kuwareru[itr->second]++;
            vec[itr->second].push_back(p[i]);
            
            

            // 削除するなら削除処理
            
            if(kuwareru[itr->second] >= k){
                // cerr << "k in " << itr->second << endl;

                rep(j, vec[itr->second].size()){
                    // cerr << vec[itr->second][j] << endl;
                    ans[vec[itr->second][j]] = i;
                }

                mp.erase(p[i]);
                mpr.erase(itr->second);
            }

            mp.erase(itr->first);

        }
    }

    // cerr << "---" << endl;
    // for(auto & i : mp){
    //     cout << i.first << " " << i.second << endl;
    // }
    // cerr << "---" << endl;
    // for(auto & i : mpr){
    //     cout << i.first << " " << i.second << endl;
    // }
    // cerr << "---" << endl;

    rep(i, n){
        if(ans[i+1] == -1){
            cout << ans[i+1] << '\n';
        }else{
            cout << ans[i+1] + 1 << '\n';
        }
    }


    /*
    long long n; cin >> n;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }
    vector<long long> dp(n, INF);
    
    for(long long i = 0; i < n; i ++){
        long long tmp = lower_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();
        dp[tmp] = vec[i];
    }
    
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        if(dp[i] < INF){
            ans++;
        }else{
            break;
        }
    }
    
    cout << ans << endl;
    */


}