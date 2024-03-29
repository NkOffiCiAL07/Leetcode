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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ar;
        stack<TreeNode*> stk;
        while(1)
        {
            if(root != NULL)
            {
                stk.push(root);
                root = root->left;
            }
            else
            {
                if(stk.empty())
                    break;
                
                root = stk.top();
                ar.push_back(root->val);
                stk.pop();
                
                root = root->right;
            }
        }
        
        return ar;
    }
};