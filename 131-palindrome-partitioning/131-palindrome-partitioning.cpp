class Solution 
{
    public:
    bool pal(string s)
    {
        int n = s.size();
        for(int i=0; i<n/2; i++)
        {
            if(s[i] != s[n-1-i])
                return 0;
        }
        
        return 1;
    }
    
    vector<vector<string>> a;
    void solve(string &s, vector<string> ar, int id)
    {
        if(id >= s.size())
        {
            a.push_back(ar);
        }
        
        for(int end = id; end<s.size(); end++)
        {
            if(pal(s.substr(id, end-id+1)))
            {
                ar.push_back(s.substr(id, end-id+1));
                solve(s, ar, end+1);
                ar.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        solve(s, {}, 0);
        return a;
    }
};