class Solution 
{
    public:
    vector<string> ar;
    void solve(string s, int k, int o = 0, int c = 0)
    {
        if(o == c && c == k)
        {
            ar.push_back(s);
            return;
        }
        
        if(c > k || o > k || c > o)
            return;
        
        if(s.size() > 2 * k)
            return;
        
        if(o < k)
            solve(s + '(', k, o+1, c); 
        
        if(c < o)
            solve(s + ')', k, o, c+1); 
    } 
    
    vector<string> generateParenthesis(int n) 
    {
        solve("", n);
        return ar;
    }
};