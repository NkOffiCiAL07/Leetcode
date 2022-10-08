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

struct cmp
{
    bool operator()(ListNode* &a, ListNode* &b)
    {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(ListNode *t : lists)
            if(t) pq.push(t);
            
        ListNode *ans = new ListNode(0);
        ListNode* temp = ans;
        while(pq.size() > 0)
        {
            ListNode* p = pq.top();
            pq.pop();
            temp->next = new ListNode(p->val);
            temp = temp->next;
            if(p->next != NULL) 
                pq.push(p->next);
        }

        return ans->next;
    }
};