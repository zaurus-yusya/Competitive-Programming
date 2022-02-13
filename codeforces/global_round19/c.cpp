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
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<long long> a(n);
        vector<ll> kisuka(n);
        vector<ll> kaisu(n);

        map<ll, ll> mp;
        vector<ll> kisu;
        set<ll> st;
        
        ll sum = 0;
        for(long long i = 0; i < n; i ++){
            cin >> a[i];
            if(i == 0 || i == n-1) continue;
            if(a[i] % 2 == 1){
                kisuka[i] = 1;
                mp[i]++;
                kisu.push_back(i);
                st.insert(i);
            }
            kaisu[i] = a[i] / 2;
            sum += a[i];
        }

        ll ans = 0;

        //vecdbg(kisu);
        for(ll x = 0; x < 2; x++){
        for(ll i = 1; i < n-1; i++){
            if(!st.count(i)){
            //if(a[i] % 2 == 0){
                //一番左と右の一番近いところにあげる
                //ll dis = lower_bound(kisu.begin(), kisu.end(), i) - kisu.begin();

                while(kaisu[i] > 0){
                    if(st.size() == 0){
                        break;
                    }
                    auto it = st.lower_bound(-1);
                    auto it2 = st.lower_bound(i);

                    if(*it == *it2){
                        //cout << i << " " << *it << endl;
                        kaisu[i]--;
                        ans++;
                        kaisu[*it]++;
                        st.erase(*it);
                    }else{
                        //cout << i << " " << *it << " "  << *it2<< endl;
                        kaisu[i]--;
                        ans++;
                        kaisu[*it]++;
                        st.erase(*it);

                        if(it2 == st.end()) continue;
                        kaisu[*it2]++;
                        st.erase(*it2);
                    }
                }
            }else{
                
                //自分の左の1と右の奇数にあげる
                while(kaisu[i] > 0){
                    //cout << "in" << endl;
                    auto it = st.lower_bound(-1);
                    auto it2 = st.upper_bound(i);
                    

                    if((*it == i) && (it2 == st.end())){
                        break;
                    }

                    kaisu[i]--;
                    ans++;

                    if(*it != i){
                        //cout << i << " " << *it << endl;
                        kaisu[*it]++;
                        st.erase(*it);
                    }

                    if(it2 == st.end()) continue;
                    //cout << i << " " << *it2 << endl;
                    kaisu[*it2]++;
                    st.erase(*it2);
                    
                }

            }

        }
        }

        //vecdbg(kaisu);
        rep(i, n){
            if(i == 0 || i == n-1) continue;
            ans += kaisu[i];
        }

        if(st.size() == 0){
            cout << ans << endl;
        }else{
            cout << -1 << endl;
        }


    }

}