class Solution 
{
    public:
    void solve(vector<vector<char>>& grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || i >= n) return;
        if(j < 0 || j >= m) return;
        
        if(grid[i][j] == '1')
        {
            grid[i][j] = '0';
            solve(grid, i+1, j);
            solve(grid, i-1, j);
            solve(grid, i, j+1);
            solve(grid, i, j-1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    solve(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};