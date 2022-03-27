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
    ll n, m; cin >> n >> m;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<long long> b(n);
    for(long long i = 0; i < n; i ++){
        cin >> b[i];
    }

    map<ll, map<ll, ll>> box;
    vector<long long> c(m);
    for(long long i = 0; i < m; i ++){
        cin >> c[i];
    }
    vector<long long> d(m);
    for(long long i = 0; i < m; i ++){
        cin >> d[i];
    }
    vector<P> aft(m);
    rep(i, m){
        aft[i] = {c[i], d[i]};
    }

    rep(i, m){
        box[c[i]][d[i]]++;
    }

    

    bool f = true;
    rep(i, n){
        //cerr << "--" << endl;
        //cerr << a[i] << endl;
        auto it = box.lower_bound(a[i]);
        cerr << it->first << endl;
        if(it == box.end()){
            f = false; break;
        }

        //auto it2 = box[it->first].lower_bound(b[i]);
        bool tmp = false;
        while(it != box.end()){
            auto it2 = box[it->first].lower_bound(b[i]);
            if(it2 == box[it->first].end()){

            }else{
                box[it->first][it2->first]--;
                if( box[it->first][it2->first] == 0){
                    box[it->first].erase(it2->first);

                    if(box[it->first].size() == 0){
                        cerr << "in" << endl;
                        box.erase(it->first);
                    }
                }
                tmp = true; break;
            }
            it++;
        }
        if(!tmp){
            f = false; break;
        }
        /*
        if(it2 == box[it->first].end()){
            f = false; break;
        }
        */

       /*
        box[it->first][it2->first]--;
        if( box[it->first][it2->first] == 0){
            box[it->first].erase(it2->first);

            if(box[it->first].size() == 0){
                cerr << "in" << endl;
                box.erase(it->first);
            }
        }
        */


    }

    if(f){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    // cout << box[5][0] << endl;
    // cout << box[5][5] << endl;
    /*
    for(auto& i: box){
        cout << i.first << endl;
    }

    auto it = box.lower_bound(100);

    cout << it->first << endl;
    if(it == box.end()){
        cout << "ok" << endl;
    }
    */





}

/*

    vector<P> bef(n);
    rep(i, n){
        bef[i] = {a[i], b[i]};
    }

        vector<P> aft(m);
    rep(i, n){
        aft[i] = {c[i], d[i]};
    }

    sort(all(bef));
    sort(all(aft));

        rep(i, n){
        a[i] = bef[i].first;
        b[i] = bef[i].second;
    }


    rep(i, m){
        c[i] = aft[i].first;
        d[i] = aft[i].second;
        box[c[i]][d[i]]++;
    }


    */