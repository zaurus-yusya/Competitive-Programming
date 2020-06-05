#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, K; cin >> n >> K;
    deque<ll> deq;
    rep(i, n){
        ll v; cin >> v;
        deq.push_back(v);
    }

    ll ans = 0;

    for(ll i = 0; i <= K; i++){
        for(ll j = 0; j <= K - i; j++){
            deque<ll> que = deq;
            priority_queue<int, vector<int>, greater<int>> pq;

            for(ll k = 0; k < i; k++){
                if(!que.empty()){
                    pq.push(que.front());
                    que.pop_front();
                }else{
                    break;
                }
            }
            for(ll k = 0; k < j; k++){
                if(!que.empty()){
                    pq.push(que.back());
                    que.pop_back();
                }else{
                    break;
                }
            }

            //discard
            for(ll k = 0; k < K - i - j; k++){
                if(!pq.empty()){
                    ll now = pq.top();
                    if(now < 0){
                        pq.pop();
                    }else{
                        break;
                    }
                }
            }

            //calc
            ll tmp = 0;
            while(!pq.empty()){
                tmp += pq.top();
                pq.pop();
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;

}