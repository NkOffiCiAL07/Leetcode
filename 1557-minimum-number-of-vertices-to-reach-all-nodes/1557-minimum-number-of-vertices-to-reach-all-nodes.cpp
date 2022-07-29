class Solution 
{
    public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        set<int> s;
        for(auto a : edges)
        {
            s.insert(a[1]);
        }
        
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            if(s.find(i) == s.end())
            {
                v.push_back(i);
            }
        }
        
        return v;
    }
};