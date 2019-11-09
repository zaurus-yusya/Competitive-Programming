#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
//二次元配列
//vector<vector<int>> vec(h, vector<int>(w));

int main() {

    string s;

    cin >> s;

    vector<ll> vec_num;
    vector<string> vec_str;

    int first_dainari = -1;

    int dainari_count = 0;
    int shonari_count = 0;

    for(int i = 0; i < s.size(); i++){
        if(s.at(i) == '<'){
            shonari_count++;
            if(dainari_count != 0){
                vec_num.pb(dainari_count);
                vec_str.pb(">");
                dainari_count = 0;
            }
        }
        if(s.at(i) == '>'){
            dainari_count++;
            if(shonari_count != 0){
                vec_num.pb(shonari_count);
                vec_str.pb("<");
                shonari_count = 0;
            }
        }
    }
    if(shonari_count != 0){
        vec_num.pb(shonari_count);
        vec_str.pb("<");
    }else{
        vec_num.pb(dainari_count);
        vec_str.pb(">");
    }


    ll ans = 0;
    ll tmp = 0;

    if(vec_num.size() == 1){
        ans = (0 + vec_num.at(0)) * (vec_num.at(0)+1) / 2;
        cout << ans << endl;
        return 0;
    }

    
    for(int i = 0; i < vec_num.size(); i++){
        tmp = (0 + vec_num.at(i)) * (vec_num.at(i)+1) / 2;

        if(i == 0){
            if(vec_str.at(i) == "<"){
                if(vec_num.at(i) <= vec_num.at(i+1)){
                    ans += (tmp - vec_num.at(i));
                }else{
                    ans += tmp;
                }
            }else{
                ans += tmp;
            }
        }

        if(i == vec_num.size()-1){
            if(vec_str.at(i) == ">"){
                if(vec_num.at(i) < vec_num.at(i-1)){
                    ans += (tmp - vec_num.at(i));
                }else{
                    ans += tmp;
                }
            }else{
                ans += tmp;
            }
        }

        if(i != 0 && i != vec_num.size()-1){
            if(vec_str.at(i) == ">"){
                if(vec_num.at(i) < vec_num.at(i-1)){
                    ans += (tmp - vec_num.at(i));
                }else{
                    ans += tmp;
                }
            }
            if(vec_str.at(i) == "<"){
                if(vec_num.at(i) <= vec_num.at(i+1)){
                    ans += (tmp - vec_num.at(i));
                }else{
                    ans += tmp;
                }
            }
        }

    }
    

    cout << ans << endl;
    return 0;


}

