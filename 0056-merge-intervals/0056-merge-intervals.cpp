class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ar;
        sort(a.begin(), a.end());
        int n = a.size();
        int i = 0;
        while(i < n){
            int start = a[i][0];
            int end = a[i][1];
            while(i < n){
                if(end >= a[i][0]){
                    end = max(end, a[i][1]);
                }
                else
                    break;
                i++;
            }
            
            ar.push_back({start, end});
        }
        
        return ar;
    }
};