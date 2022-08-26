class Solution 
{
    public:
    int dirx[4] = {-1,1,0,0};
    int diry[4] = {0,0,-1,1};
    int n, m;
    
    void dfs(int x, int y, vector<vector<int>>& grid)
    {
        grid[x][y] = 1;
        for(int i = 0; i < 4; i++)
        {
            int nxtx = x + dirx[i];
            int nxty = y + diry[i];
            if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m || grid[nxtx][nxty])
                continue;
            dfs(nxtx, nxty, grid);
        }
        return;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                    continue;
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    dfs(i,j,grid);
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                    continue;
                dfs(i,j,grid);
                ans++;
            }
        }
        return ans;
    }
};