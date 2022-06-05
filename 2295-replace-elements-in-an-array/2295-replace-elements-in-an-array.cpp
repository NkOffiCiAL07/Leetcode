class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;
        
        for(auto a : operations)
        {
            int y = m[a[0]];
            m.erase(a[0]);
            m[a[1]] = y;
        }
        
        for(auto k : m)
        {
            nums[k.second] = k.first;
        }
        
        return nums;
    }
};