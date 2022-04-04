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
        int length = 0 ; 
        ListNode *cur = head ; 
        while (cur) {
            length++ ; 
            cur = cur->next ;
        }
        int first_position = k - 1 , second_position = length - k ;
        ListNode *a = head , *b = head ;
        while (first_position--) {
            a = a->next ;
        }
        while (second_position--) {
            b = b->next ;
        }
        swap(a->val , b->val) ;
        return head ;
    }
};