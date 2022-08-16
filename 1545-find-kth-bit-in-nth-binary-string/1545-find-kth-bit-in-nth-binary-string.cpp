class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1; i<n; i++)
        {
            string k = s;
            for(int i=0; i<k.size(); i++)
            {
                k[i] = ((k[i]-'0') ^ 1) + '0';
            }
            
            reverse(k.begin(), k.end());
            s = s + '1' +  k;
        }
        
        return s[k-1];
    }
};