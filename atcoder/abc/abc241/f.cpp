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
    ll h, w, n; cin >> h >> w >> n;
    ll sy, sx; cin >> sy >> sx;
    ll gy, gx; cin >> gy >> gx;
    //map<P, ll> mp;
    map<ll, vector<ll>> mpgyo;
    map<ll, vector<ll>> mpretsu;
    
    rep(i, n){
        ll y, x; cin >> y >> x;
        mpgyo[y].push_back(x);
        mpretsu[x].push_back(y);
    }
    
    for(auto& i: mpgyo){
        sort(all(i.second));
    }
    for(auto& i: mpretsu){
        sort(all(i.second));
    }

    queue<pair<ll, ll>> que;
    que.push({sy, sx});

    map<P, ll> dist;
    dist[{sy, sx}] = 1;

    while(!que.empty()){
        P now = que.front();
        que.pop();
        ll nowy = now.first;
        ll nowx = now.second;
        ll nexty = nowy;
        ll nextx = nowx;

        //cerr << "now = " << nowy << " " << nowx << endl;

        //上
        nexty = nowy, nextx = nowx;
        ll dis = lower_bound(mpretsu[nowx].begin(), mpretsu[nowx].end(), nowy) - mpretsu[nowx].begin();
        bool f = true;
        dis--;
        if(dis == -1){
            nexty = 1; f = false;
        }else{
            nexty = mpretsu[nowx][dis] + 1;
        }
        if(dist[{nexty, nextx}] > 0 || !f){

        }else{
            dist[{nexty, nextx}] = dist[{nowy, nowx}] + 1;
            que.push({nexty, nextx});
        } 

        //下
        nexty = nowy, nextx = nowx;
        dis = lower_bound(mpretsu[nowx].begin(), mpretsu[nowx].end(), nowy) - mpretsu[nowx].begin();
        f = true;
        if(dis == mpretsu[nowx].size()){
            nexty = h; f = false;
        }else{
            nexty = mpretsu[nowx][dis] - 1;
        }
        if(dist[{nexty, nextx}] > 0 || !f){

        }else{
            dist[{nexty, nextx}] = dist[{nowy, nowx}] + 1;
            que.push({nexty, nextx});
        } 

        //右
        nexty = nowy, nextx = nowx;
        dis = lower_bound(mpgyo[nowy].begin(), mpgyo[nowy].end(), nowx) - mpgyo[nowy].begin();
        f = true;
        if(dis == mpgyo[nowy].size()){
            nextx = w; f = false;
        }else{
            nextx = mpgyo[nowy][dis] - 1;
        }
        if(dist[{nexty, nextx}] > 0 || !f){

        }else{
            dist[{nexty, nextx}] = dist[{nowy, nowx}] + 1;
            que.push({nexty, nextx});
        } 


        //左
        nexty = nowy, nextx = nowx;
        dis = lower_bound(mpgyo[nowy].begin(), mpgyo[nowy].end(), nowx) - mpgyo[nowy].begin();
        f = true;
        dis--;
        if(dis == -1){
            nextx = 1; f = false;
        }else{
            nextx = mpgyo[nowy][dis] + 1;
        }
        if(dist[{nexty, nextx}] > 0 || !f){

        }else{
            dist[{nexty, nextx}] = dist[{nowy, nowx}] + 1;
            que.push({nexty, nextx});
        } 

    }

    cout << dist[{gy, gx}]-1 << endl;


}