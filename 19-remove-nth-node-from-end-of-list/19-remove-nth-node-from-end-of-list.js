/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    var slow = head , fast = head ;
    while (fast && n > 0) {
        fast = fast.next ; 
        n = n - 1 ;
    }
    var prev = null ;
    while (fast) {
        fast = fast.next ; 
        prev = slow ; 
        slow = slow.next ;
    }
    if (!prev) {
        return head.next ;
    } else {
        prev.next = slow.next ;
        return head ;
    }
};