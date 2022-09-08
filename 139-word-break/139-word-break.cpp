class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        map<string, int> m;
        for(auto s : wordDict)
            m[s]++;

        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++)
                if (dp[j] && m[s.substr(j, i-j)]) 
                {
                    dp[i] = true;
                    break;
                }
        
        return dp.back();
    }
};