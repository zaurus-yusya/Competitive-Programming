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
    ll n;
    string s;

    cin >> n;
    cin >> s;

    //最高1000
    vector<int> vec_1(10);
    vector<int> vec_2(100);
    vector<int> vec_3(1000);


    
    for(ll i = 0; i < s.size(); i++){

        
        for(ll j = 0; j < 100; j++){
            if(vec_2.at(j) > 0){
                vec_3.at( (j*10) + int(s.at(i)) -48) ++;
            }
        }

        for(ll j = 0; j < 10; j++){
            if(vec_1.at(j) > 0){
                vec_2.at( (j*10) + int(s.at(i)) -48) ++;
            }
        }
        
        vec_1.at(int(s.at(i))-48)++;

        
    }
    
    int count = 0;
    for(ll i = 0; i < vec_3.size(); i++){
        if(vec_3.at(i) > 0){
            count ++;
        }
    }

    cout << count << endl;


}
