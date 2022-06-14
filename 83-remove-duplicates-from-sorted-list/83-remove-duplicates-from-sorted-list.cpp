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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL)
            return head;
        
        ListNode* ans = new ListNode(head->val), *node;
        node = ans;
        while(head)
        {
            if(ans->val != head->val)
            {
                ans->next = new ListNode(head->val);
                ans = ans->next;
            }
            
            head = head->next;
        }
        
        return node;
    }
};