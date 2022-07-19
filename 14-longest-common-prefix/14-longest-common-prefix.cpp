class Solution 
{
    public:
    string solve(string &a, string &b)
    {
        string s;
        for(int i=0; i<min(a.size(), b.size()); i++)
        {
            if(a[i] == b[i])
                s += a[i];
            else break;
        }
        
        return s;
    }
    
    string longestCommonPrefix(vector<string>& str) 
    {
        while(1)
        {
            vector<string> s;
            if(str.size() % 2 == 0)
            {
                for(int i=0; i<str.size()-1; i+=2)
                {
                    string st = solve(str[i], str[i+1]);
                    s.push_back(st);
                }
                str = s;
            }
            else
            {
                for(int i=0; i<str.size(); i+=2)
                {
                    if(i+1<str.size())
                    {
                        string st = solve(str[i], str[i+1]);
                        s.push_back(st);
                    }
                    else
                    {
                        s.push_back(str[i]);
                    }
                }
                
                str = s;
            }
            
            //cout<<str[0]<<" ";
            if(str.size() == 1)
                return str[0];
        }
    }
};