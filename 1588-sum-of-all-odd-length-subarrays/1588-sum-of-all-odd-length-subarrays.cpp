class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
         int n=arr.size(),sum=0;
        for(int i=0;i<n;i++){
            int s=0,x=0;
            for(int j=i;j<n;j++){
                s+=arr[j];
                if(x%2==0){
                    sum+=s;
                }
                x++;
            }
        }
       return sum;
    }
};