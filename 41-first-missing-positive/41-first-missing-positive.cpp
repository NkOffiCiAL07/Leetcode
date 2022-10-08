class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, bool> vis;
        for(int num : nums)
            vis[num] = true;
        
        for(int i=1; i<=100001; i++)
            if(!vis[i])
                return i;
        
        return 0;
    }
};