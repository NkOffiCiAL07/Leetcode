class Solution 
{
    public:
    int maxarea(vector<int> &v)
    {
        stack<int> s;
        int ans = 0;
        for(int i = 0; i <= v.size(); i++)
        {
            while(!s.empty() && (i==v.size() || v[s.top()]>v[i]))
            {
                int cur = s.top();
                s.pop();
                int width = s.empty() ? i : i-s.top() - 1;
                ans = max(ans, width * v[cur]);
            }
            
            s.push(i);
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> curr(n, 0);
        
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')     
                    curr[j]++;
                else    
                    curr[j] = 0;
            }
            
            int area = maxarea(curr);
            ans = max(ans, area);
        }
        
        return ans;
    }
};