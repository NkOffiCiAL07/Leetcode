class Solution 
{
    public:
    bool isSubsequence(string &s, string &t, int n, int m)
    {
        if(n > m)
            return false;
        
        if(n == 0)
            return true; 
        
        return isSubsequence(s, t, n - (s[n-1] == t[m-1]), m-1);
    }
    
    bool isSubsequence(string s, string t) 
    {
        return isSubsequence(s, t, s.size(), t.size());
    }
};