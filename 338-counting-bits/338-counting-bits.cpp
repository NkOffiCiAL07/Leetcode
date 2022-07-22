class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> a;
        for(int i=0; i<=n; i++)
        {
            int cnt = 0;
            for(int j=0; j<32; j++)
            {
                if(i & (1<<j))
                    cnt++;
            }
            
            a.push_back(cnt);
        }
        
        return a;
    }
};