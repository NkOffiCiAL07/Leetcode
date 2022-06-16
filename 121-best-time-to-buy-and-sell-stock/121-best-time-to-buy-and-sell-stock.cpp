class Solution 
{
    public:
    int maxProfit(vector<int>& p) 
    {
        int n = p.size();
        int sum = 0, mn = INT_MAX, mx = INT_MIN;
        
        vector<int> dp(n);
        for(int i=n-1; i>=0; i--)
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