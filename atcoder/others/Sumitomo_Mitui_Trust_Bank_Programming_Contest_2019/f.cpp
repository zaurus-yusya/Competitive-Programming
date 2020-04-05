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


int main() {
    ll t1, t2;
    ll a1, a2;
    ll b1, b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    ll first_div = (a1-b1) * t1;
    ll second_div = (a2-b2) * t2;

    if(first_div == -1 * second_div){
        cout << "infinity" << endl;
        return 0;
    }

    ll count = 0;
    string flag = "t1";
    ll before = 0;
    ll after = 0;
    ll first_flag = 0;
    while(true){
        if(first_flag == 0){
            first_flag = 1;
            flag = "t2";
            after += first_div;
        }else{
            if(flag == "t1"){
                flag == "t2";
                before = after;
                after += first_div;
                if( (before > 0 && after < 0) || (before < 0 && after > 0)){
                    count++;
                }else if(after == 0){
                    count++;
                    break;
                }else{
                    break;
                }    

            }else{
                flag == "t1";
                before = after;
                after += second_div;
                if( (before > 0 && after < 0) || (before < 0 && after > 0)){
                    count++;
                }else if(after == 0){
                    count++;
                    cout << "oo" << endl;
                    break;
                }else{
                    break;
                }

            }
        }
    }


    cout << "first_div = " << first_div << endl;
    cout << "second_div = " << second_div << endl;

    cout << count << endl;



}
