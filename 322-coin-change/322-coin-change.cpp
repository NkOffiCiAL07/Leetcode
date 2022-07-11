class Solution 
{
    public:    
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        
        dp[0] = 0;
        for(int am=0; am<=amount; am++)
        {
            for(int j=0; j<n; j++)
            {
                if(coins[j] <= am)
                {
                    dp[am] = min(dp[am], dp[am - coins[j]] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};