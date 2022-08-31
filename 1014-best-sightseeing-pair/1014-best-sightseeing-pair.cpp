class Solution 
{
    public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int N = A.size();
        int ans = 0;
        int max_after = A[N-1]-N+1;
        for(int i=N-2; i>=0; i--)
        {
            max_after = max(max_after, A[i+1]-i-1);
            ans = max(ans, A[i]+i+max_after);
        }
        
        return ans;
    }
};