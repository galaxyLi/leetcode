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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *p, *pre, *ppre, *new_head;
        pre = head;
        p = head->next;
        new_head = NULL;
        bool flag = true;
        while (p) {
            if (pre->val == p->val) {
                p = p->next;
                flag = false;
            } else {
                if (flag) { new_head = pre; break; }
                pre = p;
                p = p->next;
                flag = true;
            }
        }
        if (flag) new_head = pre;
        
        if (new_head == NULL) return NULL;
        ppre = new_head;
        pre = new_head->next;
        if (pre) p = pre->next;
        else return new_head;
        
        int pre_val = pre->val;
        int cnt = 1;
        while (p) {
        	if (p->val == pre_val) {
        		cnt++;
        		p = p->next;
        	} else {
        		if (cnt == 1) {
        			ppre->next = pre;
        			ppre = pre;
        			pre = p;
        			pre_val = pre->val;
        			p = p->next;
        		} else {
        			pre = p;
        			pre_val = pre->val;
        			cnt = 1;
        			p = p->next;
        		}
        	}
        }
        if (cnt == 1) ppre->next = pre;
        else ppre->next = NULL;
        return new_head;
    }
};
