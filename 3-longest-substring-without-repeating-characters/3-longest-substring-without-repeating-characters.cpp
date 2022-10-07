class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> map(256, -1);

        int left = 0, ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(map[s[i]] != -1)
                left = max(map[s[i]] + 1, left);

            map[s[i]] = i;
            ans = max(ans, i-left+1);
        }

        return ans;
    }
};