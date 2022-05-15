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
const long long INF = 8e18 + 1;
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        if(n > 10){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
            continue;
        }
        vector<pair<ll, ll>> child(n);
        vector<pair<ll, ll>> sweet(n+1);
        rep(i, n){
            ll x, y; cin >> x >> y;
            child[i] = {x, y};
        }
        rep(i, n+1){
            ll x, y; cin >> x >> y;
            sweet[i] = {x, y};
        }

        vector<vector<ll>> distance(n, vector<ll>(n+1)); // i : child, j: sweet
        rep(i, n){
            rep(j, n+1){
                distance[i][j] = abs(child[i].first - sweet[j].first) * abs(child[i].first - sweet[j].first) + abs(child[i].second - sweet[j].second) * abs(child[i].second - sweet[j].second);
            }
        }

        // TODO に一番近いsweetが0だったらもうダメ
        // rep(i, n){
        //     ll tmp_dis = INF;
        //     ll assign_sweet = -1; // 距離的にアサインされるお菓子
        //     rep(j, n){
        //         if(tmp_dis > distance[i][j]){
        //             // 真に小さかったらそのお菓子がアサインされる
        //             assign_sweet = j;
        //             tmp_dis = distance[i][j];
        //         }
        //     }
        // }

        // rep(i, n){
        //     rep(j, n+1){
        //         cout << "child " << i << " sweet " << j << endl;
        //         cout << distance[i][j] << endl;
        //     }
        // }


        vector<ll> vec(n);
        rep(i, n){
            vec[i] = i+1;
        }

        vector<pair<ll, ll>> ANS;

        do{
            // for(ll i = 0; i < n; i++){ //子供iにvec[i]のお菓子割り当て
            //     cout << "child " << i << " assigned " << vec[i] << ", ";
            // }
            // cout << endl;

            bool f = true;
            map<ll, ll> not_assigned_child;
            map<ll, ll> not_assigned_sweet;
            rep(i, n){
                not_assigned_child[i] = 1;
            }
            rep(i, n+1){
                not_assigned_sweet[i] = 1;
            }
            
            vector<pair<ll, ll>> ans; // 答え　アサインした順番にpush_back
            for(ll ii = 0; ii < n; ii++){
                // iiの1ループで1人の子供にアサインする。できなかったらムリ
                bool can_assign = false;
                ll tmp_dis = INF;

                for(auto& i : not_assigned_child){
                    ll x = vec[i.first]; // iの子供にアサインしたいお菓子

                    ll tmp_dis = INF;
                    ll assign_sweet = -1; // 距離的にアサインされるお菓子

                    for(auto& j : not_assigned_sweet){
                        // cerr << "child " << i.first << " sweet " << j.first << " distance " << distance[i.first][j.first] << endl;
                        if(tmp_dis > distance[i.first][j.first]){
                            // 真に小さかったらそのお菓子がアサインされる
                            assign_sweet = j.first;
                            tmp_dis = distance[i.first][j.first];
                        }else if(tmp_dis == distance[i.first][j.first]){
                            // 距離が同じだったらアサイン予定のものだったらアサインする
                            if(j.first == x){
                                assign_sweet = j.first;
                            }
                            else if(j.first != 0){
                                assign_sweet = j.first;
                            }
                        }
                    }

                    if(assign_sweet == x){
                        // アサインできた
                        not_assigned_child.erase(i.first);
                        not_assigned_sweet.erase(assign_sweet);
                        can_assign = true;

                        ans.push_back({i.first, assign_sweet});
                        break;
                    }
                    else if(assign_sweet == 0){
                        // 0がアサイン予定になってたらもうダメ
                        break;
                    }
                }

                if(!can_assign){
                    break;
                }
            }

            if(ans.size() != n){
                continue;
            }else{
                ANS = ans;
                break;
            }

        }while(next_permutation(vec.begin(), vec.end()));

        if(ANS.size() == n){
            cout << "Case #" << T+1 << ": " << "POSSIBLE" << '\n';
            rep(i, ANS.size()){
                cout << ANS[i].first + 1 << " " << ANS[i].second + 1 << '\n';
            }
        }else{
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
        }


    }

}