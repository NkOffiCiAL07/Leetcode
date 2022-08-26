class Solution {
public:
    void rotate(vector<int> &nums, int k) 
    {
        vector<int> a;
        int t = k % nums.size();
        int l = nums.size() - t;
        
        for(int i=l; i<nums.size(); i++)
        {
            a.push_back(nums[i]);
        }
        
        for(int i=0; i<l; i++)
        {
            a.push_back(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = a[i];
        }
    }
};