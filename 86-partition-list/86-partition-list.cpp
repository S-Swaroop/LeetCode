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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode() , *l2 = new ListNode() , *curr = head , *h1 = l1 , *h2 = l2 ; 
        while (curr) {
            if (curr->val < x) {
                l1->next = curr ; 
                l1 = l1->next ; 
                curr = curr->next ; 
                l1->next = nullptr ; 
            } else {
                l2->next = curr ;
                l2 = l2->next ; 
                curr = curr->next ; 
                l2->next = nullptr ;
            }
        }
        l1->next = h2->next ; 
        return h1->next ;
    }
};