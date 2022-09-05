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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ar;
        queue<Node *> q;
        q.push(root);
        
        if(root == NULL)
            return {};
        
        while(!q.empty())
        {
            vector<int> a;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                Node *tmp = q.front();
                q.pop();
                
                a.push_back(tmp->val);
                vector<Node *> r = tmp->children;
                for(int i=0; i<r.size(); i++)
                {
                    if(r[i])
                        q.push(r[i]);
                }
            }
            
            ar.push_back(a);
        }
        
        return ar;
    }
};