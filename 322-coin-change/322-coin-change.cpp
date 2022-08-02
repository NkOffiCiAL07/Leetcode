class Solution {
public:
    int coinChange(vector<int>& coins, int am) {
        int n = coins.size();
        vector<int> dp(am+1, am+1);
        
        dp[0] = 0;
        for(int a=0; a<=am; a++)
        {
            for(int j=0; j<n; j++)
            {
                if(coins[j] <= a)
                {
                    dp[a] = min(dp[a], dp[a - coins[j]] + 1);
                }
            }
        }
        
        return dp[am] > am ? -1 : dp[am];
    }
};