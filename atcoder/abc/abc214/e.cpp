#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
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
/*
//segment tree
//init O(N)  update query O(logN)
ll n;
ll dat[1<<18];

ll K = -1;
void init(ll n_){
    n = 1;
    while(n < n_) n *= 2;
    for(ll i = 0; i < 2*n - 1; i++) dat[i] = INF;
}
// RMQ min [a, b)
// index k value to a
void update(ll k, ll a){
    k += n - 1;
    dat[k] = a;
    while(k > 0){
        k = (k-1) / 2;
        dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
    }
}
ll query(ll a, ll b, ll k=0, ll l=0, ll r=n){
    if(r <= a || b <= l){
        return INF;
        K = INF;
    }

    if(a <= l && r <= b){
        return dat[k];
        K = k;
    }
    else{
        ll vl = query(a, b, k*2 + 1, l, (l+r) / 2);
        ll vr = query(a, b, k*2 + 2, (l+r) / 2, r);
        return min(vl, vr);
    }
}
*/

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<P> vec;
        rep(i, n){
            ll l, r; cin >> l >> r;
            vec.push_back({l, r});
        }
        vector<P> vec2;
        sort(all(vec));
        sort(all(vec2), cmp);
        ll now_l = -1;
        ll now_r = INF;
        bool flag = true;
        rep(i, n){
            if(now_l < vec[i].first){

                if(vec[i].first < now_r){
                    now_l = vec[i].first;
                }else{
                    flag = false; break;
                }
                
            }else if(vec[i].first <= now_l && now_l < vec[i].second){
                if(now_l+1 < now_r){
                    now_l= now_l+1;
                }else{
                    flag = false; break;
                }
            }else if(now_r > vec2[i].second){

                if(now_l < vec2[i].second){
                    now_r = vec2[i].second;
                }else{
                    flag = false; break;
                }
                
            }else if(vec2[i].second >= now_r && now_r > vec2[i].first){

                if(now_l < now_r - 1){
                    now_r = now_r - 1;  
                }else{
                    flag = false; break;
                } 
                
            }else{
                flag = false; break;
            }
            cerr << "now = " << now_l << " " << now_r << endl;
        }
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
        
    }
    


}