class Solution 
{
public:
    vector<vector<int>> ar;
    void solve(vector<int> &a, vector<int> b, int j)
    {
        ar.push_back(b);
        for(int i=j; i<a.size(); i++)
        {
            if(i > j && a[i] == a[i-1])
                continue;
            
            b.push_back(a[i]);
            solve(a, b, i+1);
            b.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> a;
        solve(nums, a, 0);
        return ar;
    }
};