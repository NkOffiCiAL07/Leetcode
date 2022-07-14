class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1);
        for(int i=0; i<nums.size(); i++)
        {
            dp[nums[i]]++;
            if(dp[nums[i]] >= 2)
                return nums[i];
        }
          
        return 0;
    }
};