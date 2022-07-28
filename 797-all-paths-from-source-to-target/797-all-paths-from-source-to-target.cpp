class Solution 
{
    public:
    vector<vector<int>> ar;
    vector<int> adj[20];
    void dfs(int u, vector<int> a, int dest)
    {   
        if(dest == u)
        {
            ar.push_back(a);
            return;
        }
        
        for(auto v : adj[u])
        {
            a.push_back(v);
            dfs(v, a, dest);
            a.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0; i<n; i++)
        {
            for(auto v : graph[i])
                adj[i].push_back(v);
        }
        
        dfs(0, {0}, n-1);
        return ar;
    }
};