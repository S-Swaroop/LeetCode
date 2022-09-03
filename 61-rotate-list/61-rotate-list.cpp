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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tail = head , *curr = head ; 
        if (!head)  return head ;
        int n = 1 ;
        while (tail->next) {
            tail = tail->next ;
            n++ ;
        }
        tail->next = head ;
        k %= n ;
        k = n - k ; 
        while (k--) {
            tail = tail->next ;
        }
        ListNode *new_head = tail->next ; 
        tail->next = nullptr ; 
        return new_head ;
    }
};