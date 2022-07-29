class Solution 
{
    public:
    vector<int> adj[1001];
    bool vis[1001];
    void dfs(int v)
    {
        vis[v] = true;
        for(auto ch : adj[v])
        {
            if(!vis[ch])
            {
                dfs(ch);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        for(int i=0; i<rooms.size(); i++)
        {
            for(int j=0; j<rooms[i].size(); j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        memset(vis, 0, sizeof(vis));
        dfs(0);
        for(int i=0; i<rooms.size(); i++)
        {
            if(!vis[i])
                return false;
        }
        
        return true;
    }
    
};