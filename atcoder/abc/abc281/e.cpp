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
    ll n, m, k; cin >> n >> m >> k; // k <= m <= n
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i]; // 1e9
    }

    if(n == 1){
        cout << a[0] << endl;
        return 0;
    }

    if(m == 1){
        rep(i, n){
            cout << a[i] << " ";
        }br;
        return 0;
    }


    priority_queue<ll> small;
    priority_queue<ll, vector<ll>, greater<ll>> large; //昇順

    map<ll, ll> kesu_s;
    map<ll, ll> kesu_l;

    ll ans = 0;
    vector<ll> res(n - m + 1);
    ll bef_desired = k;
    for(ll i = 0; i < n - m + 1; i++){
        cerr << "i = " << i << endl;

        if(i == 0){
            for(ll j = 0; j <= i + m - 1; j++){
                // cerr << "size " << small.size() << endl;
                if(small.size() < k){
                    small.push(a[j]);
                    // cerr << "push s " << a[j] << endl;
                    ans += a[j];
                }else{
                    // cerr << "in" << endl;
                    // k番目の値
                    ll val = small.top();
                    // cerr << "val = " << val << endl;

                    if(a[j] < val){
                        small.pop();
                        // cerr << "pop s " << val << endl;
                        ans -= val;
                        // cerr << "push s " << a[j] << endl;
                        small.push(a[j]);
                        ans += a[j];

                        // cerr << "push l " << val << endl;
                        large.push(val);
                    }else{
                        // cerr << "push l " << a[j] << endl;
                        large.push(a[j]);
                    }
                }
            }
            res[i] = ans;
        }else{
            // cerr << "size = " << small.size() << " " << large.size() << endl;
            // 左端消す
            ll tmp = small.top();
            ll desired_size = bef_desired;
            if(a[i-1] <= tmp){
                // small queから1個消えるはず
                kesu_s[a[i-1]]++;
                ans -= a[i-1];
                // cerr << "kesu s " << a[i-1] << endl;
                // cerr << "ans_bef " << ans << endl;

                desired_size++;
            }else{
                kesu_l[a[i-1]]++;
            }
            ///////////

            // cerr << "desired_size " << desired_size << endl;
            

            ll val;
            // smallのqueの最も大きいvalを求める。消す予定のやつだったら消す
            while(true){
                ll tmp = small.top();
                if(kesu_s.count(tmp) > 0){
                    // cerr << "pop s " << tmp << endl;
                    small.pop();
                    desired_size--;
                    kesu_s[tmp]--;
                    if(kesu_s[tmp] == 0){
                        kesu_s.erase(tmp);
                    }
                }else{
                    val = tmp;
                    break;
                }
            }

            // cerr << "desired_size " << desired_size << " " << small.size() << endl;

            // サイズdesired_sizeになるまで追加
            while(true){
                if(small.size() >= desired_size){
                    break;
                }

                // largeからsmallに移す
                ll val_l;
                while(true){
                    ll tmp = large.top();
                    // cerr << "tmp = " << tmp << endl;

                    // 消す予定のものは消す
                    if(kesu_l.count(tmp) > 0){
                        // cerr << "pop l " << tmp << endl;
                        large.pop();
                        kesu_l[tmp]--;
                        if(kesu_l[tmp] == 0){
                            kesu_l.erase(tmp);
                        }
                    }else{
                        val_l = tmp;
                        break;
                    }
                }


                // cerr << "pop l " << val_l << endl;
                large.pop();
                small.push(val_l);
                // cerr << "push s " << val_l << endl;
                ans += val_l;
            }

            val = small.top();
            // cerr << "val = " << val << " " << a[i + m - 1]<< endl;
            // cerr << a[i + m - 1] << endl;

            if(a[i + m - 1] < val){
                small.pop();
                ans -= val;
                small.push(a[i + m - 1]);
                ans += a[i + m - 1];

                large.push(val);
            }else{
                large.push(a[i + m - 1]);
            }
            // cerr << "ans = " << ans << endl;
            res[i] = ans;
            bef_desired = desired_size;
        }
        
        // cerr << "-----" << endl;
    }
    // cerr << n - m + 1 << endl;


    rep(i, n - m + 1){
        if(i == n - m){
            cout << res[i] << '\n';
        }else{
            cout << res[i] << " ";
        }
        
    }
    // n - m + 1
    


}