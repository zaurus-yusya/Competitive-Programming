#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

vector<ll> vec;
vector<ll> a;
vector<ll> b;
vector<ll> c;
vector<ll> d;
ll ans = 0;

void saiki(ll n, ll m, ll index, ll num, ll q){
    if(index == n){
        ll tmp = 0;
        rep(i,q){
            if(vec[b[i]] - vec[a[i]] == c[i]){
                tmp += d[i];
            }
        }
        ans = max(ans, tmp);
        /*
        rep(i,n){
            cout << vec[i] << " ";
        }
        cout << endl;
        */
        return;
    }
    for(ll i = num; i < m; i++){
        vec[index] = i;
        saiki(n, m, index+1, i, q);
    }
}



int main() {
    std::cout << std::fixed << std::setprecision(15);

    ll n, m, q;
    cin >> n >> m >> q;

    
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);

    rep(i,q){
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        A--; B--;
        a[i] = A; b[i] = B; c[i] = C; d[i] = D;

    }

    vec.resize(n,0);
    saiki(n, m, 0, 0, q);

    cout << ans << endl;

    



}