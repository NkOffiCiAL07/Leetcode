class Solution {
public:
    unordered_map<string, bool> mp, m;
    bool solve(string s){
        int n = s.size();
        if(mp.find(s) != mp.end())
            return mp[s];
        
        if(m.find(s) != m.end())
            return m[s];
        
        string word;
        for(int i=0; i<n; i++){
            word += s[i];
            if((m.find(word) != m.end()) && solve(s.substr(i+1))){
                return mp[word] = true;
            }
        }
        
        return mp[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict){
        for(auto str : wordDict)
            m[str] = true;
        
        return solve(s);
    }
};