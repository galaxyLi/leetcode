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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *help = new ListNode(0);
        ListNode *p = head, *q, *tmp;
        while (p != NULL) {
            q = help;
            while (q->next != NULL) {
                if (q->next->val < p->val) q = q->next;
                else break;
            }
            tmp = p->next;
            p->next = q->next;
            q->next = p;
            p = tmp;
        }
        return help->next;
    }
};
