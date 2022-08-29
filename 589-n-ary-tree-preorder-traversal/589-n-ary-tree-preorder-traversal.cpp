/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ar;
    void solve(Node* root)
    {
        if(root == NULL)
            return;
        
        ar.push_back(root->val);
        
        vector<Node*> ch = root->children;
        for(int i=0; i<ch.size(); i++)
            solve(ch[i]);
        
    }
    
    vector<int> preorder(Node* root) {
        solve(root);
        return ar;
    }
};