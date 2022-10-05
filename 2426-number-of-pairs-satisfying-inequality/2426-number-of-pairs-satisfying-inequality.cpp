struct node {
    int val;
    node* left;
    node* right;
    
    node(){
        left = right = NULL;
        val = 0;
    }
};

class Trie {
    int LIM = 30;
public:
    Trie() {
        root = new node();
    }
    
    node *root;
    void insert(int val) {
        node *ptr = root;
        
        for(int i=LIM;i>=0;i--)
        {
            ptr->val++;
            if(val&(1<<i))
            {
                if(ptr->right==NULL)
                    ptr->right = new node();
                ptr = ptr->right;                
            }
            else
            {
                if(ptr->left==NULL)
                    ptr->left = new node();
                ptr = ptr->left;  
            }
        }
        ptr->val++;
    }
    
    int getans(int num) {
        node *ptr = root;
        int ans = 0;
        
        for(int i=LIM;i>=0;i--)
        {
            if(ptr == NULL)
                return ans;
            if(num & (1<<i))
            {
                ans = ans + (ptr->left ? ptr->left->val : 0);
                ptr = ptr->right;
            }
            else {
                ptr = ptr->left;
            }
            //cout<<" ";
        }
        //cout<<"hh";
        if(ptr)
            ans+=ptr->val;
        return ans;
    }
};
class Solution {
public:
    int offset = 1e5;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        Trie tr;
        
        int mini = 0;
        
        vector<long long> vals;
        for(int i=0;i<nums1.size();i++) {
            nums1[i] -= nums2[i];
            mini = min(mini, nums1[i]+diff);
        }
        
        for(int i=0;i<nums1.size();i++) {
              long long val = 1LL*nums1[i] - mini + offset;
            vals.push_back(val);
        }
          
        
        long long res = 0;
        
        for(int i=0;i<nums1.size();i++) {
            int ct = tr.getans(vals[i] + diff);
            tr.insert(vals[i]);
            res = res + ct;
        }
        return res;
    }
    
    
};