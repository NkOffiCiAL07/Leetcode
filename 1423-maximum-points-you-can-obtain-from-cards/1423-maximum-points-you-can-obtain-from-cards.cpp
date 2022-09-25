class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int ans=0;
        for(int i=0; i<k; i++)
            ans += cardPoints[i];
        
        int total = ans, j = cardPoints.size();
        for(int i = k-1; i >= 0; i--, j--)
        {
            total = total - cardPoints[i] + cardPoints[j-1];
            ans = max(ans, total);
        }
        
        return ans;
    }
};