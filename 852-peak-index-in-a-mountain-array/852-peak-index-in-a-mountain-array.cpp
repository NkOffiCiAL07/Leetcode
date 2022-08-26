class Solution 
{
    public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l = 0, r = arr.size()-1;
        while(l <= r)
        {
            int m = (l + r) / 2;
            if((m + 1 < arr.size()) && (arr[m + 1] > arr[m]))
            {
                l = m + 1;
            }
            else 
                r = m - 1;
        }
        
        return l;
    }
};