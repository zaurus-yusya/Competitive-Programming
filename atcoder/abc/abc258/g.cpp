#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
    std::cout << std::fixed << std::setprecision(15);
    int n; cin >> n;

    bool vec[n][n];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            vec[i][j] = s[j] == '1';
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(vec[i][j] && vec[i][k] && vec[j][k]){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

}