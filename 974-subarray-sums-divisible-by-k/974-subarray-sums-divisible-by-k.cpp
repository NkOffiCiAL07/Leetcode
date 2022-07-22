class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> m;
        int sum = 0;
        
        int ans = 0;
        m[0] = 1;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            int r = sum % k;
            
            if(r < 0) 
                r += k;
            
            if(m[r] > 0)
                ans += m[r];
            
            m[r]++;
        }
        
        return ans;
    }
};