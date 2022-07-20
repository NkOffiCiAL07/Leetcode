class Solution 
{
    public:
    bool validPalindrome(string s, int l, int r, int cnt)
    {
        if(cnt > 1)
            return 0;
        
        while(l < r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
            }
            else
                return validPalindrome(s, l, r - 1, cnt + 1) || validPalindrome(s, l+1, r, cnt + 1);
        }
        
        return 1;
    }
    
    bool validPalindrome(string s) 
    {
        int lo = 0, hi = s.size() - 1;
        return validPalindrome(s, lo, hi, 0);
    }
    
    
};