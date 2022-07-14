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
    map<int, int> m;
    TreeNode *solve(vector<int> &in, int l, int r, vector<int> &pr, int ll, int rr)
    {
        if(l > r || ll > rr)
            return NULL;
        
        TreeNode *root = new TreeNode(pr[ll]);
        
        int x = m[pr[ll]];
        int n = x - l;
        
        root->left = solve(in, l, x-1, pr, ll + 1, rr + n);
        root->right = solve(in, x+1, r, pr, ll + n + 1, rr);
        return root;

    }
    
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) 
    {
        for(int i=0; i<in.size(); i++)
        {
            m[in[i]] = i;
        }
        
        return solve(in, 0, in.size()-1, pr, 0, pr.size()-1);
    }
};