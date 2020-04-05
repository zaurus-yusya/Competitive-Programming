#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> q(n);

    rep(i,n){
        cin >> p[i];
    }
    rep(i,n){
        cin >> q[i];
    }

    vector<ll> tmp(n);
    rep(i,n){
        tmp[i] = i+1;
    }

    ll count = 0;
    ll p_ans = 0;
    ll q_ans = 0;
    
    do{
        count++;
        ll p_flag = 0;
        ll q_flag = 0;
        for(ll i = 0; i < n; i++){
            //cout << tmp[i] << " ";
            if(tmp[i] == p[p_flag]){
                p_flag ++;
            }
            if(tmp[i] == q[q_flag]){
                q_flag ++;
            }
        }

        if(p_flag == n){
            p_ans = count;
        }
        if(q_flag == n){
            q_ans = count;
        }
        //cout << endl;
    }while(next_permutation(tmp.begin(), tmp.end()));

    cout << abs(p_ans - q_ans) << endl;
}