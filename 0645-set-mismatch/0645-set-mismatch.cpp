class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ar(n+1);
        for(auto v : nums){
            ar[v]++;
        }
        
        int t = 0, tq = 0;
        for(int i=1; i<=n; i++){
            if(ar[i] == 2){
                t = i;
            }
            
            if(ar[i] == 0){
                tq = i;
            }
        }
        
        return {t, tq};
    }
};