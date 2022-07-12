class Solution {
public:
        int func(int start, int end, vector<vector<int>> &dp, vector<int> &cut)
    {
        if(abs(start - end) <= 1)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int min_cost = INT_MAX;
        
        for(int i = start+1; i <= end-1; i++)
        {
            int curr_cost = (cut[end] - cut[start]) + func(start, i, dp, cut)
                            + func(i, end, dp, cut);
            
            if(min_cost > curr_cost || min_cost == INT_MAX)
                min_cost = curr_cost;
        }
        
        return dp[start][end] = min_cost;
    }

    int minCost(int n, vector<int> &cuts) 
    {    
        cuts.push_back(0);
        cuts.push_back(n);
		         
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        
        vector<vector<int>> dp(m , vector<int>(m , -1) );
        
        int ans = func(0, m-1, dp, cuts);
        
        return ans;
    }
};