class Solution {
public:
    int arrangeCoins(int n) {
        
        long long l = 0, r = n;
        while(l <= r)
        {
            long long m = (l + r) / 2;
            if(m * (m + 1) / 2 <= n)
            {
                l = m + 1;
            }
            else
                r = m - 1;
        }
        
        return l - 1;
    }
};