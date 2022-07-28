class Solution 
{
    int x = 0;
    void solve(int &n, int pos, vector<bool>& vis, int& c)
    {
        x++;
        if(pos > n) c++;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i] && ((pos%i == 0) || (i%pos == 0) ))
            {
                vis[i] = true;
                solve(n, pos+1, vis, c);
                vis[i] = false;
            }
        }
    }

    public:
    int countArrangement(int n) 
    {
        vector<bool> vis(n+1, false);
        int c = 0;
        solve(n, 1, vis, c);
        
        cout << x << endl;
        return c;
    }
};