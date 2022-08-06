class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long ans = 0;
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i] > nums[i+1])
            {
                if(nums[i] % nums[i+1] == 0)
                {
                    ans += (nums[i] / nums[i+1]) - 1,
                    nums[i] = nums[i+1];
                }
                else
                {
				    int temp = ((nums[i]  + nums[i+1] - 1) / nums[i+1]);
                    ans += temp - 1;
                    nums[i] = nums[i] / temp;
                }
            }
        }
        
        return ans;
    }
};