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
    ListNode *swapPairs(ListNode *head) {
        if ((head==NULL) || (head->next==NULL)) return head;
        ListNode *p, *q, *pre;
        p = head;
        q = head->next;
        head = q;
        pre = NULL;
        while (q != NULL) {
            p->next = q->next;
            q->next = p;
            if (pre == NULL) pre = p;
            else {
                pre->next = q;
                pre = p;
            }
            p = p->next;
            if (p != NULL) q = p->next;
            else break;
        }
        return head;
    }
};
