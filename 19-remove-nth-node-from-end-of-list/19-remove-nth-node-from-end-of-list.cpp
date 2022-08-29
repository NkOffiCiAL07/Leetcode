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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* tmp = head;
        int sz = 0;
        while(tmp != NULL)
        {
            sz++;
            tmp = tmp->next;
        }
        
        if(n == sz)
            return head->next;
        
        //cout<<sz<<endl;
        tmp = head;
        int t = sz-n;
        int i = 0;
        while(i <= t-2)
        {
            tmp = tmp->next;
            i++;
        }
        
        if(tmp->next->next)
        {
            tmp->next = tmp->next->next;
        }
        else
        {
            tmp->next = NULL;
        }
        
        return head;
    }
};