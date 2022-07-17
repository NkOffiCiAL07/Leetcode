class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums[0];
        int idx = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != n)
            {
                n = nums[i];
                swap(nums[idx], nums[i]);
                idx++;
            }
        }
        
        return idx;
    }
};