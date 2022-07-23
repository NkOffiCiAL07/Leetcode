class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> a;
        for(int i=0; i<(1<<n); i++)
        {
            vector<int> t;
            for(int j=0; j<n; j++)
            {
                if(i & (1 << j))
                {
                    t.push_back(nums[j]);
                }
            }
            sort(t.begin(), t.end());
            a.insert(t);
        }
        
        vector<vector<int>> ar(a.begin(), a.end());
        
        return ar;
    }
};