#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する

vector<vector<pair<int,int>>> vec;
int ans = 0;



void bit_full_search(int n)
{
    //2^n回ループ
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> vec_ans(n);
        int count = 0;
        //cout << "{";
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                //cout << " " << i << " ";
                vec_ans[i] = 1;
                count++;
            }
        }
        //cout << "}" << endl;

        ll flag = 0;

        rep(i,vec_ans.size()){
            if(vec_ans.at(i) == 1){
                rep(j, vec[i].size()){
                    ll man = vec[i].at(j).first;
                    ll say = vec[i].at(j).second;
                    if(vec_ans[man] != say){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1){
                break;
            }
        }

        if(flag == 0){
            ans = max(count, ans);
        }
    }


    
}

int main() {
    int n;
    cin >> n;
    
    vec.resize(n);
    
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            int x, y;
            cin >> x >> y;
            x--;
            vec[i].pb(make_pair(x,y));
        }
        
    }    

    bit_full_search(n);

    cout << ans << endl;

}
