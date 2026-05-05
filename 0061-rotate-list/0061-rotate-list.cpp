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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *temp1 = head, *temp2 = head, *temp3 = NULL;
        while (temp1 != NULL) {
            temp1 = temp1->next;
            n++;
        }

        if (n < 2 || k % n == 0)
            return head;
        k %= n;
        temp1 = head;
        while (k--)
            temp2 = temp2->next;
        while (temp2->next != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp3 = temp1->next;
        temp1->next = NULL;
        temp2->next = head;
        head = temp3;

        return head;
    }
};