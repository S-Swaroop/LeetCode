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
    ListNode* reverseList(ListNode* head , ListNode* next = nullptr , ListNode* previous = nullptr) {
        // ListNode *current = head , *next = nullptr , *previous = nullptr ;
        // while (current) {
        //     next = current->next ; 
        //     current->next = previous ; 
        //     previous = current ; 
        //     current = next ;
        // }
        // return previous ;
        return head ? reverseList(head->next , (head->next = previous , next) , head) : previous ; 
    }
};