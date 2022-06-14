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
    bool isPalindrome(ListNode* head) 
    {
        ListNode *temp = head;
        int sz = 0;
        while(temp) temp = temp->next, sz++;
        
        if(sz == 1)
            return 1;
        
        temp = head;
        int t;
        t = sz & 1 ? sz / 2 + 1 : sz / 2;
        //cout<<t<<endl;
        while(t--) temp = temp->next;
        
        ListNode *left = NULL, *right = NULL;
        
        t = sz/2;
        while(t--)
        {
            right = head->next;
            head->next = left;
            left = head;
            head = right;
        }
        
        while(temp) 
        {
            if(temp->val != left->val)
                return 0;
            
            temp = temp->next;
            left = left->next;
        }
        
        return 1;
    }
};