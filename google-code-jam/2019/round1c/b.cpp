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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t, f; cin >> t >> f;

    // 120通り //119個の順列が横並び
    // 5 * 119 = 595
    // 4 * 119 = 476
    // 残りの1個を探す
    // 
    // 119 + 23 + 5 + 1 = 
    // 120 / 5 = 24
    // 24 / 4 = 6
    // 6 / 3 = 2
    // 2 / 1 = 1
    vector<ll> num = {24, 6, 2, 1};
    map<char, ll> mp; mp['A'] = 0; mp['B'] = 1; mp['C'] = 2; mp['D'] = 3; mp['E'] = 4;
    map<ll, char> mpr; mpr[0] = 'A'; mpr[1] = 'B'; mpr[2] = 'C'; mpr[3] = 'D'; mpr[4] = 'E';
    rep(T, t){
        vector<vector<ll>> bef(5);
        vector<vector<ll>> vec(5); // A:0 B:1 C:2 D:3 E:4

        string ans = ""; //答え
        map<char, ll> ansmp;

        
        ll now = 0;
        ll ind = -1;
        ll cnt = 0;

        //1文字目を探す
        for(ll i = 1; i <= 595; i+= 5){
            cout << i << endl; cerr << i << endl; cnt++;
            flush(std::cout);
            char c; cin >> c; cerr << c << endl;
            if(c == 'N') return 0;
            vec[mp[c]].push_back(i);
        }
        cerr << "decide " << cnt << endl;
        rep(i, 5){
            if(vec[i].size() == num[now] - 1){
                char x = mpr[i];
                ans += x; ind = i; ansmp[x]++;
                cerr << "X = " << x << " now = " << now << " ind = " << ind << " size = " << vec[i].size() << endl;
            }
        }
        bef = vec;
        rep(i, 5){
            vec[i].clear();
        }
        now++;


        //2文字目以降を探す
        cerr << "in" << endl;
        for(ll tmp = 0; tmp < 3; tmp++){
            for(ll i = 0; i < bef[ind].size(); i++){
                cout << bef[ind][i]+1 << endl; cerr << bef[ind][i]+1 << endl; cnt++;
                flush(std::cout);
                char c; cin >> c; cerr << c << endl;
                if(c == 'N') return 0;
                vec[mp[c]].push_back(bef[ind][i]+1);
            }
            cerr << "decide " << cnt << endl;
            rep(i, 5){
                //cerr << "vec size = " << vec[i].size() << endl;
                if(vec[i].size() == num[now] - 1){
                    char x = mpr[i];
                    if(ansmp[x] > 0) continue;
                    ans += x; ind = i; ansmp[x]++;
                    cerr << "X = " << x << " now = " << now << " ind = " << ind << " size = " << vec[i].size() << endl;
                }
            }
            bef = vec;
            rep(i, 5){
                vec[i].clear();
            }
            now++;
        }

        //最後の文字
        rep(i, 5){
            char x = mpr[i];
            if(ansmp[x] > 0) continue;
            ans += x;
        }
        
        cout << ans << endl; cerr << ans << endl;
        char c; cin >> c;

        if(c == 'N'){
            return 0;
        }else if(c == 'Y'){
            continue;
        }
    }


}