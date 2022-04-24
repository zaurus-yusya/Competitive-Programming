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
    ll n, k; cin >> n >> k;
    vector<ll> t(n);
    vector<ll> y(n);
    vector<ll> sum(n+1);
    rep(i, n){
        cin >> t[i] >> y[i];
    }

    vector<ll> tind;
    vector<ll> yy(n);

    rep(i, n){
        if(t[i] == 1){
            tind.push_back(i);
            yy[i] = 0;
        }else{
            yy[i] = y[i];
        }
        sum[i+1] = sum[i] + yy[i];
    }

    // vecdbg(tind);
    // vecdbg(yy);
    // vecdbg(sum);

    // nokoriは1個ずつ増える

    ll ans = -INF;
    priority_queue<ll> que; //降順に変えた

    // tindの後ろから考える
    ll mae = n;
    ll negasum = 0;
    for(ll i = tind.size() - 1; i >= 0; i--){
        // 無視する回数
        ll mushi = tind.size() - i - 1;
        // cerr << "mushi = " << mushi << endl;
        ll nokori = k - mushi; // nokoriは1ずつ減っていく
        // cerr << "nokori = " << nokori << endl;


        // queに追加する
        // queがnokori個を超えてあったら削除する
        while(que.size() > nokori){
            ll x = que.top();
            negasum += -1 * x;
            que.pop();
        }
        // nokoriを考慮してsumを計算
        for(ll j = tind[i]; j < mae; j++){
            // cerr << "j = " << j << endl;
            if(t[j] == 2){
                if(y[j] < 0){

                    if(que.size() < nokori){
                        que.push(y[j]);
                        negasum += y[j];
                    }else{
                        if(que.empty()){
                            if(nokori == 0){
                            
                            }else{
                                negasum += y[j];
                                que.push(y[j]);
                            }
                            continue;
                        }
                        ll x = que.top();
                        if(x > y[j]){
                            negasum += -1 * x;
                            que.pop();
                            negasum += y[j];
                            que.push(y[j]);
                        }
                    }
                    
                }
            }
        }
        
        ll now = y[tind[i]];
        // cerr << "now = " << now << endl;
        ll res = now + sum[n] - sum[tind[i]];
        // cerr << "res = " << res << endl;
        // cerr << "negasum = " << negasum << endl;
        ans = max(ans, res - negasum);

        //ans = max(ans, res);
        // cerr << "----" << endl;
        mae = tind[i];

    }

    // t=1を一個も使わない場合
    ll mushi = tind.size();
    ll nokori = k - mushi;
    // cerr << "nokori = " << nokori << endl;
    // queに追加する
    // queがnokori個を超えてあったら削除する
    
    while(que.size() > nokori){
        ll x = que.top();
        negasum += -1 * x;
        que.pop();
    }
    for(ll j = 0; j < mae; j++){
        // cerr << "j = " << j << endl;
        if(t[j] == 2){
            if(y[j] < 0){

                if(que.size() < nokori){
                    que.push(y[j]);
                    negasum += y[j];
                }else{
                    if(que.empty()){
                        if(nokori == 0){
                            
                        }else{
                            negasum += y[j];
                            que.push(y[j]);
                        }
                        continue;
                    }
                    ll x = que.top();
                    if(x > y[j]){
                        negasum += -1 * x;
                        que.pop();
                        negasum += y[j];
                        que.push(y[j]);
                    }
                }
                
            }
        }
    }
    ll now = 0;
    ll res = now + sum[n] - sum[0];
    ans = max(ans, res - negasum);

    /*
    vector<ll> tmp;
    for(ll j = 0; j < nokori; j++){
        ll x = que.top();
        if(x >= 0){
            break;
        }else{
            tmp.push_back(x);
        }
    }
    rep(j, tmp.size()){
        res += (-1) * tmp[j];
        // que.push(tmp[j]);
    }
    ans = max(ans, res);
    */


    //はじめ0
    //2回置き換えると最後の置き換えたところだけ

    //全部の場所で1回置き換える時を考える

    cout << ans << endl;


}