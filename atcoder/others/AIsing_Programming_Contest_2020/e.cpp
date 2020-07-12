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


bool cmp2(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first != b.first){
        return a.first > b.first;
    }

    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return true;
    }
}

bool cmp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b){
    if(a.first != b.first){
        return a.first < b.first;
    }

    ll i, j, k, l;
    vector<pair<ll, ll>> tmp(4);
    tmp[0].first = a.second.first;
    tmp[1].first = b.second.first;
    tmp[2].first = a.second.second;
    tmp[3].first = b.second.second;
    tmp[0].second = 0;
    tmp[0].second = 1;
    tmp[0].second = 2;
    tmp[0].second = 3;
    sort(all(tmp), cmp2);

    if(tmp[0].second % 2 == 0){
        return a.first > b.first;
    }else{
        return b.first > a.first;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;

    rep(T, t){
        ll n; cin >> n;
        vector<pair<ll, pair<ll, ll>>> vec(n);
        vector<ll> k(n);
        vector<ll> l(n);
        vector<ll> r(n);
        rep(i, n){
            cin >> k[i] >> l[i] >> r[i];
            vec[i].first = k[i]; vec[i].second.first = l[i]; vec[i].second.second = r[i];
        }
        sort(all(vec), cmp);

        rep(i, vec.size()){
            cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << endl;
        }

        ll ans = 0;
        rep(i, n){
            if(vec[i].second.first > vec[i].second.second){
                ans += vec[i].second.first;
            }else{
                ans += vec[i].second.second;
            }
        }

        cout << ans << endl;

    }

}