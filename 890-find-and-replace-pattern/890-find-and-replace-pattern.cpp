class Solution 
{
    public:
    string encodeString(string s) 
    {
        unordered_map<char, int> m;
        string res = "";
        int i = 0;
        
        for(auto it : s) 
        {
            if(m.find(it) == m.end())
                m[it] = i++;
            
            res += to_string(m[it]);
        }
        
        return res;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        string encodedString = encodeString(pattern); 
        vector<string> v;

        for(auto it : words) 
        {
            string s = encodeString(it);
            if(s == encodedString) 
            {
                v.push_back(it);
            }
        }
        return v;
    }
};