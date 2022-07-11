class Solution 
{
    public:
	int longestCommonSubsequence(string a, string b) 
    {
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
		for(int i = 0; i < n+1; i++) dp[i][0] = 0;
		for(int i = 0; i < m+1; i++) dp[0][i] = 0;
        
		for(int i = 1; i < n+1; i++)
        {
			for(int j = 1; j < m+1; j++)
            {
				if(a[i-1] == b[j-1])
                {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else
                {
					dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
				}
			}
		}

		return dp[n][m];
	}
};