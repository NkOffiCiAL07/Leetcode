class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        for(auto k : m) q.push({k.second, k.first});
        
        vector<int> a;
        while(!q.empty() && k--)
        {
            a.push_back(q.top().second);
            q.pop();
        }
        
        return a;
    }
};