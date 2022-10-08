class Solution 
{
    public:
    int threeSumClosest(vector<int> &nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        int answer = INT_MAX;
        for (int i = 0; i < size - 1; i++)
        {
            int start = i + 1;
            int end = size - 1;
            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                int diff = target - sum;
                if (abs(diff) < abs(answer))
                {
                    answer = diff;
                }
                else
                {
                    if (sum < target)
                    {
                        start += 1;
                    }
                    else
                    {
                        end -= 1;
                    }
                }
            }
        }
        
        return target - answer;
    }
};