class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        
        map<char, int> m1, m2;
        for(auto ch : s1)
            m1[ch]++;
    
        int k = s1.size();
        for(int i=0; i<k; i++)
            m2[s2[i]]++;
        
        if(m1 == m2)
            return true;
        
        for(int i=k; i<s2.size(); i++)
        {
            m2[s2[i-k]]--;
            m2[s2[i]]++;
            
            if(m2[s2[i-k]] == 0)
                m2.erase(s2[i-k]);
            
            if(m1 == m2)
                return true;
        }
        
        return false;
    }
};