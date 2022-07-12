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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head ; 
        for (int i = 0 ; i < k ; i++) {
            if (!curr) {
                return head ; 
            }
            curr = curr->next ;
        }
        ListNode *new_head = reverse(head , curr) ;
        head->next = reverseKGroup(curr , k) ; 
        return new_head ;
    }
private: 
    ListNode* reverse (ListNode *head , ListNode *tail) {
        ListNode *prev = tail ; 
        while (head != tail) {
            ListNode *temp = head->next ;
            head->next = prev ; 
            prev = head ; 
            head = temp ;
        }
        return prev ;
    }
};