class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec(2);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int tmp = target - nums.at(i);
            if(mp.find(tmp) != mp.end()){
                vec = {mp[tmp], i};
                break;
            }else{
                mp[nums.at(i)] = i;
            }
        }
        return vec;
    }
};