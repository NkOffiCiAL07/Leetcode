class Solution {
public:
    string reverseWords(string s) {
        vector<string> ar;
        
        string sr;
        for(int i=0; i<s.size(); i++)
        {
            if(i>0 && s[i] == ' ' && s[i-1] != ' ')
            {
                ar.push_back(sr);
                sr = "";
            }
            else if(s[i] != ' ')
                sr += s[i];
        }
        
        if(sr != "")
            ar.push_back(sr);
        
        reverse(ar.begin(), ar.end());
        string str;
        str += ar[0];
        for(int i=1; i<ar.size(); i++)
            str += ' ' + ar[i];
        
        return str;
    }
};