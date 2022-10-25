class Solution {
public:
    vector<vector<int>> ar;
    void solve(vector<int> &v, int tar, vector<int> a, int idx = 0){
        if(tar == 0){
            ar.push_back(a);
            return;
        }
        
        if(tar < 0){
            return;
        }
        
        for(int i=idx; i<v.size(); i++){
            a.push_back(v[i]);
            solve(v, tar-v[i], a, i);
            a.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> t;
        solve(candidates, target, t);
        return ar;
    }
};