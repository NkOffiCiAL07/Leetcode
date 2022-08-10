class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[2001];
        vector<int> in(2001);
        vector<bool> vis(2001);
        
        for(auto v : p){
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        
        vector<int> ar;
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(in[i] == 0)
                q.push(i);
                //ar.push_back(i);
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            vis[curr] = 1;
            q.pop();
            ar.push_back(curr);
            for(auto ch : adj[curr])
            {
                in[ch]--;
                if(in[ch] == 0)
                    q.push(ch);
            }
        }
        
        vector<int> a;
        return (ar.size() == n) ? ar : a;
    }
};