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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *a = nullptr , *b = nullptr ;
        for (ListNode *cur = head ; cur != NULL ; cur = cur->next) {   
            a = a == nullptr ? nullptr : a->next ;
            if (--k == 0) {
                b = cur ;
                a = head ;
            }
        }
        swap(a->val , b->val) ;
        return head ;
    }
};