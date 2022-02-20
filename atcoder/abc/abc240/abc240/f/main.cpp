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
    ll t; cin >> t;
    rep(T, t){
        ll n, m; cin >> n >> m;
        vector<ll> x(n);
        vector<ll> y(n);

        vector<ll> kou(n+1);
        rep(i, n){
            cin >> x[i] >> y[i];
            kou[i+1] = kou[i] + y[i];
        }

        //最初の一項目が基準になる
        ll ans = x[0];

        //最後だけ考慮する
        vector<ll> b(n+1);
        rep(i, n){
            ll tmp = x[i] * y[i];
            b[i+1] = b[i] + tmp; 
        }

        // cout << "x: "; vecdbg(x);
        // cout << "y: "; vecdbg(y);
        // cout << "k: "; vecdbg(kou);
        // cout << "b: "; vecdbg(b);

        //+ギリギリの項を求める
        vector<ll> kento;

        for(ll i = 0; i < n-1; i++){
            //Xが+から-になっているところを見る
            if(x[i] >= 0 && x[i+1] < 0){

                //i番目までの合計値
                ll goukei = b[i+1];
                //i番目までの項数
                ll nowkou = kou[i+1];

                ll tmp = 0;
                
                for(ll j = i+1; j < n; j++){


                    //次にマイナスが続くのが後なんこうあるか
                    ll hiku = x[j];
                    ll kosu = y[j];
                    // cout << goukei << endl;
                    // cout << hiku * kosu << endl;

                    if(goukei + (hiku * kosu) >= 0){
                        // cout << "in" << endl;
                        nowkou = kou[j+1];
                        goukei = hiku*kosu; continue;
                        
                    }else{
                        // cout << "inn" << endl;
                        //あとなんこうでギリギリか
                        ll girikou = goukei / abs(hiku);
                        nowkou += girikou;
                        break;
                    }
                }

                kento.push_back(nowkou);

            }
        }

        vector<ll> kake(n);
        vector<ll> kakesum(n+1);
        rep(i, n){
            kake[i] = x[i] * y[i];
            kakesum[i+1] = kake[i] + kakesum[i];
        }
        vecdbg(kake);
        vecdbg(kakesum);

        vecdbg(kento);


        //kentoの中身を求めてmax(ans, x)
        vector<ll> a(n+1);
        rep(i, n){
            if(i == 0){
                a[i+1] = a[i] + x[i] * (1+y[i])*y[i]/2;
            }else{
                a[i+1] = a[i] +  x[i] * (1+y[i])*y[i]/2 + kakesum[i] * y[i];
            }
            
        }

        vecdbg(a);
        for(ll i = 0; i < kento.size(); i++){
            ll tmp = kento[i]; //tmpこうめまで
            ll dis = lower_bound(kou.begin(), kou.end(), kento[i]) - kou.begin();

            if(kou[dis] != tmp) dis--;

            ll ato = tmp - kou[dis];
            // cout << dis << endl;
            // cout << x[dis] * (1 + ato) * ato / 2 << endl;
            // cout << kakesum[dis] * ato << endl;
            ll res = kakesum[dis] + x[dis] * (1 + ato) * ato / 2 + a[dis] * ato;
            ans = max(res, ans);
        }

        ans = max(ans, a[a.size() - 1]);
        cout << ans << endl;



    }

}