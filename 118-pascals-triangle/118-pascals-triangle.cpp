class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1)
        {
            return {{1}};
        }
        
        if(n == 2)
        {
            return {{1}, {1, 1}};
        }
        
        vector<vector<int>> v;
        v.push_back({1});
        v.push_back({1, 1});

        for(int i=2; i<n; i++)
        {
            vector<int> a(i+1);
            a[0] = 1;
            a[i] = 1;
            for(int j=1; j<v.size(); j++)
            {
                a[j] = v[i-1][j-1] + v[i-1][j];
            }
            
            v.push_back(a);
            //cout << "Hi\n";
        }
        
        return v;
    }
};