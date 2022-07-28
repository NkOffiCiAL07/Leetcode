class Solution 
{
    public:
    vector<int> adj[200001];
    bool vis[200001];
    void dfs(int u, int v)
    {
        vis[u] = 1;
        for(int child : adj[u])
        {
            if(!vis[child])
                dfs(child, v);
        }
    }
    
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) 
    {
        for(auto v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        dfs(source, destination);
        
        return vis[destination];
    }
};