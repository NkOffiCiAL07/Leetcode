class Solution 
{
    public:
    vector<vector<int>> ans;
    void solve(vector<int>& a, vector<int> v, int j, int tar)
    {
        if(tar < 0) 
            return;
        
        if(tar == 0)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i=j; i<a.size(); i++)
        {
            if(i>j && a[i] == a[i-1])
                continue;
            
            v.push_back(a[i]);
            solve(a, v, i+1, tar - a[i]);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int target) 
    {
        sort(a.begin(), a.end());
        solve(a, {}, 0, target);
        
        return ans;
    }
};