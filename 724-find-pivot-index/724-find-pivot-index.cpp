class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            dp[i] = nums[i] + dp[i-1];
        
        int sum = 0;
        int p = INT_MAX;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(i == 0)
            {
                if(sum == 0)
                    p = i;
            }
            else if(i == nums.size()-1)
            {
                if(dp[i-1] == 0)
                    p = i;
            }
            else
            {
                if(sum == dp[i-1])
                    p = i;
            }
            
            sum += nums[i];
        }
        
        if(p == INT_MAX) 
            return -1;
        
        return p;
    }
};