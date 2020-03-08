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
    string s;
    cin >> s;
    ll q;
    cin >> q;

    deque<char> deq;
    
    rep(i,s.size()){
        deq.push_front(s.at(i));
    }
    

    ll flag = 1;
    rep(i,q){
        ll tmp;
        cin >> tmp;
        if(tmp == 1){
            flag++;
        }else if(tmp == 2){
            ll f;
            char c;
            cin >> f >> c;
            if((flag + f) % 2 == 1){
                deq.push_front(c);
            }else{
                deq.push_back(c);
            }
        }
    }

    if(flag % 2 == 0){
        while(!deq.empty()){
            cout << deq.front();
            deq.pop_front();
        }
    }else{
        while(!deq.empty()){
            cout << deq.back();
            deq.pop_back();
        }
    }
    cout << endl;

}