class Solution 
{
    public:
    int mx = INT_MIN;
    string s;
    void solve(vector<string>& arr, int idx, int mask)
    {
        if(idx == arr.size()) {
            mx = max(mx, (int) s.size());
            return;
        }
        
        solve(arr, idx + 1, mask);
        for(auto ch : arr[idx]){
            if(mask >> (ch - 'a') & 1)
                return;
            mask |= 1 << (ch - 'a');    
        }
        int sz = s.size();
        s += arr[idx];
        solve(arr, idx + 1, mask);
        s.erase(s.begin() + sz, s.end());
    }
    
    int maxLength(vector<string>& arr) {
        int mask = 0;
        solve(arr, 0, mask);
        return mx;
    }
};