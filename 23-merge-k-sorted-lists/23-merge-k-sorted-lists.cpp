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
        if (lists.empty()) {
            return nullptr ;
        }
        for (int step = 1 ; step <= lists.size() ; step *= 2) {
            for (int i = 0 ; i < lists.size() ; i += 2 * step) {
                if (i + step < lists.size())    lists[i] = merge(lists[i] , lists[i + step]) ;
            }
        }
        return lists[0] ;
    }
private: 
    ListNode* merge(ListNode *l1 , ListNode *l2) {
        ListNode *head = new ListNode() ;
        ListNode *curr = head ;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1 ; 
                l1 = l1->next ;
            } else {
                curr->next = l2 ;
                l2 = l2->next ;
            }
            curr = curr->next ; 
        }
        while (l1) {
            curr->next = l1 ; 
            l1 = l1->next ; 
            curr = curr->next ; 
        }
        while (l2) {
            curr->next = l2 ; 
            l2 = l2->next ; 
            curr = curr->next ; 
        }
        return head->next ;
    }
};