/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        Map<Integer, Integer> map = new TreeMap<>();
        while (head != null) {
            map.put(head.val, map.getOrDefault(head.val, 0) + 1);
            head = head.next;
        }
        ListNode prev = new ListNode();
        head = prev;
        for (Map.Entry<Integer, Integer> mapElement : map.entrySet()) {
            int key = mapElement.getKey();
            int val = mapElement.getValue();

            if (val >= 2)
                continue;
            
            ListNode temp = new ListNode(key);
            prev.next = temp;
            prev = temp;
        }
        return head.next;
    }
}