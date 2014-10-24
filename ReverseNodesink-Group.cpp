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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *rhead, *p, *pre, *end;
        int len = 0;
        p = head;
        while (p != NULL) {
            p = p->next;
            len++;
            if (len == k) {
                end = p;
                break;
            }
        }
        if (len == k) {
            pre = reverseKGroup(end, k);
            rhead = NULL;
            p = head;
            while (p != end) {
                ListNode *pnext = p->next;
                if (pnext == end) rhead = p;
                p->next = pre;
                pre = p;
                p = pnext;
            }
        } else return head;
        return rhead;
    }
};
