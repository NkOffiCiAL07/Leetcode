class NumArray {
public:
    vector<int> rangeSum;
    NumArray(vector<int>& nums) {
        rangeSum.resize(nums.size()+1, 0);
        for(int j = 0; j < nums.size(); ++j){
            update(j, nums[j]);
        }
    }
    
    void update(int index, int val) {
        int oldVal = sum(index) - sum(index-1);
        for(int i = index+1; i < rangeSum.size(); i = i + (i&(-i)) ){ 
            rangeSum[i] += (val - oldVal);
        }
    }
    int sum(int ind){
        if(ind < 0 ) return 0;
        int res = 0;
        for(int i = ind+1; i > 0; i = i - (i&(-i)) ){
            res += rangeSum[i];
        }
        return res - 101*(ind + 1);
    }
    
    int sumRange(int left, int right) {
        return sum(right) - sum(left-1);
    }
};