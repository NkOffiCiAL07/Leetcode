class Solution 
{
    public:
    int twoEggDrop(int n) {
        int sum=0, count=0;
        while(n > sum)
        {
            count++;
            sum += count;
        }
        
        return count;
    }
};