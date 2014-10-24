/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *p, *pre;
        pre = head;
        p = head->next;
        while (p) {
            if (p->val == pre->val) {
                pre->next = p->next;
                delete p;
                p = pre->next;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
