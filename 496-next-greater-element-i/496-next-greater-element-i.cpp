class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
    {
        stack<int> s;
        map<int, int> m;
        for (int n : nums) 
        {
            while (s.size() && s.top() < n) 
            {
                m[s.top()] = n;
                s.pop();
            }
            
            s.push(n);
        }
        
        vector<int> ans;
        for (int n : findNums) 
            ans.push_back(m[n] != 0 ? m[n] : -1);
        
        return ans;
    }
};