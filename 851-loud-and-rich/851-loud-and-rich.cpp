class Solution {
public:
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
         int n = quiet.size();
        vector<int> indg(n,0), ans(n,INT_MAX);
        vector<vector<int>> g(n);
        queue<int> q;
        
        
        for(int i=0;i<richer.size();i++){
            g[richer[i][0]].push_back(richer[i][1]);
            indg[richer[i][1]]++;
        }
       
       
        for(int i=0;i<n;i++){
            ans[i]=i;
            if(indg[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int i : g[curr]){
                
                if(quiet[ans[i]] > quiet[ans[curr]])
                    ans[i] = ans[curr];
                indg[i]--;
                if(indg[i]==0)
                    q.push(i);
            }
        }
        return ans;
    }
};