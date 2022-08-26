class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m, k;
        for(int i=0; i<s.size(); i++)
        {
            if(m.find(s[i]) == m.end() && k.find(t[i]) == k.end())
                m[s[i]] = t[i],
                k[t[i]] = s[i];
            else
            {
                if(m[s[i]] != t[i])
                    return false;
            }
        }
        
        return true;
    }
};