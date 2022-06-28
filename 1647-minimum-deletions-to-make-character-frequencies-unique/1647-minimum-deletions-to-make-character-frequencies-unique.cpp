bool cmp(pair<char, int> &a, pair<char, int> &b)
{
    return a.second > b.second;
}
    

class Solution 
{
    public:
    int minDeletions(string s) 
    {
        map<char, int> m;
        for(int i=0; i<s.size(); i++)
            m[s[i]]++;
        
        vector<pair<char, int>> p;
        for(auto k : m)
            p.push_back({k.first, k.second});
        
        sort(p.begin(), p.end(), cmp);
        int ans = 0, tmp = p[0].second-1;
        
        for(int i=1; i<p.size(); i++)
        {
            if(tmp < p[i].second)
            {
                ans += p[i].second - tmp;
                if(tmp > 0) tmp--;
            }
            else
                tmp = p[i].second - 1;
        }
        return ans;
    }
};