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
    ll T;
    cin >> T;
    rep(t,T){
        ll n;
        cin >> n;
        vector<string> vec(n);
        vector<string> vec2(n);
        vector<ll> vec_size(n);
        vector<ll> vec_ast(n);
        //test1
        ll size = 0;
        rep(i, n){
            cin >> vec[i];
            vec2[i] = vec[i];
            vec_size[i] = (ll)vec[i].size();
            reverse(all(vec[i]));
            size = max(size, (ll)vec[i].size());
        }


        rep(i,n){
            rep(j,vec_size[i]){
                if(vec[i][j] == '*'){
                    vec_ast[i] = j;
                }
            }
        }
        /*
        rep(i,n){
            cout << vec_ast[i] << endl;
        }
        */
        
        //back
        vector<ll> ast_flag(n);
        vector<char> ans;
        bool flag = true;
        rep(i,size){
            char tmp = '-';
            rep(j,n){
                if(i >= vec_size[j]){
                    continue;
                }
                if(ast_flag[j] == 1){
                    continue;
                }
                if(vec[j][i] == '*'){
                    ast_flag[j] = 1;
                    continue;
                }

                if(tmp == '-'){
                    //cout << vec[j][i] << endl;
                    tmp = vec[j][i];
                }else{
                    if(vec[j][i] != tmp){
                        //cout << vec[j][i] << endl;
                        flag = false;
                    }
                }
            }
            if(flag && tmp != '-'){
                ans.push_back(tmp);
            }else{
                break;
            }
            
        }
        ///back

        
        //front
        vector<ll> ast_flag2(n);
        vector<char> ans2;
        bool flag2 = true;
        rep(i,size){
            char tmp = '-';
            rep(j,n){
                if(i >= vec_size[j]){
                    continue;
                }
                if(ast_flag2[j] == 1){
                    continue;
                }
                if(vec2[j][i] == '*'){
                    ast_flag2[j] = 1;
                    continue;
                }
                if(tmp == '-'){
                    //cout << vec[j][i] << endl;
                    tmp = vec2[j][i];
                }else{
                    if(vec2[j][i] != tmp){
                        //cout << "ok" << endl;
                        flag2 = false;
                    }
                }
            }
            if(flag2 && tmp != '-'){
                ans2.push_back(tmp);
            }else{
                break;
            }
            
        }
        ///front
        

        
        cout << "Case #" << t+1 <<": ";
        if(flag == false || flag2 == false){
            cout << "*" << endl;
        }else{
            if(ans2.size() != 0){
                rep(i,ans2.size()){
                    cout << ans2[i];
                }
            }

            rep(i,n){
                rep(j,vec2[i].size()){
                    if(vec2[i][j] != '*'){
                        cout << vec2[i][j];
                    }
                }
            }

            if(ans.size() != 0){
                reverse(all(ans));
                rep(i,ans.size()){
                    cout << ans[i];
                }
                cout << endl;
            }

        }

        /*
        if(flag == false){
            cout << "*" << endl;
        }else{
            reverse(all(ans));
            rep(i,ans.size()){
                cout << ans[i];
            }
            cout << endl;
        }
        
        cout << "Case #" << t+1 <<": ";
        if(flag2 == false){
            cout << "*" << endl;
        }else{
            //reverse(all(ans2));
            rep(i,ans2.size()){
                cout << ans2[i];
            }
            cout << endl;
        }
        */
        
        

        
        


    }

}