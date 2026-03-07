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
    string gameResult(ListNode* head) {
        int odd = 0, even = 0, s = 0;
        vector<int> a;
        for (; head; head = head->next)
            s++, a.push_back(head->val);
        //cout<<s<<endl;
        for (int i = 1; i < s; i += 2) {
            //cout<<a[i - 1] << " "<<a[i]<<", ";
            if (a[i] == a[i - 1])
                continue;
            else if (a[i] > a[i - 1])
                odd++;
            else
                even++;
        }

        return ((odd == even) ? "Tie" : (odd > even ? "Odd" : "Even"));
    }
};