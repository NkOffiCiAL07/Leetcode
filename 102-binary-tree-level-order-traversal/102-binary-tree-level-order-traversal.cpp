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

class Solution 
{
    public:
    vector<vector<int>> levelOrder(TreeNode *root) 
    {
        vector<vector<int>> ar;
        if(root == NULL)
            return ar;
        
        queue<TreeNode*> q;    
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> a;
            for(int i=0; i<sz; i++)
            {
                root = q.front(); q.pop();
                a.push_back(root->val);
                
                if(root->left) q.push(root->left);
                
                if(root->right) q.push(root->right);
            }
            
            ar.push_back(a);
        }
        
        return ar;
    }
};