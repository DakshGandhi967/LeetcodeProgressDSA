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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummy= new ListNode(0);
        priority_queue< pair<int,ListNode*> ,  vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>> > pq ;
        ListNode* curr=dummy;
        for(auto i : lists){
            if(i) pq.push({i->val,i });
        }
        

        while(!pq.empty()){
            pair<int,ListNode*> x = pq.top();
            pq.pop();

            curr->next = x.second;
            x.second=x.second->next;
            if(x.second) pq.push({x.second->val,x.second});
            curr=curr->next;
        }


        return dummy->next;
    }
};