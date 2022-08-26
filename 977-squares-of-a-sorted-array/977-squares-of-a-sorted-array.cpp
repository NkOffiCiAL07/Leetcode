class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int j = nums.size()-1;
        vector<int> result(nums.size(), 0);
        int left, right;
        int k = j;
        for(int i = 0; i <= j; i++){
            left = nums[i]*nums[i];
            right = nums[j]*nums[j];
            if (left>=right){
                result[k--] = left;
            }
            else{
                result[k--] = right;
                j--;
                i--;
            }
        }
        return result;
    }
};
  