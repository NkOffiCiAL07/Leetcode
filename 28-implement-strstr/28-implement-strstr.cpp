class Solution 
{
    public:
    vector<int> Z_function(string &s)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i=1; i<n; i++)
        {
            if(i <= r)
                z[i] = min(r-i+1, z[i-l]);
            
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            
            if(i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    
    int strStr(string s, string a) 
    {
        s = a + s;
        vector<int> z = Z_function(s);
        for(int i=a.size(); i<s.size(); i++)
        {
            if(z[i] >= a.size())
                return (i - a.size());
        }
        
        return -1;
    }
};