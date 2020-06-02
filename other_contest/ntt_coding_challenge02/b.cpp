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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
ll x = 0, y = 0;
vector<pair<ll,ll>> vec = {make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0)};
ll countp = 1;
ll countr = 1;
ll stop_flag = 0;
ll now = 0;
ll flag = 0;


void move(char c, char c2){
    if(c == 'F'){
        ll tmp_x = vec[now].first;
        ll tmp_y = vec[now].second;

        x += tmp_x * countp;
        y += tmp_y * countp;
        stop_flag += countp;
        countp = 1;
        
    }
    if(c == 'B'){
        ll tmp_now = (now + 2) % 4;

        ll tmp_x = vec[tmp_now].first;
        ll tmp_y = vec[tmp_now].second;

        x += tmp_x * countp;
        y += tmp_y * countp;
        stop_flag += countp;
        countp = 1;
    }
    if(c == 'R'){
        ll tmp = countp % 4;
        now += tmp; 
        if(now >= 4){
            now = now % 4;
        }

        stop_flag += countp;
        countp = 1;
    }
    if(c == 'L'){
        ll tmp = countp % 4;
        now -= tmp;
        if(now <= -1){
            now += 4;
        }

        stop_flag += countp;
        countp = 1;
    }
    if(c >= '1' && c <= '9'){
        ll num = c - 48;
        if(c2 == '['){
            flag = 1;
            countr = num;
            
        }else{
            countp = num;
        }
        
        
    }
}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;
    
    vector<ll> roop;
    
    rep(i,s.size()){
        if(flag == 0){
            char c = s[i];
            move(c, s[i+1]);
        }
        if(flag == 1){
            //cout << " ok" << endl;
            if(s[i] == '['){
                continue;
            }else if(s[i] == ']'){
                for(ll j = 0; j < countr; j++){
                    for(ll k = 0; k < roop.size(); k++){
                        move(roop[i]);
                    }
                    //cout << x << " " << y << endl;
                }
                flag = 0;
                countr = 1;
            }else{
                roop.push_back(s[i]);
            }
        }
        
       
    }

    cout << x << " " << y << endl;
    

}