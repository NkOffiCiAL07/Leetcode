class Solution 
{
    public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char, int> m;
        int l=0;
        int mf=0;
        int ans=0;
        
        for(int r=0; r<s.size(); r++)
        {
            m[s[r]]++;
            mf = max(mf, m[s[r]]);
            
            int sz = r-l+1;
            if(sz - mf > k)
            {
                m[s[l]]--;
                l++;
            }
            else
                ans = max(ans, sz);
        }
        
        return ans;
    }
};