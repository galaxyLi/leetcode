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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1==NULL && l2==NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head = new ListNode(0);
        ListNode *p, *q, *ret;
        p = l1;
        q = l2;
        ret = head;
        int t = 0;
        while (p && q) {
            int sum = p->val + q->val + t;
            ListNode *tmp = new ListNode(sum%10);
            ret->next = tmp;
            t = sum/10;
            p = p->next;
            q = q->next;
            ret = ret->next;
        }
        while (p) {
            int sum = p->val + t;
            ListNode *tmp = new ListNode(sum%10);
            ret->next = tmp;
            t = sum/10;
            p = p->next;
            ret = ret->next;
        }
        while (q) {
            int sum = q->val + t;
            ListNode *tmp = new ListNode(sum%10);
            ret->next = tmp;
            t = sum/10;
            q = q->next;
            ret = ret->next;
        }
        if (t) {
            ListNode *tmp = new ListNode(t);
            ret->next = tmp;
        }
        return head->next;
    }
};
