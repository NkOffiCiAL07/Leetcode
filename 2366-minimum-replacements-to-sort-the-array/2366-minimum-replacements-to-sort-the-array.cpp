class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long ans = 0, sum = 0;
        for(int i=nums.size()-2; i>=0; i--)
        {
            sum += nums[i];
            if(nums[i] > nums[i+1])
            {
                if(nums[i] % nums[i+1] == 0)
                {
                    ans += (nums[i] / nums[i+1]) - 1,
                    nums[i] = nums[i+1];
                }
                else
                {
                    ans += ((nums[i] + nums[i+1] - 1) / nums[i+1]) - 1;
                    nums[i] = nums[i] / ((nums[i]  + nums[i+1] - 1) / nums[i+1]);
                }
            }
        }
        
        return ans;
    }
};