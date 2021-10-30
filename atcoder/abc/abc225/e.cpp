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

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first != b.first){
        return a.first > b.first;
    }

    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return true;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<P> kyori(n);

    map<ld, ll> mp;

    map<ll, ll> mpp;
    rep(i, n){
        cin >> x[i] >> y[i];
        /*
        kyori[i] = {x[i]*x[i] + y[i]*y[i], i};
        if(x[i] - 1 == 0){
            mp[INF]++;
        }else{
            // x-1
            mp[(ld)y[i] / (ld)(x[i] - 1)]++;
        }
        // y-1
        mp[(ld)(y[i] - 1) / (ld)(x[i])]++;
        */
        //元の座標の45度回転
        ll X = x[i] - y[i];
        ll Y = x[i] + y[i];
        kyori[i] = {X*X+Y*Y, i};

        //各2点の45度回転のx座標
        mpp[X-1]++;
        mpp[X+1]++;
    }

    sort(all(kyori));

    // for(auto i : mp){
    //     cout << i.first << ' ' << i.second << endl;
    // }
    // rep(i, kyori.size()){
    //     cout << kyori[i].first << " " << kyori[i].second << endl;
    // }


    ll cnt = 0;
    rep(i, n){
        ll xx = x[kyori[i].second];
        ll yy = y[kyori[i].second];
        ll X = xx - yy;

        auto itr = mpp.lower_bound(X-1);
        auto itr2 = mpp.lower_bound(X+1);

        if(++itr == itr2){
            //ok
        }else{
            cnt++;
            
            mpp[X-1]--;
            if(mpp[X-1] == 0){
                mpp.erase(X-1);
            }
            mpp[X+1]--;
            if(mpp[X+1] == 0){
                mpp.erase(X+1);
            }

        }
    }

    cout << n - cnt << endl;
    
    /*
    ll cnt = 0;
    rep(i, n){
        ll X = x[kyori[i].second];
        ll Y = y[kyori[i].second];
        cout << "X = " << X << " Y = " << Y << endl;

        auto itr = mp.lower_bound((ld)Y / (ld)(X - 1));
        auto itr2 = mp.lower_bound((ld)(Y-1) / (ld)(X));

        if(++itr2 == itr){
            //ok
        }else{
            cnt++;
            mp[(ld)Y / (ld)(X - 1)]--;
            if(mp[(ld)Y / (ld)(X - 1)] == 0){
                mp.erase((ld)Y / (ld)(X - 1));
            }
            mp[(ld)(Y-1) / (ld)(X)]--;
            if(mp[(ld)(Y-1) / (ld)(X)] == 0){
                mp.erase((ld)(Y-1) / (ld)(X));
            }
        }

    }
    cout << n - cnt << endl;
    */


    // for(auto i : mp){
    //     cout << i.first << ' ' << i.second << endl;
    // }

    // cout << "---" << endl;
    // auto itr = mp.lower_bound(0.9);
    // auto itr2 = mp.lower_bound(1.5);
    // if(itr == mp.end()){
    //     cout << "ok" << endl;
    // }
    // cout << itr-> first << " " << itr-> second << endl;
    // if(itr2 == mp.end()){
    //     cout << "ok" << endl;
    // }
    // cout << itr2-> first << " " << itr2-> second << endl;

    // if(++itr == itr2){
    //     cout << "okk" << endl;
    // }else{
    //     cout << "ng" << endl;
    // }




}