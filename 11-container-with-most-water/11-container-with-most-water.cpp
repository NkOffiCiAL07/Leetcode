class Solution 
{
    public:
    int maxArea(vector<int>& h) 
    {
        int mx = INT_MIN;
        int i = 0, j = h.size()-1;
        while(i < j)
        {
            int area = (j - i) * min(h[i], h[j]);
            mx = max(mx, area);
            if(h[i] < h[j]) i++;
            else j--;
        }
        
        return mx;
    }
};