#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    string s;

    for(int i = 0; i < t; i++){
        cin >> s;
        int ans = 0;

        for(int j = 0; j < s.size(); j++){

            if(s.substr(j,5) == "tokyo" || s.substr(j,5) == "kyoto"){
                j += 4;
                ans++;
            }

        }
        
        cout << ans << endl;

    }

    return 0;

}
