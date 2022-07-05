class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        
        if(nums.size() == 1)
            return 1;
        
        sort(nums.begin(), nums.end());
        int mx = INT_MIN, cnt = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                cnt++;
            }
            else if(nums[i] != nums[i-1])
            {
                
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
        
        return mx;
    }
};