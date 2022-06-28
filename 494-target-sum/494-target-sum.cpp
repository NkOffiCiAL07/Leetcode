class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        target = abs(target);
        if (target > sum || ((target + sum)&1))
            return 0;
        int n = (target + sum) / 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int& i:nums)
        {
            for (int j = n; j >= i; j--)
                dp[j] += dp[j-i];
        }
        return dp[n]; 
    }
};