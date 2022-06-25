class Solution 
{
    public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l = 0, r = arr.size();
        int ans = 0;
        while(l < r)
        {
            int m = (l + r) / 2;
            if((m + 1 < arr.size()) && (arr[m + 1] > arr[m]))
            {
                ans = m;
                l = m + 1;
            }
            else 
                r = m;
        }
        
        return ans + 1;
    }
};