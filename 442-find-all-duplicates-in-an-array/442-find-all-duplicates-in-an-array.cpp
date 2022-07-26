class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        int temp[1000000] = {0};
        vector<int> count;
        
        for(int i=0;i<nums.size();i++)
        {
            temp[nums[i]]++; 
            if(temp[nums[i]] > 1)
            {
                count.push_back(nums[i]);
            }
        }
        
        return count;
    }
};