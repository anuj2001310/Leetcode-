/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int pairSum(ListNode head) {
        ListNode fast = head;
        ListNode show = head;
        ListNode prev = null;
        while (fast != null) {
            fast = fast.next.next;
            ListNode tmp = show;
            show = show.next;
            tmp.next = prev;
            prev = tmp;
        }
        int max = 0;
        while (show != null && prev != null) {
            max = Math.max(max, show.val + prev.val);
            show = show.next;
            prev = prev.next;
        }
        return max;
    }
}