class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        map<int, int> m;
        for(auto a : edges)
        {
            int u = a[0];
            int v = a[1];
            m[u]++;
            m[v]++;
            
            if(m[u] == n)
                return u;
            
            if(m[v] == n)
                return v;
        }
        
        return 0;
    }
};