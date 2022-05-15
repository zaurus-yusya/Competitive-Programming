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
ll n, k;
vector<ll> dy = {0, 1, 0, -1};
vector<ll> dx = {1, 0, -1, 0};

vector<ll> dyy = {1, 0, -1, 0};
vector<ll> dxx = {0, -1, 0, 1};

vector<pair<ll, ll>> ans;
vector<pair<ll, ll>> tmp;
bool f = false;
void dfs(vector<vector<ll>> &vec, ll num, ll nowy, ll nowx){
    if(num > k){ //既に超えてたらreturn
        return;
    }
    ll x = vec[nowy][nowx]; 
    if(num + n*n-x < k){ //これから近道しなくていってもkに満たないときreturn
        return;
    }


    if(vec[nowy][nowx] == n*n){
        if(num == k){
            ans = tmp;
            f = true;
        }
        return;
    }

    if(f){
        return;
    }

    rep(i, 4){
        ll nexty = nowy + dyy[i];
        ll nextx = nowx + dxx[i];

        // 場外ならcontinue
        if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n){
            continue;
        }
        // 行けないならcontinue
        if(vec[nowy][nowx] >= vec[nexty][nextx]){
            continue;
        }

        // 近道ならtmpに入れる
        if(vec[nowy][nowx] + 1 != vec[nexty][nextx]){
            // 近道
            tmp.push_back({vec[nowy][nowx], vec[nexty][nextx]});
            dfs(vec, num+1, nexty, nextx);
            tmp.pop_back();
        }else{
            // 近道じゃない
            dfs(vec, num+1, nexty, nextx);
        }

        if(f){
            return;
        }
    }

    if(f){
        return;
    }


}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        cin >> n >> k;
        ll mi = n-1;
        ll ma = n*n-3;
        if(k % 2 == 1){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
            continue;
        }
        if(k < n-1){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
            continue;
        }

        vector<vector<ll>> vec(n, vector<ll>(n));
        vector<vector<ll>> dist(n, vector<ll>(n));

        ll muki = 0;
        ll cnt = 1;
        ll nowy = 0, nowx = 0;
        while(true){
            vec[nowy][nowx] = cnt;
            dist[nowy][nowx] = 1;

            ll nexty = nowy + dy[muki];
            ll nextx = nowx + dx[muki];
            // 場外なら向き替える
            if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n){
                muki = (muki+1) % 4;
            }
            // 訪問済みなら向き替える
            else if(dist[nexty][nextx] == 1){
                muki = (muki+1) % 4;
            }

            // nowy nowx更新
            nowy = nowy + dy[muki];
            nowx = nowx + dx[muki];

            cnt++;
            if(cnt > n*n){
                break;
            }
        }

        // rep(i, n){
        //     rep(j, n){
        //         cout << vec[i][j] << " ";
        //     }br;
        // }

        ans.clear();
        tmp.clear();
        f = false;
        dfs(vec, 0, 0, 0);

        if(ans.size() == 0){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
        }else{
            cout << "Case #" << T+1 << ": " << ans.size() << '\n';
            rep(i, ans.size()){
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }



    }

}