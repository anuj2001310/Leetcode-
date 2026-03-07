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
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;

class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        vi a(1e5 + 1, 0);
        for (; head; head = head->next)
            a[head->val]++;
        ListNode* prev = nullptr;
        
        for (int i = 0; i < size(a); ++i) {
            if (a[i] == 0)
                continue;
            //cout<<a[i]<<" ";
            ListNode* curr = new ListNode(a[i]);
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
};