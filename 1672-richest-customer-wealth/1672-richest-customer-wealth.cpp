class Solution {
public:
    int maximumWealth(vector<vector<int>>& ar) 
    {
        int mx = 0;
        for(int i=0; i<ar.size(); i++)
        {
            int sum = 0;
            for(int j=0; j<ar[i].size(); j++)
            {
                sum += ar[i][j];
            }
            
            mx = max(mx, sum);
        }
        
        return mx;
    }
};