class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> in(n);
        vector<int>  adj[n];
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        
        vector<bool> vis(n);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            vis[v] = true;
            for(auto ch : adj[v]){
                in[ch]--;
                if(in[ch] == 0){
                    q.push(ch);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                return false;
            }
        }        
        
        return true;
    }
};