class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++)
            q.push(i);
        
        if(k == 1)
            return n;
        
        while(q.size() > 1)
        {
            int t = k-1;
            while(t--)
            {
                int r = q.front();
                q.pop();
                q.push(r);
            }
            
            q.pop();
        }
        
        return q.front();
    }
};