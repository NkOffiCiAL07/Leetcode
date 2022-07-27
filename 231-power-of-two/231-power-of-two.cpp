class Solution 
{
    public:
    bool isPowerOfTwo(int n) 
    {
        if(n == INT_MIN)
            return 0;
        
        return n && (!(n & (n-1)));    
    }
};