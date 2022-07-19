class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        if(n == 1)
            return ans;
        
        ans.push_back({1,1});
        
        if(n == 2)
            return ans;
        
        for(int i=3; i<=n; i++)
        {
            vector<int> tmp, v = ans[i-2];
            tmp.push_back(1);
            for(int j=0; j<v.size()-1; j++)
            {
                tmp.push_back(v[j] + v[j+1]);
            }
            
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        
        return ans;
    }
};