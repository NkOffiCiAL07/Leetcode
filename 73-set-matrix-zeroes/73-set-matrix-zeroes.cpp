class Solution 
{
    public:
    void setZeroes(vector<vector<int>>& m) 
    {
        vector<int> r, c;
        for(int i=0; i<m.size(); i++)
        {
            for(int j=0; j<m[0].size(); j++)
            {
                if(m[i][j] == 0)
                {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
    
        
        for(auto x : r)
        {
            for(int j=0; j<m[0].size(); j++)
                m[x][j] = 0;
        }
        
        for(auto x : c)
        {
            for(int j=0; j<m.size(); j++)
                m[j][x] = 0;
        }

    }
};