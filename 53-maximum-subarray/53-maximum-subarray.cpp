class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local = INT_MIN, global = 0;
        for(int i=0; i<nums.size(); i++)
        {
            global += nums[i];
            if(local < global)
                local = global;
            
            if(global < 0) 
                global = 0;
        }
        
        return local;
    }
};