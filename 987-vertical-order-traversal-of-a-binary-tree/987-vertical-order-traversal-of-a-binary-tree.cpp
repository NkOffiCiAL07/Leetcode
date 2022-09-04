/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         if(root == NULL)
            return {{}};
        
        map<int, vector<int>> adj;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int sz = q.size();
            vector<pair<int,int>> a;
            for(int i=0; i<sz; i++)
            {
                auto p = q.front(); q.pop();
                int d = p.second;
                TreeNode* node = p.first;
                
                a.push_back({d, node->val});
                if(node->left) q.push({node->left, d-1});

                if(node->right) q.push({node->right, d+1});
            }
            
            sort(a.begin(), a.end());
            for(auto it : a)
                adj[it.first].push_back(it.second);
        }
        
        vector<vector<int>> ar;
        for(auto k : adj)
        {
            ar.push_back(k.second);
        }
        
        return ar;       
    }
};