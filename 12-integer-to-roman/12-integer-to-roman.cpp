class Solution 
{
    public:
    string intToRoman(int num) 
    {
        string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int val[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int i = 12;
        string str;
        while(num > 0) 
        {
            int div = num / val[i];
            num %= val[i];
            while(div--) 
            {
                str += roman[i];
            }
            
            i--;
        }
        
        return str;
    }
};