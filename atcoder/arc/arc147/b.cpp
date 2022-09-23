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
    vector<long long> p(n);
    for(long long i = 0; i < n; i ++){
        cin >> p[i];
    }

    // Aの回数を求める
    ll cnt = 0;
    rep(i, n){
        if(i % 2 == 0){
            if(p[i] % 2 == 0){
                cnt++;
            }
        }else{
            if(p[i] % 2 == 1){
                cnt++;
            }
        }
    }
    ll a_num = cnt/2;

    vector<pair<char, ll>> ans;
    //　Aを左端で交換
    cnt = 0;
    while(cnt < a_num){
        // 見つける
        ll fi = -1;
        for(ll i = 0; i < n; i+= 2){
            if(p[i] % 2 == 0){
                fi = i; break;
            }
        }
        // 持ってくる
        while(fi != 0){
            swap(p[fi-2], p[fi]);
            ans.push_back({'B', fi-2});
            fi -= 2;
        }

        // 見つける
        ll se = -1;
        for(ll i = 1; i < n; i+= 2){
            if(p[i] % 2 == 1){
                se = i; break;
            }
        }

        // 持ってくる
        while(se != 1){
            swap(p[se-2], p[se]);
            ans.push_back({'B', se-2});
            se -= 2;
        }


        // 入れ替える
        swap(p[0], p[1]);
        ans.push_back({'A', 0});

        cnt++;
    }


    // 偶奇で独立してB
    vector<ll> odd;
    for(ll i = 0; i < n; i += 2){
        odd.push_back(p[i]);
    }

    vector<ll> even;
    for(ll i = 1; i < n; i += 2){
        even.push_back(p[i]);
    }
    
    ll flag = 1;
    ll N = odd.size();
    while(flag){
        flag = 0;
        for(ll j = N-1; j > 0; j--){
            if(odd[j] < odd[j-1]){
                ans.push_back({'B', (j-1)*2});
                swap(odd[j], odd[j-1]);
                flag = 1;
            }
        }
    }
    
    flag = 1;
    N = even.size();
    while(flag){
        flag = 0;
        for(ll j = N-1; j > 0; j--){
            if(even[j] < even[j-1]){
                ans.push_back({'B', (j-1)*2 + 1});
                swap(even[j], even[j-1]);
                flag = 1;
            }
        }
    }

    // vecdbg(odd);
    // vecdbg(even);

    cout << ans.size() << '\n';
    rep(i, ans.size()){
        cout << ans[i].first << ' ' << ans[i].second+1 << '\n';
    }


}