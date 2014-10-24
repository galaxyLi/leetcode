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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL) return NULL;
        stack<ListNode *> stk;
		int cnt;
		ListNode *left, *p, *q, *right;
		left = right = NULL;
		p = head;
		cnt = 1;
		while (p != NULL) {
			if (cnt < m) left = p;
			else if (m <= cnt && cnt <= n) stk.push(p);
			else {
				right = p;
				break;
			}
			cnt++;
			p = p->next;
		}
		p = stk.top();
		stk.pop();
		if (left != NULL) left->next = p;
		else head = p;

		while (!stk.empty()) {
			q = stk.top();
			stk.pop();
			p->next = q;
			p = q;
		}
		p->next = right;
		return head;
    }
};
