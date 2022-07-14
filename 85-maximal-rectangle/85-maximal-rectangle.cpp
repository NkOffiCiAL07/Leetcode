class Solution 
{
    public:
    int maxarea(vector<int>& h) 
    {
        stack<int> s;
        vector<int> p, n;
        for(int i=0; i<h.size(); i++)
        {
            if(s.empty())
                p.push_back(-1);
            else
            {
                while((!s.empty()) && (h[s.top()] >= h[i]))
                    s.pop();
                
                if(s.empty())
                    p.push_back(-1);
                else
                    p.push_back(s.top());
            }
            
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i=h.size()-1; i>=0; i--)
        {
            if(s.empty())
                n.push_back(h.size());
            else
            {
                while((!s.empty()) && (h[s.top()] >= h[i]))
                    s.pop();
                
                if(s.empty())
                    n.push_back(h.size());
                else
                    n.push_back(s.top());
            }
            
            s.push(i);
        }
        
        reverse(n.begin(), n.end());

        int mx = INT_MIN;
        for(int i=0; i<h.size(); i++)
        {
            mx = max(mx, (n[i]-p[i]-1)*h[i]);
        }
        
        return mx;
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