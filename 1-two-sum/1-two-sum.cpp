class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;
            
        for(int i=0; i<nums.size(); i++)
        {
            int t = m[target - nums[i]];
            
            if((nums[t] + nums[i] == target) && t != i)
            {
                return {i, t};
            }
        }
        
        return {0, 0};
    }
};