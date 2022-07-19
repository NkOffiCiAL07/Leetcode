class Solution 
{
    public:
    int findPairs(vector<int>& nums, int k) 
    {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        int cnt = 0;
        int ans = 0;
        for(auto r : m)
        {
            if(m.find(k + r.first) != m.end())
                ans++;
            
            cnt += min(1, r.second / 2);
        }
        
        return k != 0 ? ans : cnt;
    }
};