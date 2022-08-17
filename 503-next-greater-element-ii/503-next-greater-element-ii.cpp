class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> t = nums;
        vector<int> ans(2 * nums.size());
        stack<int> s;
        
        for(int i=0; i<t.size(); i++)
            nums.push_back(t[i]);
        
        for(int i=nums.size()-1; i>=0; i--)
        {

            while(!s.empty() && s.top() <= nums[i])
                s.pop();
                
            if(s.empty()) 
                ans[i] = -1;
            else
                ans[i] = s.top();
            
            s.push(nums[i]);
        }
        
        vector<int> r(ans.begin(), ans.begin()+t.size());
        return r;
    }
};