class Solution 
{
    public:
    
    int coinChange(vector<int>& coins, int n) 
    {
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        
        for(int i=0; i<=n; i++)
        {
            for(auto val : coins)
            {
                if(i >= val)
                {
                     dp[i] = min(dp[i], dp[i - val] + 1);
                }
            }
        }
        
        if(dp[n] > n)
            return -1;
        
        return dp[n];
    }
};