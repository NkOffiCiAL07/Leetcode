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
    int cnt = 0;
    void solve(TreeNode* root, int k)
    {
        if(root == NULL)
            return;
        
        if(root->val >= k) 
        {
            cnt++; 
            k = root->val;
        }

        solve(root->left, k);
        solve(root->right, k);
    }
    
    int goodNodes(TreeNode* root) 
    {
        int k = root->val;
        if(root->left) 
            solve(root->left, k);
        
        if(root->right) 
            solve(root->right, k);
        
        return cnt + 1;
    }
};