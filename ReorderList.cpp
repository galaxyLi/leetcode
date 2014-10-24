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
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        stack<ListNode *> stk;
        ListNode *p, *q;
        p = head;
        while (p != NULL) {
            stk.push(p);
            p = p->next;
        }
        p = head;
        while (true) {
            q = stk.top();
            stk.pop();
            if (p==q || p->next==q) break;
            stk.top()->next = NULL;
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
    }
};
