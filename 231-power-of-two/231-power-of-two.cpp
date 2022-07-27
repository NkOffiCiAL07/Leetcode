class Solution 
{
    public:
    bool isPowerOfTwo(int n) 
    {
        return n && (!((long)n & ((long)n-1)));    
    }
};