class Solution 
{
    public:
    vector<int> adj[200001];
    bool vis[200001];
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) 
    {
        for(auto a : edges)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int v = q.front();
            vis[v] = true;
            q.pop();
            for(auto k : adj[v])
            {
                if(!vis[k])
                    q.push(k);
            }
        }
        
        return vis[d];
    }
};