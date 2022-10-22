class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ar;
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i=0; i<n;){
            int start = a[i][0];
            int end = a[i][1];
            int j = i + 1;
            while(j < n){
                if(end >= a[j][0]){
                    end = max(end, a[j][1]);
                }
                else
                    break;
                j++;
            }
            
            ar.push_back({start, end});
            i = j;
        }
        
        return ar;
    }
};