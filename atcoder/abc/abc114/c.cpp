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

string s;
ll ans = 0;
vector<char> dic = {'3', '5', '7'};

void dfs(ll keta, ll now, bool flag, string res){
    if(now == keta){
        //判定     
        bool flag3 = false, flag5 = false, flag7 = false;   
        rep(i, res.size()){
            if(res[i] == '5'){
                flag3 = true;
            }
            if(res[i] == '3'){
                flag5 = true;
            }
            if(res[i] == '7'){
                flag7 = true;
            }
        }
        if(flag3 == true && flag5 == true && flag7 == true){
            ans++;
        }
    }else{
        if(flag){
            ll tmp = s[now] - 48;
            
            for(ll j = 0; j < 3; j++){
                ll tmp_dic = dic[j] - 48;
                //cout << "tmp " << tmp << " " << tmp_dic << endl; 
                if(tmp == tmp_dic){
                    dfs(keta, now+1, true, res+dic[j]);
                }else if(tmp > tmp_dic){
                    dfs(keta, now+1, false, res+dic[j]);
                }
            }
        }else{
            for(ll j = 0; j < 3; j++){
                dfs(keta, now+1, false, res+dic[j]);
            }
        }
    }
}

int main() {
    cin >> s;
    ll n = stoll(s);

    ll keta = 0;
    ll tmp = n;
    while(tmp != 0){
        keta++;
        tmp /= 10;
    }

    if(keta < 3){
        cout << 0 << endl;
        return 0;
    }

    string res = "";
    for(ll i = 3; i <= keta; i++){
        if(i == keta){
            dfs(i, 0, true, res);
        }else{
            dfs(i, 0, false, res);
        }
        
    }
    

    cout << ans << endl;
}