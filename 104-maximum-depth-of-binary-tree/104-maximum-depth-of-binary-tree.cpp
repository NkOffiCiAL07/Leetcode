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
    int mx = INT_MIN;
    void solve(TreeNode *root, int ans)
    {
        if(root == NULL)
        {
            mx = max(mx, ans);
            return;
        }
        
        solve(root->left, ans+1);
        solve(root->right, ans+1);
    }
    
    int maxDepth(TreeNode* root) 
    {
        int ans = 0;
        solve(root, ans);
        return mx;
    }
};