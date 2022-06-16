class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        bool dp[n][n];
        
        int start, len;
        for(int g=0; g<n; g++)
        {
            for(int i=0, j=g; j < n; i++, j++)
            {
                if(g == 0)
                    dp[i][j] = 1;
                else if(g == 1)
                {
                    if(s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    if(dp[i+1][j-1] == 1 && s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                
                if(dp[i][j])
                {
                    start = i;
                    len = g+1;
                }
            }
        }
        
        return s.substr(start, len);
    }
};