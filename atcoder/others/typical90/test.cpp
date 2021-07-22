#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    //ある英単語wの受け取り
    string w; cin >> w;

    //wに含まれる文字の種類をmapで管理
    map<char, int> mp_w;
    for(int i = 0; i < w.size(); i++){
        mp_w[w[i]]++;
    }

    //求める答えの個数を変数ansとする
    int ans = 0;

    //英単語のリストLの中に重複する単語があるかチェックするmapを設定
    map<string, int> dupulicate_check;

    //while文で英単語のリストLの単語を最後の単語まで入力を受け付ける
    string s;
    while(cin >> s) { 
        //このループの中で英単語Wと、英単語リストLの中の1つの単語に関して似ているか判定する
        

        //英単語リストLの中で同じ単語が出てきた場合、2回目以降は判定しないものとする。
        if(dupulicate_check.count(s) > 0) continue;
        dupulicate_check[s]++;

        //sに含まれる文字の種類をmapで管理 (s: 英単語リストLの中の1つの単語)
        map<char, int> mp_s;
        for(int i = 0; i < s.size(); i++){
            mp_s[s[i]]++;
        }


        //wとsが似ているか判定する。flagの値がtrueだったら似ているとする
        bool flag = true;

        //wに含まれる文字全てがsに含まれるか
        for(auto i : mp_w){
            if(mp_s.count(i.first) == 0){
                flag = false;
            }
        }

        //sに含まれる文字全てがwに含まれるか
        for(auto i : mp_s){
            if(mp_w.count(i.first) == 0){
                flag = false;
            }
        }

        //flagの値がtrueだったら答えをインクリメント
        if(flag) ans++;

    }

    cout << ans << endl;

    return 0;
}