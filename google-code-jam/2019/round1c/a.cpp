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

char lose_hand(char c){
    char res;
    if(c == 'R'){
        res = 'S';
    }
    if(c == 'S'){
        res = 'P';
    }
    if(c == 'P'){
        res = 'R';
    }
    return res;
}

char win_hand(map<char, ll> mp){
    char c;
    if(mp['R'] > 0 && mp['S'] > 0){
        c = 'R';
    }
    if(mp['S'] > 0 && mp['P'] > 0){
        c = 'S';
    }
    if(mp['P'] > 0 && mp['R'] > 0){
        c = 'P';
    }
    return c;
}

char win_hand2(map<char, ll> mp){
    char c;
    if(mp['R'] > 0){
        c = 'P';
    }
    if(mp['S'] > 0){
        c = 'R';
    }
    if(mp['P'] > 0){
        c = 'S';
    }
    return c;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll T;
    cin >> T;
    rep(t,T){
        ll A;
        cin >> A;
        vector<vector<char>> vec(A);
        ll max_size = 0;
        rep(i,A){
            string s;
            cin >> s;
            max_size = max(max_size, (ll)s.size());
            rep(j,s.size()){
                /*
                if(j > 9){
                    break;
                }
                */
                vec[i].push_back(s[j]);
            }
        }

        vector<ll> win(A);
        vector<char> ans;
        bool impflag = false;
        rep(i,500){
            map<char,ll> mp;
            rep(j,A){
                if(win[j] == 0){
                    mp[vec[j][i%vec[j].size()]]++;
                }
            }
            if(mp.size() == 3){
                impflag = true;
                break;
            }else if(mp.size() == 2){
                char c = win_hand(mp);
                char canwin = lose_hand(c);
                rep(j,A){
                    if(vec[j][i%vec[j].size()] == canwin){
                        win[j] = 1;
                    }
                }
                //cout << i << " " << c << endl;
                ans.push_back(c);
            }else{
                char c = win_hand2(mp);
                ans.push_back(c);
                break;
            }
        }

        cout << "Case #" << t+1 << ": ";

        if(impflag){
            cout << "IMPOSSIBLE" << endl;
        }else{
            rep(i,ans.size()){
                cout << ans[i];
            }
            cout << endl;
            /*
            rep(i,A){
                rep(j,8){
                    cout << vec[i][j%vec[i].size()];
                }
                cout << endl;
            }
            */
        }




    }

}