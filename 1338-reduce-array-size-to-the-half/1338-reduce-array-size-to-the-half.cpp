bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;    
}

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for(int i=0; i<arr.size(); i++)
            m[arr[i]]++;
        
        vector<pair<int, int>> p;
        for(auto k : m)
        {
            p.push_back({k.second, k.first});
        }
        
        int n = arr.size();
        sort(p.begin(), p.end(), cmp);
        int sum = 0;
        for(int i=0; i<p.size(); i++)
        {
            sum += p[i].first;
            if(sum >= n/2)
            {
                return i+1;
            }
        }
        
        return n;
    }
};