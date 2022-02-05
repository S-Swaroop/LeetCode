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
        priority_queue<pair<int , ListNode*>> q ;
        for (auto &curr : lists) {
            if (curr)   q.push({-1 * curr->val , curr}) ;
        }
        ListNode* ans = new ListNode() ;
        ListNode* curr = ans ; 
        while (!q.empty()) {
            auto node = q.top() ; 
            q.pop() ; 
            curr->next = new ListNode(-1 * node.first) ; 
            curr = curr->next ; 
            if (node.second->next) {
                q.push({-1 * node.second->next->val , node.second->next}) ;
            }
        }
        return ans->next ;
    }
};