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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        k = k%len;
        if (k == 0) return head;
        ListNode *left, *right;
		p = head;
		int cnt = 1;
		while (cnt < len-k) {
			cnt++;
			p = p->next;
		}
		left = p;
		right = p->next;
		left->next = NULL;
		
		p = right;
		while (p->next) p = p->next;
		p->next = head;
		head = right;
		return head;
    }
};
