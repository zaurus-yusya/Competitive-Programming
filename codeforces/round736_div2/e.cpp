#include <bits/stdc++.h>
using namespace std;

//自分自身の記載(-1)が配列にあった場合それを検知する
bool validation_check(vector<vector<int>> male, vector<vector<int>> female){

    bool is_valid = true;
    
    for(int i = 0; i < male.size(); i++){
        auto index = find(male[i].begin(), male[i].end(), -1);
        if(index != male[i].end()) is_valid = false;
    }

    for(int i = 0; i < female.size(); i++){
        auto index = find(female[i].begin(), female[i].end(), -1);
        if(index != female[i].end()){
            is_valid = false;
        }
    }

    return is_valid;
}

//計算量評価
/* 女性のペアは一度組まれたら、そこから誰ともペアが組まれていない状態に変化することはない 
よって全ての男性に対して希望順位の女性を1人1人見ていった場合、全員分見た状態でペアが男性の人数分できている*/
//時間計算量 O(nk logn)  ※mapやsetの操作がボトルネックでlogn
//空間計算量 O(nk)
vector<int> matching(vector<vector<int>> male, vector<vector<int>> female){
    if(!validation_check(male, female)){
        cout << "Validation Error." << endl; //自分自身(-1)が配列に含まれていた場合終了する
        exit(0);
    }

    //男性n人、女性k人とする
    int n = male.size();
    int k = female.size();

    //maleのindexに対してペアとなるfemaleのindexを格納する配列(returnする配列)
    vector<int> male_match(n, -1);
    //femaleのindexに対してペアとなるmaleのindexを格納する配列
    vector<int> female_match(k, -1);

    //男性それぞれに対して次にアプローチをかける女性のindexを持っておく（初期値は第一希望: 配列0番目）
    vector<int> male_approach_index(n, 0);

    //ペアが決まった男性は下記のsetで管理
    set<int> male_decided;

    vector<map<int, int>> female_desired(k); //女性の希望順位をmapで管理 ある男性の希望順位をO(logn)で取得可能にするため
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            female_desired[i][female[i][j]] = j;
        }
    }

    while(male_decided.size() < n){

        for(int i = 0; i < n; i++){ //男性を順番に見ていく
            if(male_decided.count(i)) continue;

            //ペアが決まっていない男性は現時点で最も希望順位の高い女性にアプローチする
            int approach_female = male[i][male_approach_index[i]];

            //その女性がペアを組んでいなかったらペアを組む
            if(female_match[approach_female] == -1){
                male_match[i] = approach_female;
                female_match[approach_female] = i;
                male_decided.insert(i);
            }else{
            //ペアを組んでいた場合、女性目線で、アプローチをかけられた男性の方が条件が良かったらペアを付け替える
                int paired_male = female_match[approach_female];
                if(female_desired[approach_female][i] < female_desired[approach_female][paired_male]){
                    male_match[i] = approach_female;
                    female_match[approach_female] = i;
                    male_match[paired_male] = -1;

                    male_decided.insert(i);
                    male_decided.erase(paired_male);
                }
            }

            //次回は現在の希望順位の次の女性を見る
            male_approach_index[i] += 1;
        }
    }

    return male_match;

}

int main(){

    //使用例

    vector<vector<int>> male = {
        {1, 0, 2, 3},
        {1, 2, 0, 3},
        {3, 0, 1, 2}
    };
    vector<vector<int>> female = {
        {0, 1, 2},
        {1, 0, 2},
        {2, 0, 1},
        {2, 0, 1}
    };

    vector<int> result = matching(male, female);

    for(int i = 0; i < result.size(); i++){
        cout << "男性: " << i << " 女性: " << result[i] << endl; 
    }
    
}