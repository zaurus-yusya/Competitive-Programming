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
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)



int main() {
    ll n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    rep(i,n){
        cin >> p.at(i);
    }
    rep(i,n){
        cin >> q.at(i);
    }

    ll tmp = 1;

    vector<ll> kaijo(9);

    rep(i,n){
        tmp *= (i+1);
        kaijo.at(i+1) = tmp;
    }

    ll p_num = 0;
    ll q_num = 0;
    vector<ll> p_tmp(8);
    vector<ll> q_tmp(8);
    ll count = 0;

    rep(i,n){
        ll p_count = 0;
        ll q_count = 0;
        rep(j,p.at(i)){
            if(p_tmp.at(j) == 1){
                p_count++;
            }
        }
        rep(j,q.at(i)){
            if(q_tmp.at(j) == 1){
                q_count++;
            }
        }

        //cout << p.at(i) - p_count << endl;
        //cout << q.at(i) - q_count << endl;

        p_tmp.at(p.at(i)-1) = 1;
        q_tmp.at(q.at(i)-1) = 1;

        //cout << "----" << endl;

        p_num += (p.at(i) - p_count - 1) * kaijo.at(n-i-1);
        q_num += (q.at(i) - q_count - 1) * kaijo.at(n-i-1);

        //cout << p_num << endl;
        //cout << q_num << endl;
        //cout << "--------" << endl;

    }


    if(p_num - q_num < 0){
        cout << q_num - p_num << endl;
    }else{
        cout << p_num - q_num << endl;
    }
    

}
