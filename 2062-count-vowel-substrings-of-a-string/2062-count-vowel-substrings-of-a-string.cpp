class Solution 
{
    private:
    inline bool is(char ch) 
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    public:
    int countVowelSubstrings(string word)
    {
        unordered_set<char> set;
        int len = word.length(), count = 0;
        
        for (int i = 0; i < len - 4; i++)
        {
            set.clear();
            for (int j = i; j < len; j++)
            {
                if( is(word[j]) ){
                    set.insert(word[j]);
                }
                else {
                    break;
                }
                if(set.size() == 5){
                    count++;
                }
            }
        }
        return count;
    }
};