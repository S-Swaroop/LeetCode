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
    void reorderList(ListNode* head) {
        ListNode *head1 = head , *head2 = splitAndGetNewHead(head) ;
        head2 = reverseList(head2) ;
        while (head1 && head2) {
            ListNode *temp = head1->next ;
            head1->next = head2 ; 
            head1 = head1->next ; 
            head2 = temp ;
        }
    }
private: 
    ListNode* splitAndGetNewHead (ListNode *head) {
        ListNode *turtle = head , *hare = head->next ; 
        while (hare && hare->next) {
            turtle = turtle->next ; 
            hare = hare->next->next ; 
        }
        ListNode *newHead = turtle->next ; 
        turtle->next = nullptr ;
        return newHead ;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head , *next = nullptr , *previous = nullptr ;
        while (current) {
            next = current->next ; 
            current->next = previous ; 
            previous = current ; 
            current = next ;
        }
        return previous ; 
    }
    void print (ListNode *head) {
        while (head) {
            cout << head->val << "->" ;
            head = head->next ;
        }
        cout << endl ;
    }
};