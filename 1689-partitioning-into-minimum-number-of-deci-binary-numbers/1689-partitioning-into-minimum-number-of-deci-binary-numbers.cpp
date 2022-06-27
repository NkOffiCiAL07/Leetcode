class Solution {
public:
    int minPartitions(string s) {
        int mx = -10;
        
        for(int i=0; i<s.size(); i++)
        {
            mx = max(mx, s[i]-'0');
        }
        
        return mx;
    }
};