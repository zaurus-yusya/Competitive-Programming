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


map<ll, ll> tmp;
void calc(vector<ll> x){
    ll res = 0;
    for(ll i = 0; i < 6; i++){
        res += x[i] * POW(10, 5 - i);
    }
    //cout << "res = " << res << endl;
    if(tmp[res] > 0){
        return;
    }
    tmp[res]++;

    //0の操作
    vector<ll> y(6); y = x;
    y[0] = x[2]; y[1] = x[0]; y[2] = x[1];
    calc(y);
    //1の操作
    vector<ll> z(6); z = x;
    z[1] = x[3]; z[2] = x[1]; z[3] = x[2];
    calc(z);
    //2の操作
    vector<ll> w(6); w = x;
    w[2] = x[4]; w[3] = x[2]; w[4] = x[3];
    calc(w);
    //3の操作
    vector<ll> v(6); v = x;
    v[3] = x[5]; v[4] = x[3]; v[5] = x[4];
    calc(v);
}

//1-indexed only in the function
//O(log n)
//fenwick<ll> f(n)
template<typename T>
struct fenwick
{
    //constructor
    ll n;
    vector<T> bit;
    fenwick(ll n_) : n(n_ + 1), bit(n, 0) {}

    //method
    void add(ll i, T x){
        i += 1; //1-indexed
        for(ll idx = i; idx < n; idx += (idx & -idx)){
            bit[idx] += x;
        }
    }

    T sum(ll i){
        T s(0);
        //return sum[0, i)
        for(ll idx = i; idx > 0; idx -= (idx & -idx)){
            s += bit[idx];
        }
        return s;
    }

    T sum2(ll l, ll r){
        T L(0);
        T R(0);
        //return sum[l, r)
        for(ll idx = l; idx > 0; idx -= (idx & -idx)){
            L += bit[idx];
        }
        for(ll idx = r; idx > 0; idx -= (idx & -idx)){
            R += bit[idx];
        }
        return R - L;
    }

};

template<typename T>
class BIT{
  public:
    int N;
    vector<T> data;
    BIT(T _N):N(_N){
        data.assign(N+1, 0);
    };
    
    // a is 1-indexed
    void add(int a, T w){
        for(int x = a; x <= N; x += x & -x)data[x] += w;
    }
    // 1-indexed sum of prefix [0, a]
    T sum(int a){
        T res = 0;
        for(int x = a; x > 0; x -= x & -x)res += data[x];
        return res;
    }
    // 1-indexed sum of range [l, r]
    T sum(int l, int r){return sum(r) - sum(l-1);}
 
    // 0-indexed add
    void add0(int a, T w){add(a + 1, w);}
    // 0-indexed sum
    T sum0(int a){return sum(a + 1);}
    // 0-indexed sum of range
    T sum0(int l, int r){return sum0(r) - sum0(l-1);}
    // show the value
    void debug(){print(data);}
};


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    map<ll, ll> mpa;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i]; mpa[a[i]]++;
    }
    map<ll, ll> mpb;
    vector<long long> b(n);
    for(long long i = 0; i < n; i ++){
        cin >> b[i]; mpb[b[i]]++;
    }

    /////
    /*
    vecdbg(a);
    calc(a);

    for(auto& i: tmp){
        cout << i.first << " " << i.second << endl;
    }
    cout << tmp.size() << endl;
    */
    /////
    
    

    //要素が被ってなかったらバツ
    for(auto&i: mpa){
        if(mpb[i.first] != i.second){
            cout << "No" << endl; return 0;
        }
    }

    //一個でも複数個あったらOK
    for(auto&i: mpa){
        if(i.second > 1){
            cout << "Yes" << endl; return 0;
        }
    }

    map<ll, ll> inda;
    map<ll, ll> indb;
    rep(i, n){
        inda[a[i]] = i;
        indb[b[i]] = i;
    }

    vector<ll> newa(n);
    vector<ll> newb(n);

    rep(i, n){
        newa[i] = i;
        newb[indb[a[i]]] = i;
    }

    vecdbg(newa);
    vecdbg(newb);

    BIT<long long> c(n);
    ll ans = 0;
    rep(i,n){
        ans += i - c.sum0(newb[i]);
        c.add0(newb[i], 1);
    }

    cerr << ans << endl;
    if(ans % 2 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



    return 0;
    /*
    //全部違う時最後の3要素の並び順が一緒だったらOK
    vector<ll> res;
    vector<ll> ind;
    for(ll i = 0; i < n; i++){
        if(a[i] == b[n-3]){
            res.push_back(a[i]);
            ind.push_back(i);
        }
        if(a[i] == b[n-2]){
            res.push_back(a[i]);
            ind.push_back(i);
        }
        if(a[i] == b[n-1]){
            res.push_back(a[i]);
            ind.push_back(i);
        }
    }
    vector<ll> hikaku = {b[n-3], b[n-2], b[n-1]};

    //
    sort(all(ind));
    ll ff = 0;
    ff += n - 3 - ind[0];
    ff += n - 2 - ind[1];
    ff += n - 1 - ind[2];
    //
    if(ff % 2 == 0){
        vecdbg(res);
        bool f = true;
        for(ll i = 0; i < 3; i++){
            if(res[i] != hikaku[i]) f = false;
        }
        if(f){
            cout << "Yes" << endl; return 0;
        }

        f = true;
        vector<ll> ress = res;
        res[0] = ress[2];
        res[1] = ress[0];
        res[2] = ress[1];
        vecdbg(res);
        for(ll i = 0; i < 3; i++){
            if(res[i] != hikaku[i]) f = false;
        }
        if(f){
            cout << "Yes" << endl; return 0;
        }

        f = true;
        ress = res;
        res[0] = ress[2];
        res[1] = ress[0];
        res[2] = ress[1];
        vecdbg(res);
        for(ll i = 0; i < 3; i++){
            if(res[i] != hikaku[i]) f = false;
        }
        if(f){
            cout << "Yes" << endl; return 0;
        }

        cout << "No" << endl;
    }else{
        vecdbg(res);
        bool f = true;
        for(ll i = 0; i < 3; i++){
            if(res[i] != hikaku[i]) f = false;
        }
        if(f){
            cout << "No" << endl; return 0;
        }

        f = true;
        vector<ll> ress = res;
        res[0] = ress[2];
        res[1] = ress[0];
        res[2] = ress[1];
        vecdbg(res);
        for(ll i = 0; i < 3; i++){
            if(res[i] != hikaku[i]) f = false;
        }
        if(f){
            cout << "No" << endl; return 0;
        }

        f = true;
        ress = res;
        res[0] = ress[2];
        res[1] = ress[0];
        res[2] = ress[1];
        vecdbg(res);
        for(ll i = 0; i < 3; i++){
            if(res[i] != hikaku[i]) f = false;
        }
        if(f){
            cout << "No" << endl; return 0;
        }

        cout << "Yes" << endl;
    }
    */





    
    
    
    

    //長さ4のとき 0と1の操作ができる
    //
    // vector<ll> vec = {1, 2, 3, 4};
    // do{
    //     for(ll i = 0; i < n; i++){
    //         cout << vec[i] << " ";
    //     }
    //     cout << endl;
    // }while(next_permutation(vec.begin(), vec.end()));









}