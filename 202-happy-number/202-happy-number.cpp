class Solution 
{
    public:
    int count = 0;
    bool isHappy(int n) 
    {
        count++;
        if(count > 1e5)
            return false;
        
        int sum = 0;
        while(n > 0)
        {
            sum += pow(n%10, 2);
            n /= 10;
        }
        
        if(sum == 1)
            return true;
        else return isHappy(sum);
    }
};