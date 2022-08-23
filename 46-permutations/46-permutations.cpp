class Solution 
{
    public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int l)
    {
        if(l == nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
  
        for(int i=l; i<=nums.size()-1; i++)
        {
            swap(nums[l], nums[i]);
            solve(nums, l+1);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        solve(nums, 0);
        return ans;
    }
};