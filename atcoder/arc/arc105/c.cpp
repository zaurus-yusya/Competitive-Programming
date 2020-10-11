#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<long long> w(n);
    for(long long i = 0; i < n; i ++){
        cin >> w[i];
    }
    sort(all(w));
    vector<ll> l(m);
    vector<ll> v(m);
    vector<pair<ll,ll>> p(m);
    ll min_v = INF;
    ll sum_l = 0;
    rep(i, m){
        cin >> l[i] >> v[i];
        min_v = min(min_v, v[i]);
        sum_l += l[i];
        p[i] = make_pair(v[i], l[i]);
    }
    sort(all(p));
    vector<ll> sv(m);
    rep(i, m){
        sv[i] = p[i].first;
    }

    //橋の耐荷重のminがラクダの最大重さより小さかったら-1
    if(w[n-1] > min_v){
        cout << -1 << endl; return 0;
    }

    ll ans = 10e17;
    ll cnt = 0;
    //一番小さい橋 min_v
    do{
        /*
        for(ll i = 0; i < n; i++){
            cout << w[i] << " ";
            
        }
        cout << endl;
        cout << "---" << endl;
        */
        

        
        ll now = 0;
        vector<ll> tumi;
        for(ll i = 0; i < n; i++){
            if(now + w[i] >= min_v){
                if(now != 0){
                    tumi.push_back(now);
                    now = 0;
                } 
            }
            now += w[i];
        }
        if(now != 0) tumi.push_back(now);
        

        /*
        rep(i, tumi.size()){
            cout << tumi[i] << " ";
        }br;
        cout << "-------" << endl;
        */
        //↑↑積まれた

        
        ll kankaku = 0;
        ll tmp_ans = 0;
        vector<ll> aaa;
        rep(i, tumi.size() - 1){
            kankaku = 0;
            rep(j, m){
                if(tumi[i] + tumi[i+1] > v[j]){
                    kankaku = max(kankaku, l[j]);
                }
            }
            tmp_ans += kankaku;
            if(kankaku != 0){
                aaa.push_back(kankaku);
            }
        }

        ans = min(ans, tmp_ans);
        /*
        if(tmp_ans == (ll)3848){
            cout << "-------" << endl;
            rep(i, tumi.size()){
                cout << tumi[i] << " ";
            }br;
            cout << "-------" << endl;
            rep(i, aaa.size()){
                cout << aaa[i] << " ";
            }br;
            cout << "-------" << endl;
        }
        */
        
    }while(next_permutation(w.begin(), w.end()));

    cout << ans << endl;

}