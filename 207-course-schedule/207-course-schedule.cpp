class Solution 
{
    public:
    vector<int> adj[100001];    
    void kahn(int n, vector<int> &in, vector<bool> &vis)
    {
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            vis[curr] = 1;
            q.pop();
            
            for(auto child : adj[curr])
            {
                in[child]--;
                if(in[child] == 0)
                    q.push(child);
            }
        }
    }
    
    bool canFinish(int nc, vector<vector<int>>& p) 
    {
        vector<int> in(100001);
        vector<bool> vis(100001);
        
        for(auto a : p)
        {
            adj[a[1]].push_back(a[0]);
            in[a[0]]++;
        }
        
        kahn(nc, in, vis);
        
        
        for(int i=0; i<nc; i++)
        {
            if(!vis[i])
                return false;
        }
        
        return true;
    }
};