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
        ListNode *slow = head , *fast = head ; 
        while (fast && n--) {
            fast = fast->next ; 
        }
        ListNode *prev = nullptr ;
        while (fast) {
            fast = fast->next ; 
            prev = slow ;
            slow = slow->next ;
        }
        if (!prev) {
            return head->next ;
        } else {
            prev->next = slow->next ;
            return head ;
        }
    }
};