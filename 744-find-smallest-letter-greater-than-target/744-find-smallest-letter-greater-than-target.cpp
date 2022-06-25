class Solution 
{
    public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int start = -1, end = letters.size();
        while(start+1 < end)
        {
            long long mid = (start + end) / 2;
            if(letters[mid] > target)
            {
                end = mid;
            } 
            else 
            {
                start = mid;
            }
        }
        
        if(end != letters.size())
            return letters[end];
        else 
            return letters.front();
    }
};