class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1, 2,
        // 3, 4
        
        vector<int> ar;
        int n=nums1.size(), m=nums2.size(), i = 0, j = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                ar.push_back(nums1[i]);
                i++;
            }
            else{
                ar.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < n) ar.push_back(nums1[i]), i++;
        while(j < m) ar.push_back(nums2[j]), j++;
        
        int x = n + m;
        if(x & 1){
            return ar[x/2];
        }
        else{
            return (double) (ar[x/2] + ar[x/2-1]) / 2.0;
        }
    }
};