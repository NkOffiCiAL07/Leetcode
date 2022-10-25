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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        
        ListNode *t = head, *h = head;
        int sz = 0;
        while(t->next){
            t = t->next;
            sz++;
        }
        
        if(sz == 0 || (k % (sz + 1) == 0)){
            return head;
        }
        
        sz = sz - (k % (sz + 1));
        for(int i=0; i<sz; i++){
            h = h->next;   
        }
        
        ListNode *ans = h->next;
        h->next = NULL;
        t->next = head;
        return ans;
    }
};