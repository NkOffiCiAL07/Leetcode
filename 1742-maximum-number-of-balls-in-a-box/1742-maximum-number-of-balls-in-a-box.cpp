class Solution {
public:
    int countBalls(int l, int h) {
        map<int, int> m;
        for(int i=l; i<=h; i++)
        {
            int sum = 0;
            string s = to_string(i);
            for(int j=0; j<s.size(); j++)
                sum += s[j]-'0';
            
            m[sum]++;
        }
        
        int ans = INT_MIN;
        for(auto k : m)
            ans = max(k.second, ans);
        
        return ans;
    }
};