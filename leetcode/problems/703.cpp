class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> que;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0; (i < nums.size() && i < k); i++){
            que.push(nums[i]);
        }
        
    }
    
    int add(int val) {
        if(que.size() < K){
            que.push(val);
            return que.top();
        }
        
        int num = que.top();
        if(num < val){
            que.pop();
            que.push(val);
        }
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */