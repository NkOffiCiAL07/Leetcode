class Solution {
public:
    int jump(vector<int>& nums) {
        
        int step = 0, mstep = 0, ans = 0;
        for(int i = 0; i<nums.size()-1; i++)
        {
            if(i + nums[i] > mstep)
            {
               mstep = i + nums[i];
            }
            
            if(i == step)
            {
                ans++;
                step = mstep;
            }
        }
        
        return ans;
    }
};