class Solution 
{
    public:
    int maxArea(vector<int> &a) 
    {
        int i = 0, j = a.size()-1;
        int ans = INT_MIN;
        while(i < j)
        {
            ans = max(ans, min(a[i], a[j]) * (j - i));
            
            if(a[i] < a[j]) i++;
            else j--;
        }
        
        return ans;
    }
};