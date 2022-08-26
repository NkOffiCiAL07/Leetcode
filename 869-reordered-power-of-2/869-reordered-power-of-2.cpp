class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        do
        {
            //check power of two.
            if(s[0] != '0')
            {
                int v = stoi(s);

                if(!(v & (v-1)))
                    return true;                
            }
            
        }while(next_permutation(s.begin(), s.end()));
        
        return false;
    }
};