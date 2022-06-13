/*
 *
 * Definition for a binary tree node.
 * struct TreeNode 
    {
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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});      
        
        while(!q.empty())
        {
            int cnt = q.size();
            int start = q.front().second;
            int end = q.back().second;
            
            res = max(res, end-start+1);
            
            for(int i=0; i<cnt; ++i)
            {
                long long idx = q.front().second - start;
                
                if(q.front().first->left != NULL)
                    q.push({q.front().first->left, 2*idx+1});
                
                if(q.front().first->right != NULL)
                    q.push({q.front().first->right, 2*idx+2});
                
                q.pop();
            }
        }
        
        return res;
    }
};