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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0 , i = 1 ; 
        ListNode* curr = head ;
        for (curr = head ; curr ; curr = curr->next) {
            length++ ;
        }
        if (length == n) {
            return head->next ;
        } else {
            for (curr = head , i = 1 ; i < length - n ; i++) {
                curr = curr->next ; 
            }
            curr->next = curr->next->next ;
        }
        return head ;
    }
};