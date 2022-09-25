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
    vector<vector<int>> ans;
    void solve(TreeNode *root, int val, vector<int> tmp)
    {   
        if(root == NULL)
        {
            return;
        }
        
        tmp.push_back(root->val);
        if(root && root->left == NULL && root->right == NULL && val == 0)
        {
            ans.push_back(tmp);
            return;
        }
    
        if(root->left)
        solve(root->left, val - root->left->val, tmp);
        
        if(root->right)
        solve(root->right, val - root->right->val, tmp);
        
        tmp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int ts) 
    {
        if(root == NULL)
            return ans;
        
        vector<int> tmp;
        solve(root, ts - root->val, tmp);
        return ans;
    }
};