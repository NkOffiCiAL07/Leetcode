class Solution {
public:
    int maximumProduct(vector<int>& a) 
    {
        sort(a.begin(), a.end());
        int x=1, y=1,  z=1;
        
        int n = a.size();
        x = a[0]*a[1]*a[n-1];
        y = a[n-1]*a[n-2]*a[n-3];
        
        return max(x, y);
    }
};