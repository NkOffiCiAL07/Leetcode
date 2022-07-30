class Solution 
{
    public:
    vector<int> adj[101];
    bool vis[101];
    bool col[101];
    
    bool dfs(int v, bool c, vector<vector<int>>& g)
    {
        vis[v] = 1;
        col[v] = c;
        for(auto ch : g[v])
        {
            if(!vis[ch] && !dfs(ch, c^1, g))
                return 0;
                
            else if(col[v] == col[ch])
                return 0; 
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g) 
    {
        for(int i=0; i<g.size(); i++)
        {
            if(!vis[i])
            {
                if(!dfs(i, 0, g))
                    return 0;
            }
        }
        
        return 1;
    }
};