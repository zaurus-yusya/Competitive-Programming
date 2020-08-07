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
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<long long> vec(n);
        map<ll, ll> mp;
        priority_queue<ll> pq;
        for(long long i = 0; i < n; i ++){
            cin >> vec[i];
            mp[vec[i]]++;
        }
        for(auto i: mp){
            if(i.second >= 2){
                pq.push(i.second);
            }
            
            //cout << i.first << " " << i.second << endl;  //key, value
        }
        
        ll left = -1, right = 1000000;
        
        while(right - left > 1){
            ll mid = (left + right) / 2;
            bool flag = true;
            vector<ll> res(n, 0);
            priority_queue<ll> pq2 = pq;
            //cout << "mid = " << mid << endl;
            ll start = 0;

            while(!pq2.empty()){
                ll val = pq2.top();
                //cout << "val = " << val << endl;
                pq2.pop();
                if(val == 1){
                    break;
                }
                ll j = start;
                for(ll i = 0; i < val; i++) {
                    if(j >= n){
                        flag = false; break;
                    }
                    if(res[j] == 1){
                        flag = false; break;
                    }
                    //cout << "j = " << j << endl;
                    res[j] = 1;
                    j += (mid + 1);
                }

                while(res[start] == 1){
                    start++;
                    if(start >= n){
                        break;
                    }
                }

                if(flag == false){
                    break;
                }
            }

            /*
            rep(i, n){
                cout << res[i] << " ";
            }
            br;
            */

            //true or false
            if(flag){
                //ok
                left = mid;
            }else{
                //ng
                right = mid;
            }
            //cout << "left= " << left << " right= " << right << endl; 
        }

        //
        ll mid = right;
            bool flag = true;
            vector<ll> res(n, 0);
            priority_queue<ll> pq2 = pq;
            //cout << "mid = " << mid << endl;
            ll start = 0;

            while(!pq2.empty()){
                ll val = pq2.top();
                //cout << "val = " << val << endl;
                pq2.pop();
                if(val == 1){
                    break;
                }
                ll j = start;
                for(ll i = 0; i < val; i++) {
                    if(j >= n){
                        flag = false; break;
                    }
                    if(res[j] == 1){
                        flag = false; break;
                    }
                    //cout << "j = " << j << endl;
                    res[j] = 1;
                    j += (mid + 1);
                }

                while(res[start] == 1){
                    start++;
                    if(start >= n){
                        break;
                    }
                }

                if(flag == false){
                    break;
                }
            }
        //

        if(flag){
            cout << right << endl;
        }else if(left == -1){
            cout << 0 << endl;
        }else{
            cout << left << endl;
        }
        
    }

}