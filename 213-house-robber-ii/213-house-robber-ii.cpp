class Solution 
{
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        if(n == 1)
            return dp[0];
        
        dp[1] = max(nums[1], nums[0]);
        if(n == 2)
            return dp[1];
        
        if(n == 3)
            return max({nums[1], nums[0], nums[2]});
        
        for(int i=2; i<n-1; i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        
        int ans = dp[n-2];
        
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }       
        
        return max(ans, dp[n-1]);
    }
};