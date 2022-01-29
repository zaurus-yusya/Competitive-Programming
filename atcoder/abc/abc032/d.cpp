#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
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
ll n, w;

using S = long long;
ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return -INF;
}

//宣言
//segtree<S, op, e> seg(n); //e()で初期化
//segtree<S, op, e> seg(vec); //vecの値で初期化
//seg.set(i, x); i番目の値をxに更新
//seg.get(i); i番目の要素を取得
//seg.prod(l, r); [l, r)の区間のopを計算
//seg.all_prod(); [0, n)の区間のopを計算
//seg.max_right<f>(l); 未履修
//seg.min_left<f>(r); 未履修
//単位元 e()
//min: INF, max: -INF, 和: 0, 積: 1, xor: 0, gcd: 0, lcm: 1

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

vector<P> bit_calc(vector<ll> &val, vector<ll> &wei){
    vector<P> res;
    for(ll bit = 0; bit < (1<<val.size()); bit++){
        ll value = 0, weight = 0;
        for(ll j = 0; j < val.size(); j++){
            if((bit >> j) & 1){
                value += val[j], weight += wei[j];
            }
        }
        res.push_back({value, weight});
    }
    sort(all(res), cmp);
    return res;
}

void calc1(vector<ll> &val, vector<ll> &wei){
    vector<ll> valmae;
    vector<ll> weimae;
    vector<ll> valato;
    vector<ll> weiato;
    for(ll i = 0; i < n/2; i++){
        valmae.push_back(val[i]); weimae.push_back(wei[i]);
    }
    for(ll i = n/2; i < n; i++){
        valato.push_back(val[i]); weiato.push_back(wei[i]);
    }

    vector<P> mae = bit_calc(valmae, weimae);
    vector<P> ato = bit_calc(valato, weiato);
    vector<ll> valmae2(mae.size()); vector<ll> weimae2(mae.size());
    vector<ll> valato2(ato.size()); vector<ll> weiato2(ato.size());
    rep(i, mae.size()){
        valmae2[i] = mae[i].first; weimae2[i] = mae[i].second;
    }
    rep(i, ato.size()){
        valato2[i] = ato[i].first; weiato2[i] = ato[i].second;
    }

    ll ans = 0;
    segtree<S, op, e> seg(valato2);

    rep(i, mae.size()){
        if(weimae2[i] > w) continue;
        ll dis = upper_bound(weiato2.begin(), weiato2.end(), w - weimae2[i]) - weiato2.begin();
        ll tmp = seg.prod(0, dis);
        ans = max(ans, valmae2[i] + tmp);
    }
    cout << ans << endl;

}

void calc2(vector<ll> &val, vector<ll> &wei){
    vector<vector<ll>> dp(n+1, vector<ll>(min(w, 1000*200LL) + 10));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= min(w, 1000*200LL); j++){
            //選ぶ
            if(j - wei[i] >= 0){
                dp[i+1][j] = max(dp[i][j - wei[i]] + val[i], dp[i][j]);
            }
            //選ばない
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    cout << dp[n][min(w, 1000*200LL)] << endl; 
}

void calc3(vector<ll> &val, vector<ll> &wei){
    vector<vector<ll>> dp(n+1, vector<ll>(1000*200LL + 10, INF));
    dp[0][0] = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= 1000*200LL; j++){
            //選ぶ
            if(j - val[i] >= 0){
                dp[i+1][j] = min(dp[i][j - val[i]] + wei[i], dp[i+1][j]);
            }
            //選ばない
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }

    ll ans = 0;
    rep(i, 1000*200LL + 1){
        if(dp[n][i] <= w){
            ans = i;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> w;
    vector<ll> val(n);
    vector<ll> wei(n);
    ll mav = 0, maw = 0;
    rep(i, n){
        cin >> val[i] >> wei[i];
        mav = max(mav, val[i]);
        maw = max(maw, wei[i]);
    }

    if(n <= 30){
        cerr << "data1" << endl;
        calc1(val, wei);
    }else if(maw <= 1000){
        cerr << "data2" << endl;
        calc2(val, wei);
    }else{
        cerr << "data3" << endl;
        calc3(val, wei);
    }

}