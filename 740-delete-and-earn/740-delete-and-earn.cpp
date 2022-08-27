class Solution {
public:
    int deleteAndEarn(vector<int> & nums) 
    {
        int m = -1;
        for(auto x : nums) 
            m = max(m, x);

        vector<int> arr(m+1, 0);
        for(auto x : nums) 
            arr[x] += x;

        vector<int> dp(m+1, 0);
        dp[0] = 0;
        dp[1] = arr[1];

        for(int i=2; i<=m; i++){
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        
        return dp[m];
    }
};