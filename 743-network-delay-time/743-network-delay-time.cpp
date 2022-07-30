class Solution 
{
    public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) 
    {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<t.size();i++){
            adj[t[i][0]].push_back({t[i][1] , t[i][2]});
        }
        vector<int>dist(n+1,1e5);
        queue<int>q;
        q.push(k);
        dist[k]=0;
        while(q.size()){
          int node=q.front();
          q.pop();
          for(auto it : adj[node]){
               int v=it.first;
               int wt=it.second;
               if(dist[node]+wt < dist[v]){
                 dist[v]=dist[node]+wt;
                 q.push(v);
               }
          }
    }
        
       int ans = 0;
       for(int i=1; i<n+1; i++)
       {
          if(dist[i] == 1e5)
            return -1;
         else
           ans = max(ans, dist[i]);
       }
        
      return ans;
    }
};