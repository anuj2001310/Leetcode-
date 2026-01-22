//This is my Naive Solution on arrays with T.C O(n^3)

class Node {
    int data;
    Node next;

    public Node(int data, Node node) {
        this.data = data;
        this.next = node;
    }
}

class Solution {

    public boolean isSortedList(Node node) {
        Node current_node = node;
        while (current_node != null && current_node.next != null) {
            if (current_node.data > current_node.next.data)
                return false;

            current_node = current_node.next;
        }
        return true;
    }

    public int minimumPairRemoval(int[] nums) {
        Node head = new Node(nums[0], null);
        Node tail = head;

        for (int i = 1; i < nums.length; i++) {
            Node node = new Node(nums[i], null);
            tail.next = node;
            tail = tail.next;
        }

        int count = 0;

        while (!isSortedList(head)) {
            Node best_node = null;
            int min_sum = Integer.MAX_VALUE;
            Node current_head = head;
            while (current_head != null && current_head.next != null) {
                int sum = current_head.data + current_head.next.data;
                if (sum < min_sum) {
                    min_sum = sum;
                    best_node = current_head;
                }
                current_head = current_head.next;
            }
            Node next_list = best_node.next;
            best_node.next = next_list.next;
            best_node.data = min_sum;
            count++;
        }

        return count;
    }
}