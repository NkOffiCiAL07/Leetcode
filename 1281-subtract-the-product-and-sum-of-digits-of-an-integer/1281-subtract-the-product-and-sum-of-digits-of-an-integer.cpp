class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int mul = 1;
        int sum = 0;
        for(int i=0; i<s.size(); i++)
        {
            mul *= (s[i]-'0');
            sum += (s[i]-'0');
        }
        
        return mul-sum;
    }
};