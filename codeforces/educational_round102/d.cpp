#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
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

template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, INF) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};

template <typename T>
struct RMQ2 {
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ2(int n_) : n(), dat(n_ * 4, -INF) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    // the minimum element of [a,b)
    T query2(int a, int b) { return query_add(a, b, 0, 0, n); }
    T query_add(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return -INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_add(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_add(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, m; cin >> n >> m;
        string s; cin >> s;
        vector<ll> l(m); vector<ll> r(m);
        rep(i, m){
            cin >> l[i] >> r[i];
        }
        vector<ll> val(n + 1, 0); ll cur = 0;
        rep(i, n){
            if(s[i] == '-') cur--;
            else cur++;
            val[i+1] = cur;
        }
        vecdbg(val);

        RMQ<ll> rr(n+1);
        RMQ2<ll> rr2(n+1);
        rep(i, n+1){
            rr.update(i, val[i]);
            rr2.update(i, val[i]);
        }

        //output
        rep(i, m){
            ll sa = (val[l[i]-1]) - val[r[i]];
            cout << "sa = " << sa << endl; 
            //leftside
            ll mi1 = rr.query(0, l[i]);
            ll ma1 = rr2.query2(0, l[i]);
            //rightside
            if(r[i] == n){
                cout << ma1 - mi1 + 1 << "\n";
            }else{
                //ll mi2 = sa + rr.query(r[i] + 1 , n+1);
                //ll ma2 = sa + rr.query2(r[i] + 1 , n+1);
                ll mi2 = rr.query(r[i] + 1 , n+1);
                ll ma2 = rr2.query2(r[i] + 1 , n+1);
                cout << mi1 << " " << ma1 << endl;
                cout << sa + mi2 << " " << sa + ma2 << endl;
            }

            

        }


    }

}