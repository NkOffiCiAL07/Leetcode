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

class Solution 
{
    public:
    ListNode* removeElements(ListNode *head, int val) 
    {
        ListNode *k = head;
        
        if(head == NULL)
        {
            return head;
        }
        
        while(k != NULL && k->next != NULL)
        {
            if(k->next->val == val)
            {
                k->next = k->next->next;
            }
            
            else
            {
                k = k->next;
            }
        }
        
        if(head->val == val)
        {
            return head->next;
        }
        
        return head;
    }
};