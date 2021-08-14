#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

template <typename T>
struct Compress {

    //元の座標のリスト 座圧前の座標群をsortして重複を削除する
    vector<T> zahyo_list; 

    //元の配列が座圧されたものに書き換わる O(n logn)
    Compress(vector<T> &vec){
        zahyo_list = vec;
        sort(zahyo_list.begin(), zahyo_list.end());
        zahyo_list.erase(unique(zahyo_list.begin(), zahyo_list.end()), zahyo_list.end());
        for(ll i = 0; i < vec.size(); i++){
            vec[i] = lower_bound(zahyo_list.begin(), zahyo_list.end(), vec[i]) - zahyo_list.begin();
        }
    }

    //座圧後の配列の値の元の値を返す O(1)
    T moto_value(ll i){
        return zahyo_list[i];
    }
};


template <typename T>
struct Compress2 {

    //元の座標のリスト 座圧前の座標群をsortして重複を削除する
    vector<ll> zahyo_list_y;
    vector<ll> zahyo_list_x;

    //元の配列が座圧されたものに書き換わる O(n logn)
    //※y座標とx座標をそれぞれ別の一次元配列に入れておく必要あり
    Compress2(vector<T> &vec_y, vector<T> &vec_x, int n = 0){
        zahyo_list_y = vec_y;
        zahyo_list_x = vec_x;

        //右と下の余白を考慮
        for(int i = 0; i < n; i++){
            
        }
        sort(zahyo_list_y.begin(), zahyo_list_y.end());
        sort(zahyo_list_x.begin(), zahyo_list_x.end());
        zahyo_list_y.erase(unique(zahyo_list_y.begin(), zahyo_list_y.end()), zahyo_list_y.end());
        zahyo_list_x.erase(unique(zahyo_list_x.begin(), zahyo_list_x.end()), zahyo_list_x.end());

        for(ll i = 0; i < vec_y.size(); i++){
            vec_y[i] = lower_bound(zahyo_list_y.begin(), zahyo_list_y.end(), vec_y[i]) - zahyo_list_y.begin();
            vec_x[i] = lower_bound(zahyo_list_x.begin(), zahyo_list_x.end(), vec_x[i]) - zahyo_list_x.begin();
        }
    }

    //座圧後の配列の値の元の値を返す O(1)
    T moto_value_y(ll i){
        return zahyo_list_y[i];
    }
    T moto_value_x(ll i){
        return zahyo_list_x[i];
    }
};




template <typename T>
vector<T> zaatsu(vector<T> & x){
    vector<T> res = x;
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    for(ll i = 0; i < x.size(); i++){
        x[i] = lower_bound(res.begin(), res.end(), x[i]) - res.begin();
    }
    return res;
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w, n; cin >> h >> w >> n;

    vector<ll> A(n); vector<ll> B(n);
    rep(i, n){
        cin >> A[i] >> B[i];
    }

    //Compress<ll> ca(A);
    //Compress<ll> cb(B);
    Compress2<ll> ca(A, B);
    /*
    zaatsu(A);
    zaatsu(B);
    */
    rep(i, n){
        cout << A[i]+1 << " " << B[i]+1 << endl;
    }

    /*
    
    vector<P> a(n);
    vector<P> b(n);
    for(long long i = 0; i < n; i ++){
        ll x, y; cin >> x >> y;
        a[i] = {x, i};
        b[i] = {y, i};
    }
    sort(all(a));
    sort(all(b));

    vector<ll> ansa(n);
    vector<ll> ansb(n);

    ll nowa = -1;
    ll cnta = 0;
    ll nowb = -1;
    ll cntb = 0;
    rep(i, n){

        if(nowa < a[i].first){
            cnta += 1;
            nowa = a[i].first;
        }
        if(nowb < b[i].first){
            cntb += 1;
            nowb = b[i].first;
        }

        ansa[a[i].second] = cnta;
        ansb[b[i].second] = cntb;

        // ansa[a[i].second] = (i+1);
        // ansb[b[i].second] = (i+1);
    }

    rep(i, n){
        cout << ansa[i] << " " << ansb[i] << '\n';
    }
    */

}