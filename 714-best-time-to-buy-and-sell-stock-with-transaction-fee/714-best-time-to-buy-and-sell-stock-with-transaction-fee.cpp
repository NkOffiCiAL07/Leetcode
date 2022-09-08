class Solution {
public:
    int dp[50001][2];
    
    int ff(vector<int>& prices, int f, int i, bool bought) {
        if (i == prices.size()) return 0;
        
        /*
        Decisions :
        1. If bought -> then sell at price[i]
        2. If not bought -> then buy at price[i]
        3. Do nothing (neither buy or sell)
        */
        
        if ( dp[i][bought] != -1) return dp[i][bought];
        int profit = INT_MIN;
        if (bought) {
            // Sell, profit = +prices[i]
            profit = max(profit, ff(prices, f, i + 1, false) + prices[i]);
        }
        else {
            // Buy, profit = -prices[i] -fee
            profit = max(profit, ff(prices, f, i + 1, true) - prices[i] - f);
        }
        profit = max(profit, ff(prices, f, i + 1, bought));
        return dp[i][bought] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof dp);
        return ff(prices, fee, 0, false);
    }
};