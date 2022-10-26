class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 0;
        int runningSum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            runningSum += nums[i];
            if(!mp.count(runningSum % k)){
                mp[runningSum % k] = i + 1; 
            }
            else if(mp[runningSum % k] < i){
                return true;
            }
        }
        return false;
    }
};