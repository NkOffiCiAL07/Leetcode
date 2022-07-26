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
    vector<string> s;
    void solve(TreeNode *root, string str)
    {
        if(root == NULL)
        {
            //s.push_back(str);
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            str += to_string(root->val);
            s.push_back(str);
            return;            
        }
        
        str += to_string(root->val) + "->";
        solve(root->left, str);
        solve(root->right, str);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return s;
    }
};