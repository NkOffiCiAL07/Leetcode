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
    bool operator() (const ListNode* a, const ListNode* b) const{
        return a->val < b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*, MyComp> pq;
        for(auto list : lists){
            if(list){
                pq.insert(list);
            }
        }
        
        ListNode *res = new ListNode(0);
        ListNode *ans = res;
        while(pq.size()){
            auto it = pq.begin();
            ListNode *temp = (*it);
            pq.erase(it);
            
            ans->next = temp;
            ans = ans->next;
            
            if(temp->next){
                pq.insert(temp->next);
            }
        }
        
        return res->next;
    }
};