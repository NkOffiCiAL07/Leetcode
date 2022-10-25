class Solution {
public:
    vector<vector<int>> ar;
    void solve(vector<int> &nums, int l, int r){
        if(l == r){
            ar.push_back(nums);
            return;
        }    
        
        for(int i=l; i<=r; i++){
            swap(nums[l], nums[i]);
            solve(nums, l+1, r);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0, nums.size()-1);
        return ar;
    }
};