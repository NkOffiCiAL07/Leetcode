class Solution 
{
    public:
    bool isSubstring(string &s, vector<int> &mp)
    {
        vector<int> tmp(26, 0);
        for(auto c: s) 
            tmp[c-'a']++;
        
        for(int i = 0; i < 26; ++i)
        {
            if(tmp[i] < mp[i]) 
                return false;
        }
        
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string> ans;
        vector<int> mp(26, 0);
        for(auto w : words2)
        {
            vector<int> tmp(26, 0);
            for(auto c: w) 
                tmp[c-'a']++;
            
            for(int i = 0; i < 26; ++i)
            {
                if(mp[i] < tmp[i]) 
                    mp[i] = tmp[i];
            }
        }
        
        for(auto w: words1)
        {
            if(isSubstring(w, mp)) 
                ans.push_back(w);
        }
        
        return ans;
    }
};