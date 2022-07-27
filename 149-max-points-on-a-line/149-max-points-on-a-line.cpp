class Solution 
{
    public:
    int maxPoints(vector<vector<int>> &points) 
    {
        int result = 0;
        for(int i = 0; i < points.size(); i++)
        {
            unordered_map <long double, int> h;
            int same = 1;
            int ans = 0;
            for (int j = i+1; j<points.size(); j++)
            {
                if (points[i][0] == points[j][0] and points[i][1] == points[j][1])
                    same++;
                else if (points[i][0] == points[j][0])
                    h[INT_MAX]++;
                else
                {
                    long double m = (long double)(points[i][1] - points[j][1])/(long double)(points[i][0] - points[j][0]); 
                    h[m]++;
                }
            }
            
             for(auto k : h)
             {
                ans = max(ans, k.second);
             }
            
             ans += same;
             result = max(result, ans);
        }
        
        return result;
    }
};