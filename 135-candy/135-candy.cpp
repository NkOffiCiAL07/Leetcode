class Solution {
public:
    int candy(vector<int> &ratings) 
    {
        int n = ratings.size();
        vector<int> a(n,1), b(n,1);
        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
                a[i] = a[i-1] + 1;
        }
        
        //0,1,2,3,4
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
                b[i] = b[i+1] + 1;
        }
        
    
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += max(a[i], b[i]);
        }
        
        return ans;
    }
};