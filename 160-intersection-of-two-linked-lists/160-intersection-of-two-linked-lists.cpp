/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *head1 = headA, *head2 = headB;
        int sz1 = 0, sz2 = 0;
        while(head1)
        {
            head1 = head1->next;
            sz1++;
        }
        
        while(head2)
        {
            head2 = head2->next;
            sz2++;
        }
        
        head1 = headA, head2 = headB;
        if(sz1 > sz2)
        {
            int t = sz1 - sz2;
            while(t--)
            {
                head1 = head1->next;
            }
            
            while(head1)
            {
                if(head1 == head2)
                    return head1;
                
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        else
        {
            int t = sz2 - sz1;
            while(t--)
            {
                head2 = head2->next;
            }
            
            while(head1)
            {
                if(head1 == head2)
                    return head1;
                
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        
        return NULL;
    }
};