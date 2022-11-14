class Solution {
public:
    int shortestSubarray(vector<int>& A, int k) {
        deque<int>q;
        int res = INT_MAX;
        vector<long long> nums;
        for(auto i : A) 
            nums.push_back(i);
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i > 0) {
                nums[i] += nums[i-1];
            }
            
            if(nums[i] >= k){
                res = min(res, i+1);
            }
            
            while(!q.empty() && nums[i]-nums[q.front()] >= k){
                    res = min(res, i-q.front());
                    q.pop_front();
            }
            
            while(!q.empty() && nums[i] <= nums[q.back()]){
                    q.pop_back();
            }
            
            q.push_back(i);
        }
        
        return res == INT_MAX ? -1 : res;
    }

};