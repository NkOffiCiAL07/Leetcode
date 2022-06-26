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
    bool solve(TreeNode *root, int val)
    {   
        if(root == NULL && val != 0)
            return false;
        
        if(root && root->left == NULL && root->right == NULL && !val)
            return true;
        
        if(root && root->left == NULL && root->right == NULL && val!=0)
            return false;
        
        bool l = 0, r = 0;
        if(root->left)
            l = solve(root->left, val - root->left->val);
        
        if(root->right)
            r = solve(root->right, val - root->right->val);
        
        return l || r;
    }
    
    bool hasPathSum(TreeNode* root, int ts) 
    {
        
        if(root == NULL)
            return false;
        
        return solve(root, ts - root->val);
    }
};