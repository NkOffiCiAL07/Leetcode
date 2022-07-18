class Solution {
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        um[0] = 1;
        int curr = 0;
        int ans = 0;
        for(auto it: nums)
        {    
            curr += it;
            int rem = curr-k;
            if(um.find(rem) != um.end())
            {
                ans += um[rem];
            }
            um[curr]++;
        }
        return ans;
    }
};