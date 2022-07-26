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
    vector<string> ans;
    void path(TreeNode *root,string s)
    {
        if(!root->left && !root->right)
        {
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        
        s += to_string(root->val) + "->";
        if(root->right) path(root->right, s);
        if(root->left) path(root->left, s);
    }
    
    public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        path(root, "");
        return ans;
    }
};