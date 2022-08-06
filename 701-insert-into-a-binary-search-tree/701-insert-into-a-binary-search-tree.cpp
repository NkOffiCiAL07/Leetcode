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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode *ans = root;
        if(val > root->val)
            ans->right = insertIntoBST(root->right, val);
        else
            ans->left = insertIntoBST(root->left, val);
        
        return ans;
    }
};