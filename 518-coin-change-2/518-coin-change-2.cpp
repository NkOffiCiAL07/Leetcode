class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<int> dp(amount+1);
        dp[0] = 1;
        
        for(int i=0; i<n; i++)
        {
            for(int am = 0; am <= amount; am++)
            {
                if(coins[i] <= am)
                {
                    dp[am] += dp[am - coins[i]];
                }
            }
        }
        
        return dp[amount];
    }
};