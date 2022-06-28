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
    bool solve(TreeNode *root, TreeNode *t)
    {
        if(root == t)
            return 1;
        
        if(!root || !t)
            return 0;
        
        if(root->val != t->val)
            return 0;
        
        return solve(root->left, t->left) && solve(root->right, t->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* sr) 
    {
        if(root == NULL)
            return false;
        
        if(solve(root, sr))
            return true;
        
        return isSubtree(root->left, sr) || isSubtree(root->right, sr);
    }
};