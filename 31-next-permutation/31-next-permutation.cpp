class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = -1;
        int x = 0;
        for(int i=nums.size()-1; i>=1; i--)
        {
            //bool flag = 0;
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i] > nums[j] && j > l)
                {
                    l = j;
                    x = i;
                }
            }
            
            //if(flag) break;
        }
        
        if(l != -1)
        swap(nums[x], nums[l]);
        //cout << l << endl;
        sort(nums.begin()+l+1, nums.end());
    }
};