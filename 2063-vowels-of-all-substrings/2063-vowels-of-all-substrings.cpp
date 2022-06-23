class Solution{
public:
    long long countVowels(string word)
    {
        long long sum = 0, curr = 0;
        if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')
            curr = 1;
        
        sum += curr;
        
        for(int i = 1; i < word.length(); ++i)
        {
            long long temp = curr;
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            {
                temp += i + 1;
                curr = temp;
            }
            sum += curr;
        }
        return sum;
    }
};