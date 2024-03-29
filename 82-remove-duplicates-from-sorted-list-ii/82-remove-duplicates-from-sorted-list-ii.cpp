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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans_head = new ListNode() , *prev = ans_head ; 
        while (head) {
            int count = 1 ; 
            while (head->next && head->next->val == head->val) {
                count++ ; 
                head = head->next ; 
            }
            if (count == 1) {
                prev->next = head ; 
                prev = prev->next ;
            }
            head = head->next ; 
        }
        prev->next = nullptr ;
        return ans_head->next ;
    }
};