class Solution 
{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        vector<int> ans;
        int dir = 0;
        int i=0, j=0;
        while((i <= n) && (j <= m))
        {
            if(dir == 0)
            {
                for(int k = j; k <= m; k++)
                {
                    ans.push_back(matrix[i][k]);
                }
                
                i++;
                dir++;
            }
            
            else if(dir == 1)
            {
                for(int k = i; k <= n; k++)
                {
                    ans.push_back(matrix[k][m]);
                }
                
                m--;
                dir++;                
            }
            
            else if(dir == 2)
            {
                for(int k = m; k >= j; k--)
                {
                    ans.push_back(matrix[n][k]);
                }
                
                n--;
                dir++;                
            }
            
            else if(dir == 3)
            {
                for(int k = n; k >= i; k--)
                {
                    ans.push_back(matrix[k][j]);
                }
                
                j++;
                dir = 0;                
            }
            
            
        }
        
        return ans;
    }
};