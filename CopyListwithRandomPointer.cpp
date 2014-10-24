/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (head == NULL) return NULL;
        RandomListNode *p, *q, *ans;
        p = head;
        while (p != NULL) {
            RandomListNode *tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        p = head;
        ans = q = p->next;
        while (p != NULL) {
            if (p->random) q->random = p->random->next;
            else q->random = NULL;
            p = q->next;
            if (p) q = p->next;
        }
        p = head;
        q = p->next;
        while (p != NULL) {
            p->next = q->next;
            p = p->next;
            if (p) {
                q->next = p->next;
                q = q->next;
            }
        }
        return ans;
    }
};
