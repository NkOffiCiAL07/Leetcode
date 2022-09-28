class Solution 
{
    public:
    int helper(string word1, string word2,int dp[501][501])
    {
        int m = word1.size() ,n = word2.size();

        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        if(m==0 || n==0){
            return n==0 ? m : n;
        }

        if(word1[0] == word2[0])
        {
            return helper(word1.substr(1),word2.substr(1),dp);
        }

        int x = 1 + helper(word1,word2.substr(1),dp);
        int y = 1 + helper(word1.substr(1),word2,dp);
        int z = 1 + helper(word1.substr(1),word2.substr(1),dp);


        dp[m][n] = min(x,min(y,z));
        return dp[m][n];
    }

    int minDistance(string word1, string word2) 
    {
        int dp[501][501];
        for(int i=0;i<501;i++)
        {
            for(int j=0;j<501;j++)
            {
                dp[i][j] = -1;
            }
        }
        return helper(word1,word2,dp);     
    }

};