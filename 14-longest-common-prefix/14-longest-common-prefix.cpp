class Solution 
{
    public:
    bool cmp(string &a, string &b)
    {
        return a.size()<b.size();
    }
    
    string longestCommonPrefix(vector<string> &strs) 
    {
        sort(strs.begin(), strs.end());
        string str;
        int mx = -1;
        for(int i=(int)strs[0].size(); i>0; i--)
        {
            bool b = 1;
            for(int j=1; j<(int)strs.size(); j++)
            {
                if(strs[0].substr(0, i) != strs[j].substr(0, i))
                {
                    b = 0;
                    break;
                }
            }
            
            if(b && i > mx)
            {
                str = strs[0].substr(0, i);
                mx = i;
            }
        }
        
        return str;
    }
};