class Solution {
public:
    vector<int> adj[20];
    vector<vector<int>> ar;
    void dfs(int u, int n, vector<int> a)
    {
        if(u == n)
        {
            a.push_back(n);
            ar.push_back(a);
            return;
        }
        
        a.push_back(u);
        for(auto child : adj[u])
        {
            dfs(child, n, a);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        for(int i=0; i<graph.size(); i++)
        {
            for(auto v : graph[i])
            {
                adj[i].push_back(v);
            }
        }
        
        dfs(0, graph.size()-1, {});
        return ar;
    }
};