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
        ListNode *cur = head , *a = nullptr , *b = nullptr ;
        while (cur) {   
            k-- ;
            a = a == nullptr ? nullptr : a->next ;
            if (k == 0) {
                b = cur ;
                a = head ;
            }
            cur = cur->next ;
        }
        swap(a->val , b->val) ;
        return head ;
    }
};