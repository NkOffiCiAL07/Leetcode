class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> s;
        int ans = 0;
        for(int i = 0; i <= v.size(); i++)
        {
            while(!s.empty() && (i==v.size() || v[s.top()]>v[i]))
            {
                int cur = s.top();
                s.pop();
                int width = s.empty() ? i : i-s.top() - 1;
                ans = max(ans, width * v[cur]);
            }
            
            s.push(i);
        }
        
        return ans;
    }
};