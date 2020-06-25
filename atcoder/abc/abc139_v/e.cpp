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
    ll n; cin >> n;

    vector<queue<ll>> vec(n);

    rep(i, n){
        rep(j, n-1){
            ll tmp; cin >> tmp; tmp--;
            vec[i].push(tmp);
        }
    }

    
    ll day = 0;
    for(ll x = 0; x < n*(n-1)/2; x++){
        bool flag = true;
        ll count = 0;
        vector<ll> tmp(n);
        rep(i, n){
            if(tmp[i] > 0){
                continue;
            }
            ll player1, player2;
            if(!vec[i].empty()){
                player1 = vec[i].front();
            }else{
                //cout << "empty" << endl;
                count++;
                continue;
            }
            if(tmp[player1] > 0){
                continue;
            }

            if(!vec[player1].empty()){
                player2 = vec[player1].front();
            }else{
                continue;
            }
            
            if(i == player2){
                //cout << day << " " << i << " " << player1 << endl;
                tmp[i]++;
                tmp[player1]++;
                vec[i].pop();
                vec[player1].pop();
                flag = false;
            }
        }

        if(count == n){
            break;
        }

        if(!flag){
            day++;
            /*
            rep(i, n){
                if(tmp[i] > 0){
                    vec[i].pop();
                }
            }
            */
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    cout << day << endl;

    /*
    while(!vec[0].empty()){
        cout << vec[0].front() << endl;
        vec[0].pop();
    }
    */





}