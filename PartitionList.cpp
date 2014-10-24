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
    ListNode *partition(ListNode *head, int x) {
    	if (head == NULL) return NULL;
    	ListNode *left = new ListNode(0);
    	ListNode *right = new ListNode(0);
        ListNode *p, *l, *r;
        p = head;
        l = left;
        r = right;
        while (p != NULL) {
        	if (p->val < x) {
        		l->next = p;
        		p = p->next;
        		l = l->next;
        	} else {
        		r->next = p;
        		p = p->next;
        		r = r->next;
        	}
        }
        r->next = NULL;  //一定要记得把末尾位置赋值NULL,否则会成为循环列表.
        l->next = right->next;
        return left->next;
    }
};
