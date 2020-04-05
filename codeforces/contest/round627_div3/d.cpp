#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
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

int main() {
    ll n;
    cin >> n;

    vector<ll> vec_positive;
    vector<ll> vec_negative;

    

    vector<long long> vec_a(n);
    rep(i, n){
        cin >> vec_a[i];
    } 
    vector<long long> vec_b(n);
    vector<long long> vec_c(n);
    rep(i, n){
        cin >> vec_b[i];
        ll tmp = vec_a[i] - vec_b[i];
        vec_c[i] = tmp;
        if(tmp > 0){
            vec_positive.push_back(tmp);
        }else{
            vec_negative.push_back(tmp);
        }
    }

    sort(all(vec_positive));
    sort(all(vec_negative));
    sort(all(vec_c));

    ll ans = 0;
    rep(i,n){
        cout << vec_c[i] << " ";
    }
    cout << endl;

    rep(i,n){
        auto itr = upper_bound(all(vec_c), -vec_c[i]);
        ll tmp = vec_c.end() - itr;
        ans += vec_c.end() - itr;
        cout << tmp << endl;
    }

    cout << ans << endl;
    /*

    if(n == 2){
        if(vec_a[0] + vec_a[1] > vec_b[0] + vec_b[1]){
            cout << 1 << endl;
            return 0;
        }else{
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 0;

    if(vec_positive.size() >= 2){
        ll bunbo = 2;
        ll bunshi = vec_positive.size() * (vec_positive.size() - 1);
        ans += bunshi / bunbo;
    }


    if(vec_negative.size() != 0){

       rep(i,vec_positive.size()){
            ll tmp = vec_positive[i] * (-1);
            auto up = upper_bound(all(vec_negative), tmp);
            ll tmp2 = up - vec_negative.begin();
            cout << tmp << " " << tmp2 << endl;
            ans += vec_negative.size() - tmp2;
       }

    }
    */
    
    cout << ans << endl;
    return 0;
}