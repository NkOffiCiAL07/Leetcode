class Solution {
public:
    bool dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> m;
        for(auto str : wordDict)
            m[str]++;
        
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j] && m[s.substr(j, i-j)]){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};