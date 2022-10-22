class Solution 
{
    public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        set<string> dict (wordDict.begin(), wordDict.end());
        f(0, s, "", ans, dict);
        return ans;
    }

	void f(int ind, string &s, string temp, vector<string>& ans, set<string>& dict) {
        if(ind == s.length()) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        string cur = "";
        for(int i = ind; i < s.length(); i++) {
            cur.push_back(s[i]);
            if(dict.find(cur) != dict.end()) {
                f(i+1, s, temp + cur + " ", ans, dict);
            }
        }
    }
};