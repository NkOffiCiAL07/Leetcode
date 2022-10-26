class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;
            
            if(rem < 0)
                rem += k;
            
            if(m.count(rem)){
                cnt += m[rem];
            }
            
            m[rem]++;
        }
        return cnt;
    }
};