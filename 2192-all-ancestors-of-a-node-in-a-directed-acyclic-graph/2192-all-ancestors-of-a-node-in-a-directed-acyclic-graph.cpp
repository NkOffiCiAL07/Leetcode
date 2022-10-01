class Solution {
public:
    vector<int> adj[1001];
    vector<vector<int>> ar;
    
    void dfs(int node, int par, vector<bool> &vis)
    {
        if(!vis[node])
            vis[node] = true;
        
        for(auto ch : adj[node])
        {
            if(!vis[ch])
            {
                ar[ch].push_back(par);
                dfs(ch, par, vis);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ar.resize(n);
        for(auto a : edges)
        {
            adj[a[0]].push_back(a[1]);
        }
        
        for(int i=0; i<n; i++)
        {
            vector<bool> vis(n);
            dfs(i, i, vis);
        }
        
        return ar;
    }
};