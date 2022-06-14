class Solution 
{
    public:
    int get_index(vector<int>& nums, int start, int end, int &target)
    {
        if(start > end) return -1;
        int mid = start + (end - start) / 2;
        if(target == nums[mid]) 
            return mid;
        else if(target < nums[mid]) 
            return get_index(nums, start, mid - 1, target);
        return get_index(nums, mid + 1, end, target);           
    }
    
    int search(vector<int> &nums, int target) 
    {
        return get_index(nums, 0, nums.size() - 1, target);
    }
};