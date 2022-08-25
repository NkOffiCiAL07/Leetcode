class Solution {
public:
    double average(vector<int>& ar) {
        double ans = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i=0; i<ar.size(); i++)
        {
            ans += ar[i];
            mx = max(mx, ar[i]);
            mn = min(mn, ar[i]);
        }
        
        return (double) (ans - mx - mn) / (ar.size() - 2);
    }
};