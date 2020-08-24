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
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    ll y, x, c; cin >> y >> x >> c; y--; x--;
    vector<vector<ll>> vec(n, vector<ll>(m));
    rep(i, n){
        rep(j, m){
            cin >> vec[i][j];
        }
    }

    if(vec[y][x] == c){
        ll cnt = 0;
        rep(i, n)rep(j, m){
            if(vec[i][j] == 1) cnt++;
        }
        cout << cnt << endl;
        return 0;
    }

    vector<vector<ll>> dist(n, vector<ll>(m, -1));

    queue<pair<ll, ll>> que;
    dist[y][x] = 1;
    que.push(make_pair(y, x));

    vector<ll> dx = {1, -1, 0, 0};
    vector<ll> dy = {0, 0, 1, -1};

    while(!que.empty()){
        pll p = que.front();
        ll now_y = p.first, now_x = p.second;
        vec[now_y][now_x] = c;
        que.pop();
        
        for(ll i = 0; i < 4; i++){
            ll next_y = now_y + dy[i];
            ll next_x = now_x + dx[i];
            //壁ならcontinue
            if(next_y < 0 || next_y >= n) continue;
            if(next_x < 0 || next_x >= m) continue;

            //訪問済みならcontinue
            if(dist[next_y][next_x] != -1) continue;

            //同じ色ならcontinue
            if(vec[next_y][next_x] == c) continue;

            //push
            dist[next_y][next_x] = 1;
            que.push(make_pair(next_y, next_x));
        }
    }

    ll ans = 0;
    rep(i, n){
        rep(j, m){
            if(vec[i][j] == 1) ans++;
        }
    }

    cout << ans << endl;

}