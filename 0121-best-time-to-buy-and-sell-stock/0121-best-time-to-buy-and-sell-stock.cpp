class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int ans = 0;
        for(auto v : prices)
        {
            ans = max(ans, v - mn);
            mn = min(mn, v);
        }
        
        return ans;
    }
};