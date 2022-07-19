class Solution 
{
    public:
    void moveZeroes(vector<int>& nums) 
    {
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == 0)
            {
                int j = i + 1;
                while(j < nums.size())
                {
                    if(nums[j] != 0)
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
                    j++;
                }
             }
        }
    }
};