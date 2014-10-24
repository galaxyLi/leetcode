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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return NULL;
        ListNode *first = new ListNode(0);
        first->next = head;
        ListNode *l, *r;
        l = first;
        r = head;
        while (r != NULL) {
            r = r->next;
			n--;
			if (!n) break;
        }
        if (n) return head;
        while (r != NULL) {
            l = l->next;
            r = r->next;
        }
        l->next = l->next->next;
        return first->next;
    }
};
