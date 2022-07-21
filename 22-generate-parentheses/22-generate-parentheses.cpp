class Solution 
{
    public:
    vector<string> ar;
    void solve(string s, int k, int n)
    {
        if(k == 0)
        {
            if(n == 0)
                ar.push_back(s);
            return;
        }
        
        if(n < 0 || n > k)
            return;
        
        solve(s + '(', k-1, n+1);
        solve(s + ')', k-1, n-1);
    } 
    
    vector<string> generateParenthesis(int n) 
    {
        solve("", 2 * n, 0);
        return ar;
    }
};