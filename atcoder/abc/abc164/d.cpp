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
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

vector<bool> seen;

ll dfs(const Graph &G, ll v, ll size)
{
    size++;
    seen[v] = true;

    for(ll next_node : G[v]){
        if(seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            size += dfs(G, next_node);
        }
    }

    return size;

}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s;
    cin >> s;

    if(s.size() < 4){
        cout << 0 << endl;
        return 0;
    }

    /*
    rep(i,50){
        cout << 2019 * i << endl;
    }
    */

    vector<pair<ll,ll>> vec;
    map<ll,ll> beg;
    map<ll,ll> end;

    ll ans = 0;

    vector<vector<ll>> g(s.size()); 

    if(s.size() >= 5){
        for(ll i = 0; i <= s.size() - 5; i++){
            if(stoi(s.substr(i,5)) % 673 == 0 && stoi(s.substr(i,5)) % 3 == 0){
                cout << "ok5" << endl;
                beg[i-1]++;
                end[i+4]++;
                ans++;
                vec.push_back(make_pair(i,i+4));
                g[i-1].push_back(i+4);
            }
        }
    }
    
    if(s.size() >= 6){
        for(ll i = 0; i <= s.size() - 6; i++){
            if(stoi(s.substr(i,6)) % 673 == 0 && stoi(s.substr(i,6)) % 3 == 0){
                cout << "ok6" << endl;
                beg[i-1]++;
                end[i+5]++;
                ans++;
                vec.push_back(make_pair(i,i+5));
                g[i-1].push_back(i+5);
            }
        }
    }

    
    ll ans2 = 0;
    /*
    cout << "------------" << endl;
    for(auto i: beg){
        cout << i.first << " " << i.second << endl;  //key
    }
    cout << "------------" << endl;
    for(auto i: end){
        if(beg.count(i.first) >= 1){
            ans2++;
        }
        cout << i.first << " " << i.second << endl;  //key
    }
    cout << "------------" << endl;
    */
    

    /*
    rep(i,vec.size()){
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    */
   
    rep(i,g.size()){
        if(g[i].size() > 0){
            cout << i << " [ ";
            rep(j,g[i].size()){
                cout << g[i][j] << " ";
            }
            cout << " ]"<< endl;
        }
    }

    seen.assign(s.size(),false);
    rep(i,s.size()){
        ll tmp;
        tmp = dfs(g, i, 0);
        if(tmp > 1){
            ans += (1 + tmp-1) * (tmp-1) / 2;
        }
        
    }
    

    cout << ans << endl;
    cout << ans2 << endl;

    

    /*
    cout << s.size() << endl;
    ll ans = 0;
    for(ll i = 0; i <= s.size() - 4; i++){
        for(ll j = 3; i + j < s.size(); j++){
            if(stoi(s.substr(i,j+1)) % 2019 == 0){
                cout << i << " " << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    */

}