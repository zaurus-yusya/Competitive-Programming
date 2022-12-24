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

ll h, w; 
vector<ll> dy = {1, -1, 0, 0};
vector<ll> dx = {0, 0, 1, -1};
ll sy, sx;

vector<vector<ll>> seen;

bool f = false;
void dfs(vector<vector<char>> &vec, ll y, ll x, ll py, ll px){
    seen[y][x] = 1;

    rep(i, 4){
        ll ny = y + dy[i];
        ll nx = x + dx[i];
        
        if(ny < 0 || ny >= h || nx < 0 || nx >= w){
            continue;
        }
        if(vec[ny][nx] == '#'){
            continue;
        }

        if(ny == py && nx == px){
            continue;
        }

        if(ny == sy && nx == sx){
            f = true;
        }

        if(seen[ny][nx] == 0){
            dfs(vec, ny, nx, y, x);
            // seen[ny][nx] = 0;
        }
        /*
        else{
            cerr << ny << " " << nx << " " << y << " " << x << endl;
            f = true;
        }
        */
    }

}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> h >> w;
    vector<vector<char>> vec(h, vector<char>(w));
    
    rep(i, h){
        rep(j, w){
            cin >> vec[i][j];
            if(vec[i][j] == 'S'){
                sy = i; sx = j;
            }
        }
    }

    seen.assign(h, vector<ll>(w, 0));

    dfs(vec, sy, sx, -1, -1);

    if(f){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }




    






}

/*
    queue< pair<ll,ll> > que;
    dist[0][0] = 0;
    que.push(make_pair(0,0));

    while(!que.empty()){
        pair<ll,ll> now_pos = que.front();
        ll now_y = now_pos.first;
        ll now_x = now_pos.second;
        que.pop();

        rep(i,4){
            ll ny = now_y + dy[i];
            ll nx = now_x + dx[i];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w){
                continue;
            }
            if(vec[ny][nx] == '#'){
                continue;
            }

            if(dist[next_pos_y][next_pos_x] != -1){
                continue;
            }


        }
    }
    */