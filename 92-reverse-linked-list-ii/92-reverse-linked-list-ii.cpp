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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *left_prev = nullptr , *right_next = nullptr ;
        int position = 1 ; 
        for (ListNode *curr = head ; curr ; curr = curr->next) {
            if (position == left - 1) {
                left_prev = curr ; 
            } else if (position == right) {
                right_next = curr->next ;
                curr->next = nullptr ;
            }
            position++ ; 
        }
        if (left == 1) {
            head = reverse(left == 1 ? head : left_prev->next) ;
        } else {
            left_prev->next = reverse(left_prev->next) ;
        }
        ListNode *curr = head ; 
        while (curr->next) {
            curr = curr->next ; 
        }
        curr->next = right_next ; 
        return head ; 
    }
private: 
    ListNode* reverse(ListNode* head , ListNode* next = nullptr , ListNode* previous = nullptr) {
        // ListNode *current = head , *next = nullptr , *previous = nullptr ;
        // while (current) {
        //     next = current->next ; 
        //     current->next = previous ; 
        //     previous = current ; 
        //     current = next ;
        // }
        // return previous ;
        return head ? reverse(head->next , (head->next = previous , next) , head) : previous ; 
    }
};