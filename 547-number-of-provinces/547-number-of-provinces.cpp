class Solution 
{
    public:
    vector<int> adj[201];
    bool vis[201];
    void dfs(int u)
    {
        vis[u] = 1;
        for(auto child : adj[u])
        {
            if(!vis[child])
                dfs(child);
        }
    }
    
    int findCircleNum(vector<vector<int>>& edge) {
        for(int i=0; i<edge.size(); i++)
        {
            for(int j=0; j<edge[i].size(); j++)
            {
                if(edge[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int cnt = 0;
        for(int i=0; i<edge.size(); i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }
        
        return cnt;
    }
};