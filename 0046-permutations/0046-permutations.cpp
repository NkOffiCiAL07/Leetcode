class Solution {
public:
    vector<vector<int>> ar;
    void solve(vector<int> &nums, int l){
        int n = nums.size()-1;
        if(l == n){
            ar.push_back(nums);
            return;
        }    
        
        for(int i=l; i<=n; i++){
            swap(nums[l], nums[i]);
            solve(nums, l+1);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ar;
    }
};