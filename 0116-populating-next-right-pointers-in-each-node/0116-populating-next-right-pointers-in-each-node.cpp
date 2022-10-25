/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution 
{
    public:
    void solve(Node* root){
        if(root == NULL)
            return;
        
        if(root->left && root->right){
            root->left->next = root->right;
        }
        
        if(root->right && root->next && root->next->left){
            root->right->next = root->next->left;
        }
        
        solve(root->left);
        solve(root->right);
    }
    
    Node* connect(Node* root) {
        solve(root);
        return root;        
    }
};