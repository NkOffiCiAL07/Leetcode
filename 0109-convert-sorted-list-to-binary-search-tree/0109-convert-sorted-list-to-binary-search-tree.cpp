/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *solve(vector<int> &ar, int l, int r){
        if(l > r){
            return NULL;
        }    
        int m = (l + r) / 2;
        TreeNode *root = new TreeNode(ar[m]);
        root->left = solve(ar, l, m-1);
        root->right = solve(ar, m+1, r);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ar;
        while(head){
            ar.push_back(head->val);
            head = head->next;
        }
        return solve(ar, 0, ar.size()-1);
    }
};