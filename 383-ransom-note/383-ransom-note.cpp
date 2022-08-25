class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m1, m2;
        for(auto ch : ransomNote) m1[ch]++;
        for(auto ch : magazine) m2[ch]++;
        
        for(auto k1 : m1)
        {
            if(k1.second > m2[k1.first])
                return false;
        }
        
        return true;
    }
};