#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    vector<int> dice(6);
    for(int i = 0; i < 6; i++){
        cin >> dice.at(i);
        dice.at(i)--;
    }
    vector<int> reverse(6);
    for(int i = 0; i < 6; i++){
        if(i % 2 == 0){
            reverse.at(dice.at(i)) = dice.at(i+1);
        }else{
            reverse.at(dice.at(i)) = dice.at(i-1);
        }
        
    }

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec.at(i);
        vec.at(i)--;
    }

    int ans = 0;
    int now = dice.at(0);
    for(int i = 0; i < n; i++){
        if(i == 0){
            continue;
        }
        if(now == vec.at(i)){
            ans += 0;
        }else if(reverse.at(now) == vec.at(i)){
            ans += 2;
            now = vec.at(i);
        }else{
            ans += 1;
            now = vec.at(i);
        }
    }

    cout << ans << endl;

}
