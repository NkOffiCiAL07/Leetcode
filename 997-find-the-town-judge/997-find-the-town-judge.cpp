class Solution 
{
    public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> adj[n+1], temp[n+1];
        for(auto x : trust)
        {
            adj[x[0]].push_back(x[1]);
            temp[x[1]].push_back(x[0]);
        }
        
        for(int i=1; i<=n; i++)
        {
            if(temp[i].size() == n-1 && adj[i].size() == 0) 
                return i;
        }
        
        return -1;
    }
};