class Solution 
{
    public:
    vector<int> adj[1001];
    bool dfs(int v, vector<bool> &vis, int par = -1)
    {
        if(vis[v])
            return true;
        
        vis[v] = 1;
        
        for(auto child : adj[v])
        {
            if(child != par && dfs(child, vis, v))
                return true;
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        
        int n = edges.size();
        for(auto a : edges)
        {
            vector<bool> vis(n+1);
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
            
            if(dfs(a[0], vis))
            {
                return a;
            }
        }
        
        return {};
    }
    
};