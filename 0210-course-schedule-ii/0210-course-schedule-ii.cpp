class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> in(n);
        vector<int>  adj[n];
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ar;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ar.push_back(v);
            for(auto ch : adj[v]){
                in[ch]--;
                if(in[ch] == 0){
                    q.push(ch);
                }
            }
        }      
        
        vector<int> a;
        return (ar.size() == n) ? ar : a;        
    }
};