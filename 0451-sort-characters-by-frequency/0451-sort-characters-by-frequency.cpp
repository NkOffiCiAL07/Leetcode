class Solution {
public:
    string frequencySort(string s) { 
       unordered_map<char,int> m;
       for(auto i : s)
            ++m[i];
        
        s = "";
        vector<pair<int, char>> v;
        for(auto i : m) 
            v.push_back({i.second, i.first});
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        for(auto i : v) 
            s += string(i.first, i.second);
        return s;
    }
};