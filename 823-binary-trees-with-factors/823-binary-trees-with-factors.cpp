class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int mod = 1e9 + 7;
        map<int, long long> mp;
        
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]] = 1;
            for(int j=0; j<i; j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    mp[arr[i]] += (mp[arr[j]] * mp[arr[i] / arr[j]]) % mod;
                }
            }
        }
          
        long long ans = 0;
        for(auto it : mp){
             ans= (ans + it.second)  % mod;
        }
        
        return ans;
    }
};