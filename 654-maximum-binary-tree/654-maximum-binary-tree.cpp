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
    TreeNode* solve(vector<int> &a, int l, int r, map<int, int> &m)
    {
        if(l > r)
            return nullptr;
        
        int mx = INT_MIN;
        for(int i=l; i<=r; i++)
            mx = max(mx, a[i]);
        
        TreeNode *root = new TreeNode(mx);
        
        root->left = solve(a, l, m[mx]-1, m);
        root->right = solve(a, m[mx]+1, r, m);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;
        
        return solve(nums, 0, nums.size()-1, m);
    }
};