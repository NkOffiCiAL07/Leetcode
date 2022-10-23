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

struct MyComp{
    bool operator() (ListNode* &a, ListNode* &b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MyComp> pq;
        for(auto list : lists){
            if(list){
                pq.push(list);
            }
        }
        
        ListNode *res = new ListNode(0);
        ListNode *ans = res;
        while(!pq.empty()){
            ListNode *temp = pq.top();
            pq.pop();
            
            ans->next = temp;
            ans = ans->next;
            
            if(temp->next){
                pq.push(temp->next);
            }
        }
        
        return res->next;
    }
};