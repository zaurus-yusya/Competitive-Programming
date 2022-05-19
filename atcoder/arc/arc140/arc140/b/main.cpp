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
    ll n; cin >> n;
    string s; cin >> s;

    // 奇数の場合 AARCCで回数増やせる
    // 偶数の場合絶対増やせない無理

    // AAAARCCCCを見つける
    vector<ll> vec;
    ll a_cnt = 0;

    for(ll i = 0; i < n; i++){

        if(s[i] == 'R'){

            ll cnt = 0;
            for(ll j = 1; j < n; j++){
                ll next_l = i - j;
                ll next_r = i + j;
                if(next_l < 0 || next_r >= n){
                    break;
                }
                // cerr << s[next_l] << " " << s[next_r] << endl;
                if(s[next_l] == 'A' && s[next_r] == 'C'){
                    cnt++;
                }else{
                    break;
                }
            }
            if(cnt > 0){
                vec.push_back(cnt);
            }         

        }

    }

    sort(all(vec), greater<ll>());
    priority_queue<ll> que; //降順
    map<ll, ll> mp;
    rep(i, vec.size()){
        que.push(vec[i]);
        mp[vec[i]]++;
    }
    if(vec.size() == 0){
        cout << 0 << endl; return 0;
    }

    // for(auto&i: mp){
    //         cout << i.first << " " << i.second << endl;
    //     }

    ll res = 0;
    ll cnt = 1;
    while(true){
        if(cnt % 2 == 1){
            auto itr = mp.rbegin();
            ll x = itr->first;
            ll y = itr->second;

            if(y == 1){
                mp.erase(x);
                if(x > 1){
                    mp[x-1]++;
                }
            }else{
                mp[x] -= 1;
                if(x > 1){
                    mp[x-1]++;
                }
            }

            res++;
        }else{
            auto itr = mp.begin();
            ll x = itr->first;
            ll y = itr->second;
            if(y == 1){
                mp.erase(x);
            }else{
                mp[x] -= 1;
            }
            
            res++;

        }

        // cerr << "--" << endl;
        // for(auto&i: mp){
        //     cout << i.first << " " << i.second << endl;
        // }
        // cerr << "--" << endl;

        if(mp.size() == 0){
            break;
        }
        cnt++;
    }
    cout << res << endl;
    return 0;
    

    ll l_ind = 0;
    ll r_ind = vec.size() - 1;

    if(vec.size() == 0){
        cout << 0 << endl; return 0;
    }

    ll num = 1;
    ll ans = 0;
    while(true){
        if(num % 2 == 1){
            if(vec[l_ind] == 0){
                // 操作できない
                break;
            }else if(vec[l_ind] > 0){
                ans++;
                vec[l_ind]--;
                if(vec[l_ind] == 0){
                    l_ind++;
                }
            }
        }else{
            if(vec[r_ind] == 0){
                // 操作できない
                break;
            }else if(vec[r_ind] > 0){
                ans++;
                vec[r_ind] = 0;
                r_ind--;
            }
        }
        // if(r_ind < l_ind){
        //     break;
        // }

        num++;
    }
    cout << ans << endl;


}