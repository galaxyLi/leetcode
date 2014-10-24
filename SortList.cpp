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
    ListNode *f(ListNode *p, int len) {
		if (len == 1) {
			p->next = NULL;
			return p;
		} else {
			int i = 0;
			ListNode *q = p;
			while (q) {
				i++;
				q = q->next;
				if (i == len/2) break;
			}
			ListNode *left = f(p, i);
			ListNode *right = f(q, len-i);
			ListNode *helphead = new ListNode(0);
			ListNode *help = helphead;
			while (left && right) {
				if (left->val < right->val) {
					help->next = left;
					left = left->next;
					help = help->next;
				} else {
					help->next = right;
					right = right->next;
					help = help->next;
				}
			}
			while (left) {
				help->next = left;
				left = left->next;
				help = help->next;
			}
			while (right) {
				help->next = right;
				right = right->next;
				help = help->next;
			}
			return helphead->next;
		}
	}

    ListNode *sortList(ListNode *head) {
        if (head == NULL) return NULL;
		ListNode *res, *p = head;
		int len = 0;
		while (p) {
			len++;
			p = p->next;
		}
		res = f(head, len);
		return res;
    }
};
