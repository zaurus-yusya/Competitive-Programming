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
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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

void slide(vector<ll> &vec, ll ind, ll x){
    vector<ll> res(vec.size() + 1);
    ll now = 0;
    for(ll i = 0; i <= ind; i++){
        res[i] = vec[i];
    }
    res[ind+1] = x;
    for(ll i = ind+1; i < vec.size(); i++){
        res[i+1] = vec[i];
    }
    vec = res;
}

void left_insert(vector<ll> &vec, ll x){
    vector<ll> res(vec.size() + 1);
    rep(i, vec.size()){
        res[i+1] = vec[i];
    }
    res[0] = x;
    vec = res;
}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t, n, q; cin >> t >> n >> q;
    cerr << t << " " << n << " " << q << endl;
    ll x; 
    ll Q;
    rep(T, t){
        
        cerr << "Test in " << T << endl;
        cout << "1 2 3" << endl;
        Q++;
        fflush(stdout);

        cin >> x;
        cerr << x << endl;
        vector<ll> res;
        if(x == 1){
            res = {2, 1, 3};
        }else if(x == 2){
            res = {1, 2, 3};
        }else{
            res = {1, 3, 2};
        }

        for(ll i = 3; i < n; i++){
            
            ll mid = (0 + i-1)/2;
            ll L = 0, R = (i-1);
            cerr << "mid = " << mid << endl;

            while(true){
                ll l = res[mid], r = res[mid+1];
                cout << l << " " << i+1 << " " << r << endl;
                Q++;
                fflush(stdout);
                ll x; cin >> x;
                if(x == (i+1)){
                    //おわり
                    slide(res, mid, (i+1));
                    break;
                }else if(x == l){
                    
                    if(mid == 0){
                        //終わり
                        left_insert(res, (i+1));
                        break;
                    }else{
                        //左にある
                        R = mid;
                        mid = (L + mid) / 2;
                        
                    }
                    
                }else{

                    if(mid == (i-2)){
                        //終わり
                        res.push_back(((i+1)));
                        break;
                    }else{
                        //右にある
                        L = mid;
                        mid = (mid + R) / 2;
                        
                    }
                    
                }
            }

            cerr << "vec size = " << i+1 << endl;


        }
        
        rep(i, n){
            if(i == 0) cout << res[i];
            else cout << " " << res[i];
        }br;
        fflush(stdout);

        cin >> x;
        cerr << "x = " << x << endl;
        if(x == -1){
            exit(0);
        }
    
    }
    cerr << Q << endl;
    

}