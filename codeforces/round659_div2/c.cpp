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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll X; cin >> X;
    rep(x, X){
        ll n; cin >> n;
        string s, t; cin >> s >> t;
        /*
        vector<vector<ll>> g(20);
        rep(i, n){
            ll sl = (ll)s[i] - 97, tl = (ll)t[i] - 97;
            cout << sl << " " << tl << endl;
            g[sl].push_back((-1) * tl);
        }
        cout << "---" << endl;
        rep(i, 20){
            rep(j, g[i].size()){
                cout << g[i][j] << " ";
            }
            br;
        }
        */

        vector<priority_queue<ll>> pq(20);
        bool flag = false;
        rep(i, n){
            ll sl = (ll)s[i] - 97, tl = (ll)t[i] - 97;
            if(tl - sl != 0){
                pq[sl].push((-1) * (tl - sl));
            }
            if(tl - sl < 0){
                flag = true;
            }
        }

        if(flag){
            cout << -1 << endl;
            continue;
        }

        /*
        cout << "---" << endl;
        rep(i, 20){
            while(!pq[i].empty()){
                cout << pq[i].top() << " ";
                pq[i].pop();
            }
            br;
        }
        cout << "---" << endl;
        */

        ll ans = 0;
        rep(i, 20){
            if(pq[i].empty()){
                continue;
            }

            ll num = pq[i].top() * (-1);
            pq[i].pop();
            //cout << "num = " << num << endl;
            //cout << "i = " << i << endl;
            while(!pq[i].empty()){
                //cout << "top = " << pq[i].top() << endl;
                ll tmp = pq[i].top() + num;
                if(tmp != 0){
                    pq[i + num].push(tmp);
                    //cout << "pushed " << tmp << endl;
                }
                pq[i].pop();
            }
            
            ans++;
        }
        cout << ans << endl;

        /*
        vector<ll> a(n);
        rep(i, n){
            ll tmp = (ll)t[i] - (ll)s[i];
            a[i] = tmp;
        }
        rep(i, n){
            cout << a[i] << endl;
        }
        */

    }

}