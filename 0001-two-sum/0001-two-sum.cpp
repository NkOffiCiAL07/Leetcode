class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int tar = target - nums[i];
            if(m.find(tar) != m.end()){
                return {i, m[tar]};
            }
            m[nums[i]] = i;
        }
        
        return {0, 0};
    }
};