class Solution 
{
    public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        for(int r = 0; (i < n) && (i <= r); i++)
            r = max(i + nums[i], r);
        
        return (i == n);
    }
};