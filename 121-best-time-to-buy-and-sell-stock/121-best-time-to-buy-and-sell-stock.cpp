class Solution 
{
    public:
    int maxProfit(vector<int>& p) 
    {
        int n = p.size();
        int sum = 0, mn = INT_MAX, mx = INT_MIN;
        
        vector<int> dp(n);
        dp[n-1] = p[n-1];
        for(int i=n-2; i>=0; i--)
        {
            dp[i] = max(dp[i], p[i]);
            
        }
        
        for(int i=0; i<n; i++)
        {
            mn = min(mn, p[i]);
            mx = max(mx, dp[i] - mn);
        }
        
        return mx;
    }
};