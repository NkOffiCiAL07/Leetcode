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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};

        vector<int> ar;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;
            for(int i=0; i<sz; i++)
            {
                root = q.front(); q.pop();
                
                tmp.push_back(root->val);
                if(root->left)
                    q.push(root->left);

                if(root->right)
                    q.push(root->right);               
            }
            
            int n = tmp.size();
            ar.push_back(tmp[n-1]);
        }

        return ar;
    }
};