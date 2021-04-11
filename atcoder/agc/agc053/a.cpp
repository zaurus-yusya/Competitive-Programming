#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
    ll n; cin >> n;
    string s; cin >> s;
    vector<long long> a(n+1);
    for(long long i = 0; i < n+1; i ++){
        cin >> a[i];
    }
    //10000

    vector<ll> sa(n);
    ll mi = INF;
    for(ll i = 0; i < n; i++){
        sa[i] = abs(a[i+1] - a[i]);
        //chmin(mi, sa[i]);
        if(i != 0 && i != n-1){
            chmin(mi, sa[i]);
        }
    }

    //vecdbg(sa);

    


    vector<ll> res(n+1);

    for(ll i = 0; i < n+1; i++){
        if(s[i] == '<'){
            chmax(res[i+1], res[i] + 1);
        }
    }
    for(ll i = n; i >= 0; i--){
        if(s[i] == '>'){
            chmax(res[i], res[i+1] + 1);
        }
    }

    cerr << "a ";
    vecdbg(a);
    cerr << "res ";
    vecdbg(res);
    cerr << "sa ";
    vecdbg(sa);

    vector<ll> ressa(n);
    for(ll i = 0; i < n; i++){
        ressa[i] = abs(res[i+1] - res[i]);
    }
    cerr << "ressa ";
    vecdbg(ressa);


    //resの端っこだけ処理
    //mi-1回が最高
    

    
    //a定数
    //sa定数
    //res定数
    ll ans = 0;
    ll ans0 = 0, ansn = 0, ansnum = 0;

    if(s[0] == '<' && s[n-1] == '>'){
        for(ll i = res[0]; i < res[1]; i++){
            for(ll j = res[n]; j < res[n-1]; j++){

                cerr << i << " " << j << " in" << endl;
                
                res[0] = i; res[n] = j;

                ll num = 0;

                vector<ll> tmp = a;
                while(true){
                    bool flag = true;
                    for(ll k = 0; k < n+1; k++){
                        if(tmp[k] - res[k] >= 0){
                            tmp[k] = tmp[k] - res[k];
                        }else{
                            bool flag = false;
                        }

                        if(k > 0){
                            if(s[k-1] == '<' && tmp[k-1] >= tmp[k]){
                                flag = false;
                            }
                            if(s[k-1] == '>' && tmp[k-1] <= tmp[k]){
                                flag = false;
                            }
                        }
                    }

                    if(flag){
                        num++;
                    }else{
                        break;
                    }
                }

                cerr << "num = " << num << endl;

                if(ans < num){
                    ans = num;
                    ans0 = i; ansn = j; ansnum = num;
                }

            }
        }
    }else if(s[0] == '<'){
        for(ll i = res[0]; i < res[1]; i++){
            res[0] = i;
            
            ll num = 0;
            vector<ll> tmp = a;

            while(true){
                bool flag = true;
                for(ll k = 0; k < n+1; k++){
                    if(tmp[k] - res[k] >= 0){
                        tmp[k] = tmp[k] - res[k];
                    }else{
                        bool flag = false;
                    }

                    if(k > 0){
                        if(s[k-1] == '<' && tmp[k-1] >= tmp[k]){
                            flag = false;
                        }
                        if(s[k-1] == '>' && tmp[k-1] <= tmp[k]){
                            flag = false;
                        }
                    }
                }

                if(flag){
                    num++;
                }else{
                    break;
                }
            }
            cerr << "num = " << num << endl;

            if(ans < num){
                ans = num;
                ans0 = i; ansnum = num;
            }
        }
        ansn = res[n];
    }else if(s[n-1] == '>'){
        for(ll j = res[n]; j < res[n-1]; j++){
            res[n] = j;

            ll num = 0;

            vector<ll> tmp = a;
            while(true){
                bool flag = true;
                for(ll k = 0; k < n+1; k++){
                    if(tmp[k] - res[k] >= 0){
                        tmp[k] = tmp[k] - res[k];
                    }else{
                        bool flag = false;
                    }

                    if(k > 0){
                        if(s[k-1] == '<' && tmp[k-1] >= tmp[k]){
                            flag = false;
                        }
                        if(s[k-1] == '>' && tmp[k-1] <= tmp[k]){
                            flag = false;
                        }
                    }
                }

                if(flag){
                    num++;
                }else{
                    break;
                }
            }

            cerr << "num = " << num << endl;

            if(ans < num){
                ans = num;
                ansn = j; ansnum = num;
            }
        }
        ans0 = res[0];
    }else{
        res[0] = res[0]; res[n] = res[n];

        ll num = 0;

        vector<ll> tmp = a;
        while(true){
            bool flag = true;
            for(ll k = 0; k < n+1; k++){
                if(tmp[k] - res[k] >= 0){
                    tmp[k] = tmp[k] - res[k];
                }else{
                    bool flag = false;
                }

                if(k > 0){
                    if(s[k-1] == '<' && tmp[k-1] >= tmp[k]){
                        flag = false;
                    }
                    if(s[k-1] == '>' && tmp[k-1] <= tmp[k]){
                        flag = false;
                    }
                }
            }

            if(flag){
                num++;
            }else{
                break;
            }
        }

        cerr << "num = " << num << endl;

        if(ans < num){
            ans = num;
            ansnum = num;
        }

        ans0 = res[0]; ansn = res[n];
    }

    //ans
    if(ans == 0){
        cout << 1 << endl;
        rep(i, n+1){
            if(i == 0){
                cout << a[i];
            }else{
                cout << " " << a[i];
            }
        }br;
    }else{
        cout << ans + 1 << endl;
        res[0] = ans0;
        res[n] = ansn;
        rep(i, ansnum){
            rep(j, n+1){
                if(j == 0){
                    cout << res[j];
                }else{
                    cout << " " << res[j];
                }
            }br;
        }
        rep(j, n+1){
            if(j == 0){
                cout << a[j] - ansnum * res[j];
            }else{
                cout << " " << a[j] - ansnum * res[j];
            }
        }br;

    }

}