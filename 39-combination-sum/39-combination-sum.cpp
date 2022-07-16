class Solution 
{
    public:
    vector<vector<int>> ans;
    void solve(vector<int> &a, vector<int> v, int j, int tar)
    {
        if(tar == 0)
        {
            ans.push_back(v);
            return;
        }
        
        if(tar < 0)
            return;
        
        for(int i=j; i<a.size(); i++)
        {
            v.push_back(a[i]);
            solve(a, v, i, tar - a[i]);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        solve(candidates, {}, 0, target);
        return ans;
    }
};