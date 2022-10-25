class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        ans = max(ans, min(height[i], height[j]) * (j - i));
        while(i < j)
        {
            if(height[i] < height[j]) i++;
            else j--;
            
            ans = max(ans, min(height[i], height[j]) * (j - i));
        }
        
        return ans;
    }
};