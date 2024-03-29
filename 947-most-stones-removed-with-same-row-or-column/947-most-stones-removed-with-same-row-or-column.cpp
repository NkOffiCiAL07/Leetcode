class Solution {
    
    public:
    vector<int> parent;         
    int find(int node){                   
        if(node == parent[node]) 
            return node;
        
        return parent[node] = find(parent[node]);
    }
    
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        
        if(x == y) 
            return false;
        
        parent[y] = x;
        return true;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if((stones[i][0]==stones[j][0]) || (stones[i][1]==stones[j][1])){
                    if(merge(i, j)) 
                        count++;
                }
            }
        }
        
        return count;
    }
};