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

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

ll d;
vector<ll> c(26);
vector<vector<ll>> vec(d, vector<ll>(26));

ll calc(vector<ll> t){
    ll res = 0;
    vector<ll> last(26);
    rep(i, d){
        rep(j, 26){
            if(t[i] == j){
                res += vec[i][j];
                last[j] = 0;
            }else{
                last[j]++;
            }
        }
        rep(j, 26){
            res -= c[j]*last[j];
        }
    }
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    
    cin >> d;
    clock_t start = clock();
    rep(i, 26){
        cin >> c[i];
    }
    vec.resize(d, vector<ll>(26));
    rep(i, d){
        rep(j, 26){
            cin >> vec[i][j];
        }
    }

    ll ans = 0;
    vector<ll> last(26);
    vector<ll> t;
    rep(i, d){

        ll max_value = -1;
        ll contest_type = -1;

        //それぞれの日を選んだ場合
        ll max_val = -INF;
        ll tmp_day = -1;
        rep(j, 26){
            ll tmp = 0;

            rep(k, 26){
                if(j == k){
                    tmp += vec[i][j];
                }
                else{
                    tmp -= c[k] * (last[k] + 1);
                }
            }
            if(max_val < tmp){
                max_val = tmp;
                tmp_day = j;
            }
        }

        //cout << tmp_day + 1 << endl;
        t.push_back(tmp_day);
        ans += max_val;

        //後処理
        rep(j, 26){
            if(j == tmp_day){
                last[j] = 0;
            }else{
                last[j]++;
            }
        }
    }

    

    //cout << ans << endl;

    while(true){

        srand(time(NULL));
        ll before = rand() % 26 + 1;
        ll after = rand() % 26 + 1;
        if(t[before] != after){
            ll old = t[before];
            t[before] = after;

            ll res = 0;
            res = calc(t);

            if(ans < res){
                ans = res;
            }else{
                t[before] = old;
            }
        }

        clock_t end = clock();
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        //printf("time %lf[ms]\n", time);
        if(time > 1950){
            break;
        }
    }

    rep(i, t.size()){
        cout << t[i] + 1 << endl;
    }
    
    
    
    
    /*
    clock_t end = clock();
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("time %lf[ms]\n", time);
    */


}