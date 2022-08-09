class Solution {
public:
    vector<int> adj[200001];
    bool vis[200001];
    void dfs(int u)
    {
        vis[u] = true;
        for(auto child : adj[u])
        {
            if(!vis[child])
                dfs(child);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        dfs(source);
        return vis[destination];
    }
};