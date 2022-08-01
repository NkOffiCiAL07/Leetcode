class Solution 
{
    public:
    int maximumGroups(vector<int>& g) 
    {
        int ans = 0;
        int n = g.size();
        for(int i = 1; i < 1000; i++)
        {
            if(n >= (i * (i + 1) / 2))
                ans = i;
            else
                return ans;
        }
    
        return ans;
    }
};